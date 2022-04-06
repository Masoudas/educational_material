"""
Web applications use different HTTP methods when accessing URLs. By default, a route only answers to GET requests. 
You can use the methods argument of the route() decorator to handle different HTTP methods.

If GET is present, Flask automatically adds support for the HEAD method and handles HEAD requests according to 
the HTTP RFC. Likewise, OPTIONS is automatically implemented for you.
"""

from flask import Flask
from markupsafe import escape
app = Flask(__name__)

@app.route("/<string:name>", methods=['POST', 'PUT'])
def post_and_put(name):
	return f"name is {escape(name)}"