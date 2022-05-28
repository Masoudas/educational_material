"""
It receives the same type you would declare for a Pydantic model attribute, so, it can be a  Pydantic model, but it can also be, e.g. a list of Pydantic models, like List[Item].

FastAPI will use this response_model to:
    -   Convert the output data to its type declaration.
    -   Validate the data.
    -   Add a JSON Schema for the response, in the OpenAPI path operation.
    -   Will be used by the automatic documentation systems.

But most importantly:
    -   Will limit the output data to that of the model.
"""
