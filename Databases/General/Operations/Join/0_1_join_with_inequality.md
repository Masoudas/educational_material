Consider the following join of tables, and interpret it:

**Example1**

Table A         
ID_1    Start   End Name
137 1:00    2:00    Galia
137 2:00    3:00    Est
137 3:00    4:00    Omnia
137 4:00    5:00    Divisa
137 5:00    6:00    Partes
137 6:00    7:00    Tres
137 7:00    8:00    Quarum
137 8:00    9:00    Unam
137 9:00    10:00   Incolunt

Table B     
ID_1Time_1  Time_2
137 3:10    3:57

select A.*, B.Time_1, B.Time_2
from Table_A A
inner join
Table_B B
on 
A.ID_1 = B.ID_1 and B.Time_1<=A.End and B.Time_2 >= A.Start

Well. We join to elements of table B, where time_1 is less than End and time_2 is greater than Start. So, when we iterate over each row, we compare it to all the columns of table B. So, whichever row satisfies this constraint, then that row is selected. The point I'm making is that joins are cartesian products. As such, we can have N*M elements, where N is the size of table 1, and M is the size of table 2. Because normally, I see joins with equality constraints, and in those joins, normally, the size of inner join does not exceed N, which is the size of the left table. Here, however, we are reminded that the size of join is in fact N*M.

**Example 2**

SELECT user_account_1.name, user_account_2.name AS name_1
FROM user_account AS user_account_1
JOIN user_account AS user_account_2 ON user_account_1.id > user_account_2.id

Again, we note that the result is in fact M*M, and not M with this join. Each name of table 1 is paired with all the names of table 2 that have ids less than its id.