"""
Me: Here's a simple example of how to use post with fast api. Notice how we use pydantic to create the body of the request.

To add the body to your path operation, declare it the same way you declared path and query parameters as an argument for request.

Results:
With just that Python type declaration, FastAPI will:

    *   Read the body of the request as JSON.
    *   Convert the corresponding types (if needed).
    *   Validate the data.
        -   If the data is invalid, it will return a nice and clear error, indicating exactly where and what was the incorrect data.
    *   Give you the received data in the parameter item.
        -   As you declared it in the function to be of type Item, you will also have all the editor support (completion, etc) for all of the attributes and their types.
    *   Generate JSON Schema definitions for your model, you can also use them anywhere else you like if it makes sense for your project.
    *   Those schemas will be part of the generated OpenAPI schema, and used by the automatic documentation UIs.

Check the swagger docs to see how interesting they are.

Me: Notice that our pydantic model directly converts to a json. As such, we needn't do anything else when we return it from our query handler. As such, the response to this post request is directly returned with the same request body.
"""

from typing import Optional

from fastapi import FastAPI
from pydantic import BaseModel


class Item(BaseModel):
    name: str
    description: Optional[str] = None
    price: float
    tax: Optional[float] = None


app = FastAPI()


@app.post("/items/")
async def create_item(item: Item):
    return item
