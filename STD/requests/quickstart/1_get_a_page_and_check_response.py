"""
using the get method (which corresponds to the get method,) we can get from a webpage, and then check that its response is 200 OK

We should note that the time it gets to get a response is a lot.
"""
import requests
import time

now = time.time()
result: requests.models.Response = requests.get(
    'https://api.github.com/events')
then = time.time()

print(result.ok)
print(then - now)
