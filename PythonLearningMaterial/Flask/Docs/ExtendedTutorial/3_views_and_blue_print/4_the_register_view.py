"""
The first view is the register view, which we use to register with our blog.

When the user visits the /auth/register URL, the register view will return HTML with a form for them to fill out. 
When they submit the form, it will validate their input and either show the form again with an error message or 
create the new user and go to the login page.

The template for showing the registery form is shown next.

Me: Notice that the same method is used for both posting, and getting the data from the page.

Notice that whatever is returned from the page, it's in the request variable (of Request type,) which we import
from flask. Then, we can access fields from the form dictionary.

Notice also the use of the flash method for reflecting errors.

"""
import functools
from flask import Blueprint, flash, g, redirect, render_template, request, session, url_for
from werkzeug.security import check_password_hash, generate_password_hash
from flaskr.db import get_db

bp = Blueprint('auth', __name__, url_prefix='/auth')	# The pattern is then /auth

@bp.route('/register', methods=('GET', 'POST'))		# Both for accessing and writing to the page.
def register():
    if request.method == 'POST':	# If the user is posting something to the server.
        username = request.form['username']		# Notice how to access the form.
        password = request.form['password']
        db = get_db()	# Accessing the db for writing to it.
        error = None

        if not username:
            error = 'Username is required.'
        elif not password:
            error = 'Password is required.'

        if error is None:
            try:
                db.execute(
                    "INSERT INTO user (username, password) VALUES (?, ?)",
                    (username, generate_password_hash(password)),
                )
                db.commit()
            except db.IntegrityError:
                error = f"User {username} is already registered."
            else:
                return redirect(url_for("auth.login"))

        flash(error)	# Ah! A simple form for just reflecting the results.

    return render_template('auth/register.html')