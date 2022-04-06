"""
SQLAlchemy allows us to compose SQL expressions, such as "name = 'squidward'" or "user_id > 10", by making use of standard Python operators in conjunction with Column and similar objects. For boolean expressions, most Python operators such as ==, !=, <, >= etc. generate new SQL Expression objects, rather than plain boolean True/False values:

>>> print(user_table.c.name == 'squidward')
user_account.name = :name_1

>>> print(address_table.c.user_id > 10)
address.user_id > :user_id_1

>>> print(select(user_table).where(user_table.c.name == 'squidward'))

“AND” and “OR” conjunctions are both available directly using the and_() and or_() functions, illustrated below in terms of ORM entities:

from sqlalchemy import and_, or_
print(
    select(Address.email_address).
    where(
        and_(
            or_(User.name == 'squidward', User.name == 'sandy'),
            Address.user_id == User.id
        )
    )
)

"""
