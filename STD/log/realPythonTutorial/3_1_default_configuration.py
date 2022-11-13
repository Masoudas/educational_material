"""
You can use the basicConfig(**kwargs) method to configure the logging. These are the parameters mostly used:

    -   level: The root logger will be set to the specified severity level.
    -   filename: This specifies the file.
    -   filemode: If filename is given, the file is opened in this mode. The default is a, which means append.
    -   format: This is the format of the log message.

For example, here we set the logging level to debug.  

It should be noted that calling basicConfig() to configure the root logger works only if the root logger has not been configured before. Basically, this function can only be called once.

debug(), info(), warning(), error(), and critical() also call basicConfig() without arguments automatically if it has not been called before. This means that after the first time one of the above functions is called, you can no longer configure the root logger because they would have called the basicConfig() function internally.

Note also that the default logging is to command line, and this would imply writing to ext://sys.stdout for example.
"""
import logging

logging.basicConfig(level=logging.DEBUG)