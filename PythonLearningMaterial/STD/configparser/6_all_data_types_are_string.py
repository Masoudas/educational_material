"""
One thing to note is that all data types are string. Hence, we need explicit conversions. The good news is that the are casting methods.

Notice that the getXXX method is used once we want to get the value pair of course. Another positive property is that we can return defaults. It's called fallback
"""
import configparser

config = configparser.ConfigParser()
print(config.sections())  # Nothing now.

# Th
config.read('example.ini')
print(
    config['topsecret.server.example'].getint('port', fallback=42))  # Now, prints 50022
print(
    config['topsecret.server.example'].getint('port1', fallback=42))  # Now, prints 42