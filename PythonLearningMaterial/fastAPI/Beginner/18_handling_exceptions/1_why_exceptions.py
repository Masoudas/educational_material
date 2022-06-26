"""
There are many situations where you need to notify an error to a client that is using your API. This client could be a browser with a frontend, a code from someone else, an IoT device, etc.

You could need to tell the client that:
    -   The client doesn't have enough privileges for that operation.
    -   The client doesn't have access to that resource.
    -   The item the client was trying to access doesn't exist.
etc.
In these cases, you would normally return an HTTP status code in the range of 400 (from 400 to 499).
This is similar to the 200 HTTP status codes (from 200 to 299). Those "200" status codes mean that somehow there was a "success" in the request.

The status codes in the 400 range mean that there was an error from the client. Remember all those "404 Not Found" errors (and jokes)?
"""
