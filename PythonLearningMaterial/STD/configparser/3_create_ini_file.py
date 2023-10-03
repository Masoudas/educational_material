"""
ME: The structure is very simple. Every dictionary content is a header file. Then if we pass a dictionary, then that dictionary is written as key value pairs. In fact, what makes a dictionary key a header rather than a key-value pair? The fact that we pass another dictionary in it.
"""

import configparser
config = configparser.ConfigParser()
config['DEFAULT'] = {'ServerAliveInterval': '45',
                     'Compression': 'yes',
                     'CompressionLevel': '9'}
config['forge.example'] = {}
config['forge.example']['User'] = 'hg'
config['topsecret.server.example'] = {}

topsecret = config['topsecret.server.example']
topsecret['Port'] = '50022'     # mutates the parser
topsecret['ForwardX11'] = 'no'  # same here
config['DEFAULT']['ForwardX11'] = 'yes'

with open('example.ini', 'w') as configfile:
  config.write(configfile)