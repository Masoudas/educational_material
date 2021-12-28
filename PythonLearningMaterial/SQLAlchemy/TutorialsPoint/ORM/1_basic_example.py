from sqlalchemy import Column, Integer, String
from sqlalchemy import create_engine
from sqlalchemy.ext.declarative import declarative_base

engine = create_engine('sqlite:///sales.db', echo = True)
Base = declarative_base()

class Customers(Base):
   __tablename__ = 'customers'
   id = Column(Integer, primary_key=True)

   name = Column(String)
   address = Column(String)
   email = Column(String)

Base.metadata.create_all(engine)

from sqlalchemy.orm import sessionmaker
Session = sessionmaker(bind = engine)
session = Session()

c1 = Customers(name = 'Ravi Kumar', address = 'Station Road Nanded', email = 'ravi@gmail.com')
c2 = Customers(name = 'Kumar', address = 'Station Road Nanded', email = 'ravi@gmail.com')

session.add(c1)
session.add(c2)
session.commit()


result = session.query(Customers).all()