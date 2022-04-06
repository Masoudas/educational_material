"""
    1-  First we imported the Flask class. An instance of this class will be our WSGI application.
    2-  Next we create an instance of this class. The first argument is the name of the application’s module or 
    package. __name__ is a convenient shortcut for this that is appropriate for most cases. This is needed so that 
    Flask knows where to look for resources such as templates and static files.
    3-  We then use the route() decorator to tell Flask what URL should trigger our function.
    4-  The function returns the message we want to display in the user’s browser. The default content type is 
    HTML, so HTML in the string will be rendered by the browser.

Now, to run this application, we need to first export the famous(?) FLASK_APP variable, which is set to the
name of our application:
$ export FLASK_APP=2_first_app  # The name of this file.

Then, we run the app using the flask command line:
$ cd Flask/Docs
$ flask run

As such, the framework is available on localhost/5000, which is printed by the run message. Notice that when
openning the webbrowser to get this page, a get command has been sent:
127.0.0.1 - - [29/Nov/2021 08:41:55] "GET / HTTP/1.1" 200 -

If another program is already using port 5000, you’ll see OSError: [Errno 98] or OSError: [WinError 10013] when 
the server tries to start. See Address already in use for how to handle that.

To run the application in deployement mode, set the FLASK_ENV:
$export FLASK_ENV=deployement

Development mode shows an interactive debugger whenever a page raises an exception, and restarts the server 
whenever you make changes to the code. You can leave it running and just reload the browser page.
"""
from flask import Flask

app = Flask(__name__)
app.debug = False

@app.route("/")	# Route is like the page hierarchy of the app
def hello_world():
    return "<h1>Navid is very fat!</h1>"	# Return an html project.

