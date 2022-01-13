"""
We can check the response status code:

Requests also comes with a built-in status code lookup object for easy reference:

If we made a bad request (a 4XX client error or 5XX server error response), we can raise it with Response.raise_for_status():

But, since our status_code for r was 200, when we call raise_for_status() we get: All is well.
"""
import requests

r = requests.get('https://httpbin.org/get')
r.status_code
200

r.status_code == requests.codes.ok  # Check if Ok.

bad_r = requests.get('https://httpbin.org/status/404')
bad_r.status_code
404

bad_r.raise_for_status()
