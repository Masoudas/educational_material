"""
As individual row-fetch operations with fully unbuffered server side cursors are typically more expensive than fetching batches of rows at once, The Connection.execution_options.yield_per execution option configures a Connection or statement to make use of server-side cursors as are available, while at the same time configuring a fixed-size buffer of rows that will retrieve rows from the server in batches as they are consumed. This parameter may be set to a positive integer value using the Connection.execution_options() method on Connection or on a statement using the Executable.execution_options() method.

with engine.connect() as conn:
    with conn.execution_options(yield_per=100).execute(
        text("select * from table")
    ) as result:
        for partition in result.partitions():
            # partition is an iterable that will be at most 100 items
            for row in partition:
                print(f"{row}")

Using this option is equivalent to manually setting the Connection.execution_options.stream_results option, described in the next section, and then invoking the Result.yield_per() method on the Result object with the given integer value. In both cases, the effect this combination has includes:

    -   server side cursors mode is selected for the given backend, if available and not already the default behavior for that backend

    -   as result rows are fetched, they will be buffered in batches, where the size of each batch up until the last batch will be equal to the integer argument passed to the Connection.execution_options.yield_per option or the Result.yield_per() method; the last batch is then sized against the remaining rows fewer than this size

    -   The default partition size used by the Result.partitions() method, if used, will be made equal to this integer size as well.

The above example illustrates the combination of yield_per=100 along with using the Result.partitions() method to run processing on rows in batches that match the size fetched from the server. The use of Result.partitions() is optional, and if the Result is iterated directly, a new batch of rows will be buffered for each 100 rows fetched. Calling a method such as Result.all() should not be used, as this will fully fetch all remaining rows at once and defeat the purpose of using yield_per. 
"""
