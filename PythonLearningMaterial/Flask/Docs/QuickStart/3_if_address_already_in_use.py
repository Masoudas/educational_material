"""
It's possible that the port 5000 is already in use, in which case, we get the following error messages:

	-	OSError: [Errno 98] Address already in use
	-	OSError: [WinError 10013] An attempt was made to access a socket in a way forbidden by its access 
	permissions

Either identify and stop the other program, or use flask run --port 5001 to pick a different port.

You can use netstat to identify what process id is using a port, then use other operating system tools stop that 
process. The following example shows that process id 6847 is using port 5000:

$ netstat -nlp | grep 5000
tcp 0 0 127.0.0.1:5000 0.0.0.0:* LISTEN 6847/python
"""