"""
We can view the server’s response headers using a Python dictionary:

>>> r.headers

The dictionary is special, though: it's made just for HTTP headers. According to RFC 7230, HTTP Header names are case-insensitive.

So, we can access the headers using any capitalization we want:

r.headers['Content-Type']
'application/json'

r.headers.get('content-type')
'application/json'

It is also special in that the server could have sent the same header multiple times with different values, but requests combines them so they can be represented in the dictionary within a single mapping, as per RFC 7230:

A recipient MAY combine multiple header fields with the same field name into one “field-name: field-value” pair, without changing the semantics of the message, by appending each subsequent field value to the combined field value in order, separated by a comma.


"""