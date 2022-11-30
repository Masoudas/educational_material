"""
An origin is the combination of protocol (http, https), domain (myapp.com, localhost, localhost.tiangolo.com), and port (80, 443, 8080).

So, all these are different origins:
    -   http://localhost
    -   https://localhost
    -   http://localhost:8080

Even if they are all in localhost, they use different protocols or ports, so, they are different "origins"
"""
