"""
The Web Server Gateway Interface (WSGI, pronounced whiskey[1][2] or WIZ-ghee[3]) is a simple calling convention 
for web servers to forward requests to web applications or frameworks written in the Python programming language. 
The current version of WSGI, version 1.0.1, is specified in Python Enhancement Proposal (PEP) 

The WSGI has two sides:

	-	the server/gateway side. This is often running full web server software such as Apache or Nginx, or is a 
	lightweight application server that can communicate with a webserver, such as flup.
	-	the application/framework side. This is a Python callable, supplied by the Python program or framework.

Between the server and the application, there may be one or more WSGI middleware components, which implement both 
sides of the API, typically in Python code.
"""