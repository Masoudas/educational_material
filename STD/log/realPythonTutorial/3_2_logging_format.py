"""
In this example, we shall use a formating for the basic logger using the basicConfig method. Notice that the placeholders %()s are used for defining logging parameters, like %(name)s, %(levelname), %(message)s' and others. Notice also the mode parameter is set to 'w' and not 'a', which would imply writing to the file, and not appending to it.
"""
import logging

logging.basicConfig(
    mode='a', filename="logs.log", format='%(name)s - %(levelname)s - %(message)s', level=logging.DEBUG
)
