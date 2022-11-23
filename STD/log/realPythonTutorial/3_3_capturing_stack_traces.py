"""
To capture execption messages in the program, even if they're not logged, we may use exec_info=True option. This will capture the exception message for example in the following code.

A better tip here is to use logging.exception()
"""
import logging

a = 5
b = 0

try:
    c = a / b
except Exception as e:
    logging.error("Exception occurred", exc_info=True)
    logging.exception("Cow-tow to this!")
