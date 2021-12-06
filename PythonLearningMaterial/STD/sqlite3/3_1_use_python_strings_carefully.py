"""
SQL operations usually need to use values from Python variables. However, beware of using Python’s string operations to assemble queries, as they are vulnerable to SQL injection attacks (see the xkcd webcomic for a humorous example of what can go wrong):
"""

import sqlite3

con = sqlite3.connect("myDB.db")
cur = con.cursor()

date = "2005-10-11"; trans = "SELL"; symbol = "RHAT"; qty = 100; price = 10
cur.execute(f'INSERT INTO stock VALUE ({date},{trans},{symbol},{qty},{price})')
