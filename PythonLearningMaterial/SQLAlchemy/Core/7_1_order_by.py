"""
Select function has an order by method. Moreover, columns themselves have ascending and descending methods, as the following example demonstrates.

print(select(User).order_by(User.fullname.desc()))
SELECT user_account.id, user_account.name, user_account.fullname
FROM user_account ORDER BY user_account.fullname DESC

https://docs.sqlalchemy.org/en/14/tutorial/data_select.html
"""
