"""
Similarly, we can read an ini file as follows:
"""
import configparser

config = configparser.ConfigParser()
print(config.sections())  # Nothing now.

# Th
config.read('example.ini')
print(config.sections())  # Now, prints the sections

'forge.example' in config  # True
'python.org' in config  # False

print(config['forge.example']['User'])  # prints 'hg'
print(config['DEFAULT']['Compression'])  # prints 'yes'

topsecret = config['topsecret.server.example']
print(topsecret['ForwardX11'])
print(topsecret['Port'])
for key in config['forge.example']:
    print(key)

print(config['forge.example']['ForwardX11'])
