"""
It is good practice to use the with keyword when dealing with file objects. The advantage is that the file is 
properly closed after its suite finishes, even if an exception is raised at some point. Using with is also much 
shorter than writing equivalent try-finally blocks
"""

with open('workfile') as f:
    read_data = f.read()

print(f.closed)	# Always prints true.
