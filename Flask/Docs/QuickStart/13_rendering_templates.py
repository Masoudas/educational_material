"""
To render already template html files, use the render_template function.

NOTE: template htmls are different from htmls in that they have variables that can be assigned to etc. An example
is as follows. Jinja2 has a full documentation on this matter:

<!doctype html>
<title>Hello from Flask</title>
{% if name %}
  <h1>Hello {{ name }}!</h1>
{% else %}
  <h1>Hello, World!</h1>
{% endif %}

Flask will look for templates in the templates folder. So if your application is a module, this folder is next to 
that module, if it’s a package it’s actually inside your package:

Case 1: A module:
/application.py
/templates
    /hello.html

Case 2: A package:
/application
    /__init__.py
    /templates
        /hello.html
"""

from flask import Flask, render_template

app = Flask(__name__)

@app.route('/hello/')
@app.route('/hello/<name>')
def hello(name=None):
    return render_template('hello.html', name=name)	# Name is the template to replace in the template above.