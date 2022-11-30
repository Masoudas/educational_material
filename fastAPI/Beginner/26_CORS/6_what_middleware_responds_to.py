"""
The middleware responds to two types of requests:

    -   CORS preflight requests
These are any OPTIONS request with Origin and Access-Control-Request-Method headers. In this case the middleware will intercept the incoming request and respond with appropriate CORS headers, and either a 200 or 400 response for informational purposes.

    -   Simple requests
Any request with an Origin header. In this case the middleware will pass the request through as normal, but will include appropriate CORS headers on the response.
"""
