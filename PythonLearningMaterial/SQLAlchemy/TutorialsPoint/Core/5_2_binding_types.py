"""
The text() construct supports pre-established bound values using the TextClause.bindparams() method. The parameters can also be explicitly typed as follows 

The text() function also produces fragments of SQL within a select() object that 
accepts text() objects as an arguments. The “geometry” of the statement is provided by 
select() construct , and the textual content by text() construct. We can build a statement 
without the need to refer to any pre-established Table metadata. 
"""
from sqlalchemy import create_engine, text, bindparam, String, select
conn = create_engine("").connect()

stmt = text("SELECT * FROM students WHERE students.name BETWEEN :x AND :y")

stmt = stmt.bindparams(
   bindparam("x", type_= String), 
   bindparam("y", type_= String)
)

result = conn.execute(stmt, {"x": "A", "y": "L"})
s = select([text("students.name, students.lastname from students")]).where(text("students.name between :x and :y"))
conn.execute(s, x = 'A', y = 'L').fetchall()