"""
One thing that’s worth knowing is that redis-py requires that you pass it keys that are bytes, str, int, or float. (It will convert the last 3 of these types to bytes before sending them off to the server.)

Consider a case where you want to use calendar dates as keys. You’ll need to explicitly convert the Python date object to str, which you can do with .isoformat():
"""
import datetime
import redis

r = redis.Redis()

# Raises redis data error
r.sadd(datetime.datetime.today(), *{1, 2, 3})
