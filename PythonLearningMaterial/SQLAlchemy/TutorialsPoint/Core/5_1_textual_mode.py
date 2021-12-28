"""
To execute textual commands, we need to import the Text object.

The advantages text() provides over a plain string are −
    -   backend-neutral support for bind parameters
    -   per-statement execution options
    -   result-column typing behaviour

See the textual select operation.
"""

from sqlalchemy import text, create_engine

t = text("SELECT * FROM students")
result = create_engine("").connect().execute(t)

# Notice how x and y are params to be passed values, and how we pass values in the execute function.
s = text(
    "select students.name, students.lastname from students where students.name between :x and :y")
create_engine("").connect().execute(s, x = 'A', y = 'L').fetchall()