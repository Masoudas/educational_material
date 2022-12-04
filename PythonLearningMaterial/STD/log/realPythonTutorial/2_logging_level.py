"""
With the logging module imported, you can use something called a “logger” to log messages that you want to see. By default, there are 5 standard levels indicating the severity of events. Each has a corresponding method that can be used to log events at that level of severity. The defined levels, in order of increasing severity, are the following:
    -   DEBUG
    -   INFO
    -   WARNING
    -   ERROR
    -   CRITICAL

The logging module provides you with a default logger that allows you to get started without needing to do much configuration. The corresponding methods for each level can be called as shown in the following example:

Note: Why no debug and info messages? This is because the logging level is set to warning. Thus, we need to set the loggin level to a value. We can define custom levels of logging, but we prefer not to. This is because it may confuse third party loggers.
"""
import logging

logging.debug('This is a debug message')
logging.info('This is an info message')
logging.warning('This is a warning message')
logging.error('This is an error message')
logging.critical('This is a critical message')
