"""
Using the %s, it's possible to log variable data.
"""
import logging

logging.basicConfig(filename="app.log", level=logging.INFO)
logging.info("%s is a warning %s", "This", "message")
logging.info("{placement}".format(placement="My message"))
