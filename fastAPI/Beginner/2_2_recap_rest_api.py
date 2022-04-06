"""
"Operation" here refers to one of the HTTP "methods".

One of:
    -   POST
    -   GET
    -   PUT
    -   DELETE

...and the more exotic ones:
    -   OPTIONS
    -   HEAD
    -   PATCH
    -   TRACE

In the HTTP protocol, you can communicate to each path using one (or more) of these "methods". When building APIs, you normally use these specific HTTP methods to perform a specific action.

Normally you use:

    -   POST: to create data.
    -   GET: to read data.
    -   PUT: to update data.
    -   DELETE: to delete data.

So, in OpenAPI, each of the HTTP methods is called an "operation". We are going to call them "operations" too.

You are free to use each operation (HTTP method) as you wish. FastAPI doesn't enforce any specific meaning. The information here is presented as a guideline, not a requirement. For example, when using GraphQL you normally perform all the actions using only POST operations.
"""
