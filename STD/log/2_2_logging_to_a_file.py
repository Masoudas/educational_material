"""
To log to a file, we should setup the logger.

The call to basicConfig() should come before any calls to debug(), info() etc. As it’s intended as a one-off simple 
configuration facility, only the first call will actually do anything: subsequent calls are effectively no-ops.

Also note that the default logging file writing mode is appending. We can change it by setting the filemode parameter
in the basicConfig.

Note that as such, various modules in the code can use the logging fascility, and they'll all log to the same 
mylogger.log file.
"""
import logging
import sys

logging.basicConfig(filename="mylogger.log", level=logging.DEBUG)

#logging.basicConfig(filename=sys.stderr) Logging to stderr
#logging.basicConfig(filename=sys.stdout) Logging to stdout (by default)

logging.warning("Here's a warning")
logging.critical("Here's something critical")
logging.error('And non-ASCII stuff, too, like Øresund and Malmö')