"""
To redirect a user to another endpoint, use the redirect() function; to abort a request early with an error code,
use the abort() function:
"""

from flask import Flask, abort, redirect, url_for

app = Flask(__name__)


@app.route('/')
def index():
    return redirect(url_for('login'))

@app.route('/login')
def login():
    abort(401)
    #this_is_never_executed()