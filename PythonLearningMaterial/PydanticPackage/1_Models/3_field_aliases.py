"""
We can use alaises to rename a field, and give a field name in the background. This is useful if the 
field should be accessed by our programs in one way, and for example by a database in another way, as the
following example demonstrates.

Note that when we do so, the field in the class initializer has the alias name, but it can be accessed and played
with only with the original name. This is to allow construction by alias name in other classes.

What we're doing is we're turning an SQL server field into a DataClass of our own.
"""

from pydantic import BaseModel
from pydantic.fields import Field

class Data(BaseModel):
    name: str = Field(alias='name_')
    
    def using_name_(self):
        print(self.name)

data = Data(name_="Masoud") 

print(data.name)	# Property accessible by original name
data.dict(by_alias=True)	# Dictionary by alias names (so uses 'name_').
data.using_name_()

## More complex example:
import typing

import sqlalchemy as sa
from sqlalchemy.ext.declarative import declarative_base


class MyModel(BaseModel):
    metadata: typing.Dict[str, str] = Field(alias='metadata_')

    class Config:
        orm_mode = True


BaseModel = declarative_base()


class SQLModel(BaseModel):
    __tablename__ = 'my_table'
    id = sa.Column('id', sa.Integer, primary_key=True)
    # 'metadata' is reserved by SQLAlchemy, hence the '_'
    metadata_ = sa.Column('metadata', sa.JSON)


sql_model = SQLModel(metadata_={'key': 'val'}, id=1)

pydantic_model = MyModel.from_orm(sql_model)

print(pydantic_model.dict())
#> {'metadata': {'key': 'val'}}
print(pydantic_model.dict(by_alias=True))
#> {'metadata_': {'key': 'val'}}