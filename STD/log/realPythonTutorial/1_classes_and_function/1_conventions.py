"""
The most commonly used classes defined in the logging module are the following:

    -   Logger: This is the class whose objects will be used in the application code directly to call the functions (me: i.e debug, info, ...).

    -   LogRecord: Loggers automatically create LogRecord objects that have all the information related to the event being logged, like the name of the logger, the function, the line number, the message, and more.

    -   Handler: Handlers send the LogRecord to the required output destination, like the console or a file. Handler is a base for subclasses like StreamHandler, FileHandler, SMTPHandler, HTTPHandler, and more. These subclasses send the logging outputs to corresponding destinations, like sys.stdout or a disk file.

    -   Formatter: This is where you specify the format of the output by specifying a string format that lists out the attributes that the output should contain.

Out of these, we mostly deal with the objects of the Logger class, which are instantiated using the module-level function logging.getLogger(name). Multiple calls to getLogger() with the same name will return a reference to the same Logger object, which saves us from passing the logger objects to every part where it’s needed. Here’s an example:
'Note: The name of a custom logger is not added by default to the log message. For example, below only prints "This is a warning", whereas the root logger prints "WARNING:root:This is a warning"'

NOTE FROM ME: Calling getLogger with empty argument does not give the default logger.
"""
import logging

logger = logging.getLogger("my_logger")
logging.warning('This is a warning')
