"""
All exceptions inherit from BaseException, and so it can be used to serve as a wildcard. Use this with extreme 
caution, since it is easy to mask a real programming error in this way! It can also be used to print an error 
message and then re-raise the exception (allowing a caller to handle the exception as well):
"""
import sys

try:
    f = open('myfile.txt')
    s = f.readline()
    i = int(s.strip())

except BaseException as err:
    print(f"Unexpected {err=}, {type(err)=}")
    raise