"""
A database transaction symbolizes a unit of work performed within a database management system (or similar system) against a database, and treated in a coherent and reliable way independent of other transactions. A transaction generally represents any change in a database. Transactions in a database environment have two main purposes:

    -   To provide reliable units of work that allow correct recovery from failures and keep a database consistent even in cases of system failure, when execution prematurely and unexpectedly stops (completely or partially) and many operations upon a database remain uncompleted, with unclear status.
    -   To provide isolation between programs accessing a database concurrently. If this isolation is not provided, the programs' outcomes are possibly erroneous.

In a database management system, a transaction is a single unit of logic or work, sometimes made up of multiple operations. Any logical calculation done in a consistent mode in a database is known as a transaction. One example is a transfer from one bank account to another: the complete transaction requires subtracting the amount to be transferred from one account and adding that same amount to the other.

Me: And transactions must end with a commit to actually make changes in a database. Otherwise, they're just manipulations without effects (like viewing)
"""
