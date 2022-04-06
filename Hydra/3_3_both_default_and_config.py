"""
Your primary config can contain both config values and a Defaults List. In such cases, you should add the _self_ keyword to your defaults list to specify the composition order of the config file relative to the items in the defaults list.

If you want your primary config to override the values of configs from the Defaults List, append _self_ to the end of the Defaults List (me: because the last item is chosen!).
If you want the configs from the Defaults List to override the values in your primary config, insert _self_ as the first item in your Defaults List.    

## Uses this file.
config.yaml
defaults:
  - db: mysql
  - _self_

db:
  user: root


## Uses mysql file.
config.yaml
defaults:
  - _self_
  - db: mysql

db:
  user: root
"""