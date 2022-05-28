"""
Me: The point is to explicitly declare the type of our response.

You can declare the model used for the response with the parameter response_model in any of the path operations:

    -   @app.get()
    -   @app.post()
    -   @app.put()
    -   @app.delete()
etc.

Note: Notice that response_model is a parameter of the "decorator" method (get, post, etc). Not of your path operation function, like all the parameters and body.

"""
from typing import Union

from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()


class Item(BaseModel):
    name: str
    description: Union[str, None] = None
    price: float
    tax: Union[float, None] = None
    tags: list[str] = []


@app.post("/items/", response_model=Item)
async def create_item(item: Item):
    return item
