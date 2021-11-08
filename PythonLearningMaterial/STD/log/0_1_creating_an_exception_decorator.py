"""
To log exceptions, one thing we can do is to create decorators for them, which we place on top of the function
that throws. As such, we only have to decorate a function for it to throw an exception.

Notice that the exception decorator creates the logger everytime it wants to log the exception. Also note
that this decorator only logs unhandled exceptions. Because if the exception is handled inside the function,
then it won't reach the decorator function, so we can't log it from there.

We may also pass a logger to our decorator, using the following modification:

import functools
def exception(logger):
    A decorator that wraps the passed in function and logs 
    exceptions should one occur
    
    @param logger: The logging object
    
    def decorator(func):
    
        def wrapper(*args, **kwargs):
            try:
                return func(*args, **kwargs)
            except:
                # log the exception
                err = "There was an exception in  "
                err += func.__name__
                logger.exception(err)
            
            # re-raise the exception
            raise
        return wrapper
    return decorator
"""
import functools
import logging

def create_logger():
    """
    Creates a logging object and returns it
    """
    logger = logging.getLogger("example_logger")
    logger.setLevel(logging.INFO)
    # create the logging file handler
    fh = logging.FileHandler("logger.log")
    fmt = '%(asctime)s - %(name)s - %(levelname)s - %(message)s'
    formatter = logging.Formatter(fmt)
    fh.setFormatter(formatter)
    # add handler to logger object
    logger.addHandler(fh)
    return logger

def exception(function):
    """
    A decorator that wraps the passed in function and logs 
    exceptions should one occur
    """
    @functools.wraps(function)
    def wrapper(*args, **kwargs):
        logger = create_logger()
        try:
            return function(*args, **kwargs)
        except:
            # log the exception
            err = "There was an exception in  "
            err += function.__name__
            logger.exception(err)
            # re-raise the exception
            raise
    return wrapper

@exception
def main():
	raise Exception

main()