"""
The unittest module can be used from the command line to run tests from modules, classes or even individual test 
methods:

$ python -m unittest test_module1 test_module2
$ python -m unittest test_module.TestClass
$ python -m unittest test_module.TestClass.test_method

You can pass in a list with any combination of module names, and fully qualified class or method names.

Test modules can be specified by file path as well:
$ python -m unittest tests/test_something.py

We can also run the test with more verbosity by passing the -v option.
"""