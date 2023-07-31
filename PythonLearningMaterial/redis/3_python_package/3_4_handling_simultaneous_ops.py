"""
Let's introduce a big chunk of code and walk through it afterwards step by step. You can picture buyitem() as being called any time a user clicks on a Buy Now or Purchase button. Its purpose is to confirm the item is in stock and take an action based on that result, all in a safe manner that looks out for race conditions and retries if one is detected.

The critical line occurs at Line 21 with pipe.watch(itemid), which tells Redis to monitor the given itemid for any changes to its value. The program checks the inventory through the call to r.hget(itemid, "quantity"), in Line 22. If the inventory gets touched during this short window between when the user checks the item stock and tries to purchase it, then Redis will return an error, and redis-py will raise a WatchError (Line 30). That is, if any of the hash pointed to by itemid changes after the .hget() call but before the subsequent .hincrby() calls in Lines 20 and 21, then we'll re-run the whole process in another iteration of the while True loop as a result.

This is the “optimistic” part of the locking: rather than letting the client have a time-consuming total lock on the database through the getting and setting operations, we leave it up to Redis to notify the client and user only in the case that calls for a retry of the inventory check.

One key here is in understanding the difference between client-side and server-side operations:

nleft = r.hget(itemid, "quantity")

This Python assignment brings the result of r.hget() client-side. Conversely, methods that you call on pipe effectively buffer all of the commands into one, and then send them to the server in a single request. No data comes back to the client side in the middle of the transactional pipeline. You need to call .execute() (Line 19) to get the sequence of results back all at once. Even though this block contains two commands, it consists of exactly one round-trip operation from client to server and back.

"""
import logging
import redis

logging.basicConfig()


class OutOfStockError(Exception):
    """Raised when PyHats.com is all out of today's hottest hat"""


def buyitem(r: redis.Redis, itemid: int) -> None:
    with r.pipeline() as pipe:
        error_count = 0
        while True:
            try:
                # Get available inventory, watching for changes
                # related to this itemid before the transaction
                pipe.watch(itemid)
                nleft: bytes = r.hget(itemid, "quantity")
                if nleft > b"0":
                    pipe.multi()
                    pipe.hincrby(itemid, "quantity", -1)
                    pipe.hincrby(itemid, "npurchased", 1)
                    pipe.execute()
                    break
                else:
                    # Stop watching the itemid and raise to break out
                    pipe.unwatch()
                    raise OutOfStockError(
                        f"Sorry, {itemid} is out of stock!"
                    )
            except redis.WatchError:
                # Log total num. of errors by this user to buy this item,
                # then try the same process again of WATCH/HGET/MULTI/EXEC
                error_count += 1
                logging.warning(
                    "WatchError #%d: %s; retrying",
                    error_count, itemid
                )
    return None
