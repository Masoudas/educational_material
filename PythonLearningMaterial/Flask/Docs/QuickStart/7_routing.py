"""
Modern web applications use meaningful URLs to help users. Users are more likely to like a page and come back if 
the page uses a meaningful URL they can remember and use to directly visit a page.

You can make parts of the URL dynamic and attach multiple rules to a function.
"""
from flask import Flask

app = Flask(__name__)

@app.route("/page1")
def page_one():
	return "<p>Page 1<p>"

@app.route("/page2")
def page_two():
	return "<p>Page 2<p>"