"""
The 'flask run' command can do more than just start the development server. By enabling debug mode, the server 
will automatically reload if code changes, and will show an interactive debugger in the browser if an error occurs 
during a request.

The debugger allows executing arbitrary Python code from the browser. It is protected by a pin, but still 
represents a major security risk. Do not run the development server or debugger in a production environment.

To enable all development features, set the FLASK_ENV environment variable to development before calling flask 
run:

$ export FLASK_ENV=development
$ flask run
"""