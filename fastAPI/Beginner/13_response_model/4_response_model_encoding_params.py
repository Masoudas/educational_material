"""
Our response model may have default values. For example, if you have models with many optional attributes in a NoSQL database, but you don't want to send very long JSON responses full of default values.

You can set the path operation decorator parameter response_model_exclude_unset=True, and those default values won't be included in the response, only the values actually set.

Me: Exclude unset actualy excludes those values for which we did not set any data, but have a default value. Notice that we mean those parameters that have default, but are not set when we create the model. Notice that if we set a parameter to another value that's equal to its default, pydantic is smart enough to realize that we're resetting it. Then, it would include that parameter in the response.

So, if you send a request to that path operation for the item with ID foo, the response (not including default values) will be:

{
    "name": "Foo",
    "price": 50.2
}

You can also use:

    -   response_model_exclude_defaults=True
    -   response_model_exclude_none=True

as described in the Pydantic docs for exclude_defaults and exclude_none.
"""
from typing import Union

from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()


class Item(BaseModel):
    name: str
    description: Union[str, None] = None
    price: float
    tax: float = 10.5
    tags: list[str] = []


items = {
    "foo": {"name": "Foo", "price": 50.2},
    "bar": {"name": "Bar", "description": "The bartenders", "price": 62, "tax": 20.2},
    "baz": {"name": "Baz", "description": None, "price": 50.2, "tax": 10.5, "tags": []},
}


@app.get("/items/{item_id}", response_model=Item, response_model_exclude_unset=True)
async def read_item(item_id: str):
    return items[item_id]
