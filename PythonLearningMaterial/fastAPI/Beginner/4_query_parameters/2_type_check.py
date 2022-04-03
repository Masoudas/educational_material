"""
...the query parameters in the previous example are:

    -   skip: with a value of 0
    -   limit: with a value of 10
As they are part of the URL, they are "naturally" strings.

But when you declare them with Python types (in the example above, as int), they are converted to that type and validated against it.

All the same process that applied for path parameters also applies for query parameters:

    -   Editor support (obviously)
    -   Data "parsing"
    -   Data validation
    -   Automatic documentation
"""
