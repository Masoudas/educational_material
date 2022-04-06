"""
When returning HTML (the default response type in Flask), any user-provided values rendered in the output must be 
escaped to protect from injection attacks. HTML templates rendered with Jinja, introduced later, will do this 
automatically.

escape(), shown here, can be used manually. It is omitted in most examples for brevity, but you should always be 
aware of how you’re using untrusted data

If a user managed to submit the name <script>alert("bad")</script>, escaping causes it to be rendered as text, 
rather than running the script in the user’s browser.

<name> in the route captures a value from the URL and passes it to the view function. 
"""
from flask import app
from markupsafe import escape

@app.route("/<name>")	# We must use the page as localhost:5000/Masoud, then it prints masoud
def hello(name):
    return f"Hello, {escape(name)}!"