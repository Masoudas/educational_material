"""
The logger object provides a method for logging exceptions, called exception. The exception method accepts
a message, and then prints the stack trace as well.

Note also that there's one for logging errors as well.
"""

import logging

logging.basicConfig(filename="logger.log")

try:
	raise Exception()
except Exception:
	logging.exception("Loggin the exception")

