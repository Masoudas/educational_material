"""
We may also use the and_ function to and conditions.
"""

from sqlalchemy import and_, text
from sqlalchemy.sql import select
s = select([text("* from students")]) \
.where(
   and_(
      text("students.name between :x and :y"),
      text("students.id>2")
   )
)
