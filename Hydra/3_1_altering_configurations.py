"""
Normally, we want to switch between configurations. This is where the power of hydra comes in. Define multiple config files for the db as follows in the db folder. Also notice the addition of the init file:

├── conf
│   ├── config.yaml
│   ├── db
│   │   ├── mysql.yaml
│   │   └── postgresql.yaml
│   └── __init__.py
└── my_app.py

Now, inside the config file, define defaults for each config (db in this case) as follows:
defaults:
  - db: mysql

defaults is a special directive telling Hydra to use db/mysql.yaml when composing the configuration object. The resulting cfg object is a composition of configs from defaults with configs specified in your config.yaml.

Now, the even cooler thing is that we may choose from the command line as well:
$ python my_app.py db=postgresql db.timeout=20
db:
  driver: postgresql
  pass: drowssap
  timeout: 20
  user: postgres_user
"""