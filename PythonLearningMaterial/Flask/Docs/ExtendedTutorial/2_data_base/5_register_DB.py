"""
The close_db and init_db_command functions need to be registered with the application instance; otherwise, they 
won’t be used by the application. However, since you’re using a factory function, that instance isn’t available 
when writing the functions. Instead, write a function that takes an application and does the registration.

Finally, we need to add this portion to the app factory function.

def create_app():
    app = ...
    # existing code omitted

    from . import db
    db.init_app(app)

    return app
"""
from flask import Flask

def init_app(app: Flask):
    app.teardown_appcontext(close_db)
    app.cli.add_command(init_db_command)