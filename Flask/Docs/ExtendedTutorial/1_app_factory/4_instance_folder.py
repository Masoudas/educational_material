"""
The instance folder has to be created, and it's not created automatically.

os.makedirs() ensures that app.instance_path exists. Flask doesn’t create the instance folder automatically, but 
it needs to be created because your project will create the SQLite database file there.
"""