"""
app.config.from_mapping() sets some default configuration that the app will use:

	-	SECRET_KEY is used by Flask and extensions to keep data safe. It’s set to 'dev' to provide a convenient 
	value during development, but it should be overridden with a random value when deploying.
	-	DATABASE is the path where the SQLite database file will be saved. It’s under app.instance_path, which is 
	the path that Flask has chosen for the instance folder. 

app.config.from_pyfile() overrides the default configuration with values taken from the config.py file in the 
instance folder if it exists. For example, when deploying, this can be used to set a real SECRET_KEY.

	*	test_config can also be passed to the factory, and will be used instead of the instance configuration. 
	This is so the tests you’ll write later in the tutorial can be configured independently of any development 
	values you have configured.

Me: I guess from_pyfile overrides existing keys. Otherwise, if a key does not exist, it's not deleted.
"""