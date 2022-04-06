"""
You often want to send some sort of data in the URL's query string. If you were constructing the URL by hand, this data would be given as key/value pairs in the URL after a question mark, e.g. httpbin.org/get?key=val. Requests allows you to provide these arguments as a dictionary of strings, using the params keyword argument. As an example, if you wanted to pass key1=value1 and key2=value2 to httpbin.org/get, you would use the following code:

Me: When working with APIs, we usually send data to get data. This is not done with the post or update method. Because those are responsible for updating the page, whereas we want to get some data based on our params. For example, we were working with the GIS DB, and we used the get method to get data, with the passed values.

Note that any dictionary key whose value is None will not be added to the URL’s query string.
"""
import requests

payload = {'key1': 'value1', 'key2': ['value2', 'value3']}
r = requests.get('https://httpbin.org/get', params=payload)

print(r.url)
