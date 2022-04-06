"""
The subprocess is used for running subprocesses of this program process.

What is shell argument useful for? I don't know. But apparently, it's the source of many problems and should be
avoided. If we don't use it, we have to pass the arguments as a list.
"""
import subprocess

print(subprocess.run(["ls -l"], capture_output=True, shell=True))
print(subprocess.run(["ls", "-l"], capture_output=True))
