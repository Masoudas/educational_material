"""
We may also convert the response to json seamlessly using the json method of Response.

In case the JSON decoding fails, r.json() raises an exception. For example, if the response gets a 204 (No Content), or if the response contains invalid JSON, attempting r.json() raises requests.exceptions.JSONDecodeError. This wrapper exception provides interoperability for multiple exceptions that may be thrown by different python versions and json serialization libraries.

It should be noted that the success of the call to r.json() does not indicate the success of the response. Some servers may return a JSON object in a failed response (e.g. error details with HTTP 500). Such JSON will be decoded and returned. To check that a request is successful, 
use r.raise_for_status() or check r.status_code is what you expect.
"""
import requests

r = requests.get('https://api.github.com/events')
r.raise_for_status()
print(r.json())
