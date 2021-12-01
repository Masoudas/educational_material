"""
A Blueprint is a way to organize a group of related views and other code. Rather than registering views and other 
code directly with an application, they are registered with a blueprint. Then the blueprint is registered with 
the application when it is available in the factory function.

Flaskr will have two blueprints, one for authentication functions and one for the blog posts functions. The code 
for each blueprint will go in a separate module. Since the blog needs to know about authentication, you’ll write 
the authentication one first.

The following goes into the auth.py file

This creates a Blueprint named 'auth'. Like the application object, the blueprint needs to know where it’s defined, 
so __name__ is passed as the second argument. The url_prefix will be prepended to all the URLs associated with 
the blueprint.
"""
import functools
from flask import Blueprint, flash, g, redirect, render_template, request, session, url_for
from werkzeug.security import check_password_hash, generate_password_hash
from flaskr.db import get_db

bp = Blueprint('auth', __name__, url_prefix='/auth')	# The pattern is then /auth


