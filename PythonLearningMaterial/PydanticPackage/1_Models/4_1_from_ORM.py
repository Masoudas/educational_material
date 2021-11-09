"""
Recall that ORM implies Object Relational Model (like xml, etc.).

The docs say "Pydantic models can be created from arbitrary class instances to support models that map to 
ORM objects."

To do this:
	-	The Config property orm_mode must be set to True.
	-	The special constructor from_orm must be used to create the model instance.


"""
from typing import List
from sqlalchemy import Column, Integer, String
from sqlalchemy.dialects.postgresql import ARRAY
from sqlalchemy.ext.declarative import declarative_base
from pydantic import BaseModel, constr

Base = declarative_base()

# Creating an ORM as columns of a particular company.
class CompanyOrm(Base):
    __tablename__ = 'companies'
    id = Column(Integer, primary_key=True, nullable=False)
    public_key = Column(String(20), index=True, nullable=False, unique=True)
    name = Column(String(63), unique=True)
    domains = Column(ARRAY(String(255)))

# The conversion of ORM to our pydantic class
class CompanyModel(BaseModel):
    id: int
    public_key: constr(max_length=20)
    name: constr(max_length=63)
    domains: List[constr(max_length=255)]

    class Config:
        orm_mode = True


co_orm = CompanyOrm(
    id=123,
    public_key='foobar',
    name='Testing',
    domains=['example.com', 'foobar.com'],
)
print(co_orm)
#> <models_orm_mode.CompanyOrm object at 0x7f779fd22ac0>

co_model = CompanyModel.from_orm(co_orm)
print(co_model)
#> id=123 public_key='foobar' name='Testing' domains=['example.com',
#> 'foobar.com']