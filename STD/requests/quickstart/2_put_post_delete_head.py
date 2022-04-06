"""
Similarly, we have access to put, post, and delete methods.

Also, notice that the same module works with https as well as http.
"""
import requests

r = requests.post('https://httpbin.org/post', data={'key': 'value'})
print(r.headers)

r = requests.put('https://httpbin.org/put', data={'key': 'value'})
r = requests.delete('https://httpbin.org/delete')
r = requests.head('https://httpbin.org/get')
r = requests.options('https://httpbin.org/get')
