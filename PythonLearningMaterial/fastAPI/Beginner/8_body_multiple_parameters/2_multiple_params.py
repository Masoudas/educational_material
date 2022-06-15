"""
The same way we can have multiple path params, and multiple request params (or even a list for request params,) we can have multiple request body params. 

Here's a request without the body params:
{
    "name": "Foo",
    "description": "The pretender",
    "price": 42.0,
    "tax": 3.2
}

Here's what the request's json would look like. Notice that even though the item was declared the same way as before, it is now expected to be inside of the body with a key item. FastAPI will do the automatic conversion from the request, so that the parameter item receives it's specific content and the same for user. (Me: I think this means that we needn't define item and user as the name of the function arguments):
{
    "item": {
        "name": "Foo",
        "description": "The pretender",
        "price": 42.0,
        "tax": 3.2
    },
    "user": {
        "username": "dave",
        "full_name": "Dave Grohl"
    }
}

"""

from typing import Optional

from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()


class Item(BaseModel):
    name: str
    description: Optional[str] = None
    price: float
    tax: Optional[float] = None


class User(BaseModel):
    username: str
    full_name: Optional[str] = None


@app.put("/items/{item_id}")
async def update_item(item_id: int, item: Item, user: User):
    results = {"item_id": item_id, "item": item, "user": user}
    return results
