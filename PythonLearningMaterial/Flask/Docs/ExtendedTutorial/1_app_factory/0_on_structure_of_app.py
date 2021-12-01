"""
Notice the following couple of things before running the app:

	1-	The app factory is in the __init__ file of the packge. flask will run the package in this setting rather
	than the app file directly. This is what we mean by the package mode.
	2-	The name of the app is the name of the app files' folder (package). As such, the name of the app is flaskr.
	3-	When exporting the app name, we need to supply the package name, together with the app factory function,
	with a comma. Hence, in our example, it would be:
	$ export FLASK_APP=flaskr:app_factory
	4-	The instance folder will be created by the app itself, and it will contain the instance files required,
	such as our database instance, etc.
"""