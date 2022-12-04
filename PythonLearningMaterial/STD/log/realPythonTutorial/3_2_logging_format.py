"""
In this example, we shall use a formating for the basic logger using the basicConfig method. Notice that the placeholders %()s are used for defining logging parameters, like %(name)s, %(levelname), %(message)s' and others. Notice also the mode parameter is set to 'w' and not 'a', which would imply writing to the file, and not appending to it.

The available logs are here:
https://docs.python.org/3/library/logging.html#logrecord-attributes

We may also specify how to format date and time as well. The link is here in the docs: https://docs.python.org/3/library/datetime.html#strftime-and-strptime-behavior
"""
import logging

logging.basicConfig(
    mode='a', filename="logs.log", format='%(name)s - %(levelname)s - %(message)s', level=logging.DEBUG
)
