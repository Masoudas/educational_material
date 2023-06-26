"""
Normally, we use ss -tunlp to check port states. We can also use 

$ lsof -i -n. 

lsof gives you the COMMAND, PID (process ID), and USER (user ID) of open Internet sockets when used with the -i option. Above is the echo server process.
"""