"""
Me: Aliases are alternative names we give to tables and subquerries (and columns. Although for columns, we use labels in sqlalchemy). There's one thing reanming a querry:

SELECT CustomerName, Address + ', ' + PostalCode + ' ' + City + ', ' + Country AS Address
FROM Customers;
# or mysql
SELECT CustomerName, CONCAT(Address,', ',PostalCode,', ',City,', ',Country) AS Address
FROM Customers;

But more importantly, we may have to for example join a table with itself. In such a case, we need to use alias names for the table, so that they're not mixed with each other. Otherwise, how's a querry to understand we're talking about two different tables? The answer is (abo tai!) that in the from clause, we can define aliases:

SELECT a.id, a.name, b.id, b.name FROM user_table AS a, user_table AS b
 
"""
