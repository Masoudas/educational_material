"""
Logging provides a set of convenience functions for simple logging usage. These are debug(), info(), warning(), 
error() and critical(). To determine when to use logging, see the table below, which states, for each of a set of 
common tasks, the best tool to use for it.

	Task you want to perform												The best tool for the task

Display console output for ordinary usage of a command line script or program			print()

Report events that occur during normal operation of a program (e.g. for status 
monitoring or fault investigation)										logging.info() (or logging.debug() for very 
																		detailed output for diagnostic purposes)

Issue a warning regarding a particular runtime event					 warnings.warn() in library 
																		code if the issue is avoidable and the client 
																		application should be modified to eliminate the 
																		warning															logging.warning() 

																		if there is nothing the client application 
																		can do about the situation, but the event 
																		should still be noted

Report an error regarding a particular runtime event					Raise an exception

Report suppression of an error without raising an exception (e.g. 
error handler in a long-running server process)							logging.error(), logging.exception() or 
																		logging.critical() as appropriate for the 
																		specific error and application domain

A simple example is given below.
Note that as mentioned below, the info level message will not appear, because the default level is warning. The
levels are: DEBUG, INFO, WARNING, ERROR, CRITICAL. ME: Also notice that the default logger is stdout.
"""
import logging

logging.warning('Watch out!')  # will print a message to the console
logging.info('I told you so')  # will not print anything
