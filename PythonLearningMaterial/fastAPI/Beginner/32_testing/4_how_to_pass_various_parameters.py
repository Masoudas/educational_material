"""
Whenever you need the client to pass information in the request and you don't know how to, you can search (Google) how to do it in requests. Then you just do the same in your tests.

E.g.:
    -   To pass a path or query parameter, add it to the URL itself.
    -   To pass a JSON body, pass a Python object (e.g. a dict) to the parameter json.
    -   If you need to send Form Data instead of JSON, use the data parameter instead.
    -   To pass headers, use a dict in the headers parameter.
    -   For cookies, a dict in the cookies parameter
"""
