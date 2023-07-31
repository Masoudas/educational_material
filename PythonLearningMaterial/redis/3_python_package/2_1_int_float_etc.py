"""
Note that the returned type is bytes regardless of what is set in Redis. Hence, we need a proper conversion. Of course, a direct conversion to int from bytes is possible.
"""
import redis

r = redis.Redis()

# Raises redis data error
r.sadd("1", *{1, 2, 3})
print([int(v) for v in r.spop("1", 5)])
