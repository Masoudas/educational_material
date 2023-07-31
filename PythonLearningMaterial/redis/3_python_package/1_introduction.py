"""
The Python Redis client library, redis-py, that you’ll dive into shortly in this article, does things differently from redis-cli. It encapsulates an actual TCP connection to a Redis server and sends raw commands, as bytes serialized using the REdis Serialization Protocol (RESP), to the server. It then takes the raw reply and parses it back into a Python object such as bytes, int, or even datetime.datetime.

The following demonstrates how to connect to the redis instance. Notice that the outcome of each key in the example below is a binary string, hence, we need to decode it.

Note that there's a db parameter, that allows us to define new databases, which accepts ints.
"""
import redis

r = redis.Redis()

r.mset({"Hello": "world", "are": "ready", "for": "me"})

vals = r.mget("Hello", "are", "for")
print([val.decode() for val in vals if val is not None])
