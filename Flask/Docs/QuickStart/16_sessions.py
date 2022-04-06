"""
In addition to the request object there is also a second object called session which allows you to store 
information specific to a user from one request to the next. This is implemented on top of cookies for you and 
signs the cookies cryptographically. What this means is that the user could look at the contents of your cookie 
but not modify it, unless they know the secret key used for signing.
"""

from flask import Flask, session, request, redirect, url_for
from secrets import token_hex

app = Flask(__name__)


# Set the secret key to some random bytes. Keep this really secret!
app.secret_key = token_hex()

@app.route('/')
def index():
    if 'username' in session:
        return f'Logged in as {session["username"]}'
    return 'You are not logged in'

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        session['username'] = request.form['username']
        return redirect(url_for('index'))	# What is index?
    return '''
        <form method="post">
            <p><input type=text name=username>
            <p><input type=submit value=Login>
        </form>
    '''

@app.route('/logout')
def logout():
    # remove the username from the session if it's there
    session.pop('username', None)
    return redirect(url_for('index'))