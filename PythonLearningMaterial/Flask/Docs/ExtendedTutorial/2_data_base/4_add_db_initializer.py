"""
We now add functions that are used for initializing the DB. For that, we need to have sqlite DB open. Moreover,
we need to tell flask which function to run to initalize our DB. To actually initialize the dB, we need to run
the schema.sql file. So, we run that script using the sqlite3.executescript. Easy peasy! 

Note that:
	-	open_resource() opens a file relative to the flaskr package, which is useful since you won’t necessarily 
	know where that location is when deploying the application later. get_db returns a database connection, which 
	is used to execute the commands read from the file.

click.command() defines a command line command called init-db that calls the init_db function and shows a success 
message to the user. You can read Command Line Interface to learn more about writing commands.


"""
import sqlite3
from flask import current_app, g
from flask.cli import with_appcontext
import click

def get_db():
    if 'db' not in g:
        g.db = sqlite3.connect(
            current_app.config['DATABASE'],
            detect_types=sqlite3.PARSE_DECLTYPES
        )
        g.db.row_factory = sqlite3.Row

    return g.db


def init_db():
    db = get_db()

    with current_app.open_resource('schema.sql') as f:
        db.executescript(f.read().decode('utf8'))	# Execute the script to create the DBs if not exist.
	
@click.command('init-db')	
@with_appcontext
def init_db_command():
    """Clear the existing data and create new tables."""
    init_db()
    click.echo('Initialized the database.')