"""
Typically, you want to send some form-encoded data — much like an HTML form. To do this, simply pass a dictionary to the data argument. Your dictionary of data will automatically be form-encoded when the request is made.

Again, note that we can pass a list of values for a key.
"""
import requests

payload = {'key1': ['value1', 'value2'], 'key2': 'value2'}

r = requests.post("https://httpbin.org/post", data=payload)
print(r.text)
