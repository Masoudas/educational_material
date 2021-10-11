"""
Loggers have the following attributes and methods. Note that Loggers should NEVER be instantiated directly, but 
always through the module-level function logging.getLogger(name). Multiple calls to getLogger() with the same name 
will always return a reference to the same Logger object. (Me: so that all modules use the same logger)

The name is potentially a period-separated hierarchical value, like foo.bar.baz (though it could also be just plain 
foo, for example). Loggers that are further down in the hierarchical list are children of loggers higher up in the 
list. For example, given a logger with a name of foo, loggers with names of foo.bar, foo.bar.baz, and foo.bam are 
all descendants of foo. The logger name hierarchy is analogous to the Python package hierarchy, and identical to 
it if you organise your loggers on a per-module basis using the recommended construction 
logging.getLogger(__name__). That’s because in a module, __name__ is the module’s name in the Python package 
namespace.

Me: I skipped the class documentation, but below is an example: 
"""

import logging

FORMAT = '%(asctime)-15s %(clientip)s %(user)-8s %(message)s'
logging.basicConfig(format=FORMAT)

d = {'clientip': '192.168.0.1', 'user': 'fbloggs'}
logger = logging.getLogger('tcpserver')
logger.warning('Protocol problem: %s', 'connection reset', extra=d)	# Print a warning message
logger.critical('Critical Error', extra=d)
logger.debug("Nice debugging", extra=d)
# Prints something like:
# 2006-02-08 22:20:02,165 192.168.0.1 fbloggs  Protocol problem: connection reset