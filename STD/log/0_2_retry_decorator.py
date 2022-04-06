"""
The retry decorator allows us to execute a patch of code that has thrown once it fails. This decorator
is in the retry package:

$ pip install retry

This is especially useful in case for example there's a connection error (to a database for example) and
we need to retry our operation.

The api is follows:
	:param exceptions: an exception or a tuple of exceptions to catch. default: Exception.
    :param tries: the maximum number of attempts. default: -1 (infinite).
    :param delay: initial delay between attempts. default: 0.
    :param max_delay: the maximum value of delay. default: None (no limit).
    :param backoff: multiplier applied to delay between attempts. default: 1 (no backoff).
    :param jitter: extra seconds added to delay between attempts. default: 0.
                   fixed if a number, random if a range tuple (min, max)
    :param logger: logger.warning(fmt, error, delay) will be called on failed attempts.
                   default: retry.logging_logger. if None, logging is disabled.
"""

from retry import retry

@retry(ZeroDivisionError, delay=2, tries=20)
def thrower():
	raise ZeroDivisionError

thrower()