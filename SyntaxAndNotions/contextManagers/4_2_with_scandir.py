"""
Here's something I didn't know. When scanning a dir, we should use context managers:

>>> with os.scandir(".") as entries:
...     for entry in entries:
...         print(entry.name, "->", entry.stat().st_size, "bytes")
...
"""
