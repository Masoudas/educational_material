"""
There must always be a couple of check steps:

    Step 1: Check if the item is in stock, or otherwise raise an exception on the backend.
    Step 2: If it is in stock, then execute the transaction, decrease the quantity field, and increase the npurchased field.
    Step 3: Be alert for any changes that alter the inventory in between the first two steps (a race condition).

Step 1 is relatively straightforward: it consists of an .hget() to check the available quantity.

Step 2 is a little bit more involved. The pair of increase and decrease operations need to be executed atomically: either both should be completed successfully, or neither should be (in the case that at least one fails).

With client-server frameworks, it’s always crucial to pay attention to atomicity and look out for what could go wrong in instances where multiple clients are trying to talk to the server at once. The answer to this in Redis is to use a transaction block, meaning that either both or neither of the commands get through.

In redis-py, Pipeline is a transactional pipeline class by default. This means that, even though the class is actually named for something else (pipelining), it can be used to create a transaction block also.

How is this handled?  This is what our code looks like, in redis terms:

127.0.0.1:6379> MULTI
127.0.0.1:6379> HINCRBY 56854717 quantity -1
127.0.0.1:6379> HINCRBY 56854717 npurchased 1
127.0.0.1:6379> EXEC

MULTI (Line 1) marks the start of the transaction, and EXEC (Line 4) marks the end. Everything in between is executed as one all-or-nothing buffered sequence of commands. This means that it will be impossible to decrement quantity (Line 2) but then have the balancing npurchased increment operation fail (Line 3).

Let's circle back to Step 3: we need to be aware of any changes that alter the inventory in between the first two steps.

Step 3 is the trickiest. Let's say that there is one lone hat remaining in our inventory. In between the time that User A checks the quantity of hats remaining and actually processes their transaction, User B also checks the inventory and finds likewise that there is one hat listed in stock. Both users will be allowed to purchase the hat, but we have 1 hat to sell, not 2, so we’re on the hook and one user is out of their money. Not good.

Redis has a clever answer for the dilemma in Step 3: it’s called optimistic locking, and is different than how typical locking works in an RDBMS such as PostgreSQL. Optimistic locking, in a nutshell, means that the calling function (client) does not acquire a lock, but rather monitors for changes in the data it is writing to during the time it would have held a lock. If there’s a conflict during that time, the calling function simply tries the whole process again.

You can effect optimistic locking by using the WATCH command (.watch() in redis-py), which provides a check-and-set behavior.

Follow the process up in the next file.
"""
import random
import redis

random.seed(444)

hats = {
    f"hat:{i}": i for i in
    (
        {
            "color": "black",
            "price": 49.99,
            "style": "fitted",
            "quantity": 1000,
            "npurchased": 0,
        },
        {
            "color": "maroon",
            "price": 59.99,
            "style": "hipster",
            "quantity": 500,
            "npurchased": 0,
        },
        {
            "color": "green",
            "price": 99.99,
            "style": "baseball",
            "quantity": 200,
            "npurchased": 0,
        })
}

r = redis.Redis(db=1)
with r.pipeline() as pipe:
    for h_id, hat in hats.items():
        pipe.hmset(h_id, hat)

    pipe.execute()

r.bgsave()


r.hincrby("hat:1", "quantity", -1)

r.hget("hat:1", "quantity")
# b'199'
r.hincrby("hat:1", "npurchased", 1)
