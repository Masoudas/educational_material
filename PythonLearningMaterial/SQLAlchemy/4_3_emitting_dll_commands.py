"""
We’ve constructed a fairly elaborate object hierarchy to represent two database tables, starting at the root MetaData object, then into two Table objects, each of which hold onto a collection of Column and Constraint objects. This object structure will be at the center of most operations we perform with both Core and ORM going forward.

The first useful thing we can do with this structure will be to emit CREATE TABLE statements, or DDL, to our SQLite database so that we can insert and query data from them. We have already all the tools needed to do so, by invoking the MetaData.create_all() method on our MetaData, sending it the Engine that refers to the target database:

>>> metadata_obj.create_all(engine)
BEGIN (implicit)
PRAGMA main.table_...info("user_account")
...
PRAGMA main.table_...info("address")
...
CREATE TABLE user_account (
    id INTEGER NOT NULL,
    name VARCHAR(30),
    fullname VARCHAR,
    PRIMARY KEY (id)
)
...
CREATE TABLE address (
    id INTEGER NOT NULL,
    user_id INTEGER NOT NULL,
    email_address VARCHAR NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY(user_id) REFERENCES user_account (id)
)
...
COMMIT

Me: Do we need to commit this? No. As the above example shows, the COMMIT is generated automatically for us. But it's not quite clear to me whether this is just for sqlite or not.

Why do we use create all?
The create process also takes care of emitting CREATE statements in the correct order; above, the FOREIGN KEY constraint is dependent on the user table existing, so the address table is created second. In more complicated dependency scenarios the FOREIGN KEY constraints may also be applied to tables after the fact using ALTER.

"""
