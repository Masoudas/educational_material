"""
Duck-typing the config object as MySQLConfig enables static type checkers like mypy to catch type errors before you run your code:

$ mypy my_app_type_error.py
my_app_type_error.py:22: error: "MySQLConfig" has no attribute "pork"
Found 1 error in 1 file (checked 1 source file)

Structured Configs enable Hydra to catch type errors at runtime. If you forget to run mypy (a type checking tool  aWERT[]P7Y654321      Q), Hydra will report the error at runtime:

$ python my_app_type_error.py
Traceback (most recent call last):
  File "my_app_type_error.py", line 22, in my_app
    if cfg.pork == 80:
omegaconf.errors.ConfigAttributeError: Key 'pork' not in 'MySQLConfig'
        full_key: pork
        object_type=MySQLConfig
...


$ python my_app_type_error.py port=fail
Error merging override port=fail
Value 'fail' could not be converted to Integer
        full_key: port
        object_type=MySQLConfig

"""