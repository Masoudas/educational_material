"""
SQLite is convenient because it doesn’t require setting up a separate database server and is built-in to Python. 
However, if concurrent requests try to write to the database at the same time, they will slow down as each write 
happens sequentially. Small applications won’t notice this. Once you become big, you may want to switch to a 
different database.


"""