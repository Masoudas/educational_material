"""
app = Flask(__name__, instance_relative_config=True) creates the Flask instance.
	* __name__ is the name of the current Python module. The app needs to know where it’s located to set up some 
	paths, and __name__ is a convenient way to tell it that.

	* instance_relative_config=True tells the app that configuration files are relative to the instance folder. 
	The instance folder is located outside the flaskr package and can hold local data that shouldn’t be committed 
	to version control, such as configuration secrets and the database file.
"""