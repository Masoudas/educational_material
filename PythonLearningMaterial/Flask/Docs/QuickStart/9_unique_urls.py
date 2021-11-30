"""
OR redirection behavior. Consider the following two examples:

With /projects/, this is essentially like a folder in Linux system. If you access the URL without a trailing 
slash (/projects), Flask redirects you to the canonical URL with the trailing slash (/projects/).

With /about, however, if you try and access /about/, it throws a 404 error. Why? Because this is like a file,
and as such, it does not have any content (it's not a folder). Similar to a file system that we can't access a
file with slash "/a.txt/", we can't do the same in a flask app.
"""
from flask import Flask

app = Flask("")

@app.route('/projects/')
def projects():
    return 'The project page'

@app.route('/about')
def about():
    return 'The about page'