"""
Sometimes you might be in a situation where you deal with data that should be correct, but actually is not. For 
example, you may have some client-side code that sends an HTTP request to the server but it’s obviously malformed. 
This might be caused by a user tampering with the data, or the client code failing. Most of the time it’s okay to 
reply with 400 Bad Request in that situation, but sometimes that won’t do and the code has to continue working.

You may still want to log that something fishy happened. This is where loggers come in handy. As of Flask 0.3 a 
logger is preconfigured for you to use.

Here are some example log calls:
app.logger.debug('A value for debugging')
app.logger.warning('A warning occurred (%d apples)', 42)
app.logger.error('An error occurred')

We may add handlers to handle log events, which could be writing to a file. Note that for logging to a file to
work, we have to be in production mode.

Another option is to log the flask logger directly by the python logger, as follows:

import logging, logging.config, yaml
logging.config.dictConfig(yaml.load(open('logging.conf')))

logfile    = logging.getLogger('file')
logconsole = logging.getLogger('console')
logfile.debug("Debug FILE")
logconsole.debug("Debug CONSOLE")
"""
from logging import FileHandler
from flask import Flask

app = Flask(__name__)

@app.route("/")	
def hello_world():
	file_handler = FileHandler("error.log")
	app.logger.addHandler(file_handler)

	app.logger.critical("Wow! Someone is using this.")
	return "<p>Hello, dear World!</p>"	

