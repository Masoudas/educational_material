"""
It's possible to supply a format string, through which we can set time, and other information for the logging.
A syntax such as %(what)s displays something. what can be:
	-	levelname
	-	asctime, together with a datefmt parameter as datefmt='%m/%d/%Y %I:%M:%S %p'
	-	message
	-	custom keys: Should be passed with the extra argument in the logger functions

If we define custom keys, we can send them using a dictionary to the logger. format of course has to be defined
by the basicConfig method,
"""
import logging

logging.basicConfig(filename="app.log", datefmt="%d/%m/%Y %I:%M:%S", 
	format="%(asctime)s - %(levelname)s:%(message)s - %(user)s@%(ip)s")

dic = {"user" : "Masoudas", "ip" : "192.167.1.1"}
logging.warning("This is the location for the message", extra=dic)

