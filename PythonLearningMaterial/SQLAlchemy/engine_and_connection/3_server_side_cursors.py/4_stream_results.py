"""
To enable server side cursors without a specific partition size, the Connection.execution_options.stream_results option may be used, which like Connection.execution_options.yield_per may be called on the Connection object or the statement object.

When a Result object delivered using the Connection.execution_options.stream_results option is iterated directly, rows are fetched internally using a default buffering scheme that buffers first a small set of rows, then a larger and larger buffer on each fetch up to a pre-configured limit of 1000 rows. The maximum size of this buffer can be affected using the Connection.execution_options.max_row_buffer execution option:

with engine.connect() as conn:
    with conn.execution_options(stream_results=True, max_row_buffer=100).execute(
        text("select * from table")
    ) as result:

        for row in result:
            print(f"{row}")

ME: Note that result essentially works like a connection object.
"""
