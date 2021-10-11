"""
To speed up loading modules, Python caches the compiled version of each module in the __pycache__ directory under 
the name module.version.pyc, where the version encodes the format of the compiled file; it generally contains the 
Python version number. For example, in CPython release 3.3 the compiled version of spam.py would be cached as 
__pycache__/spam.cpython-33.pyc. This naming convention allows compiled modules from different releases and 
different versions of Python to coexist.

Python checks the modification date of the source against the compiled version to see if it’s out of date and needs 
to be recompiled. This is a completely automatic process. Also, the compiled modules are platform-independent, so 
the same library can be shared among systems with different architectures.

"""