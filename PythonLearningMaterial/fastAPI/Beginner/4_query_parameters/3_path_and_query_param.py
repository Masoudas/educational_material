"""
We can mix query params and path params together, and fast api is clever enough to detect that. For example. a query would look something like this:

$ /items/my_parameter/?q=my_query

Note that when you want to make a query parameter required, you can just not declare any default value. As such, it must be a part of the query. For example below, if I don't send a value for q, I'll get the following error:
{
    "detail": [
        {
            "loc": [
                "query",
                "q"
            ],
            "msg": "field required",
            "type": "value_error.missing"
        }
    ]
}

"""

from typing import Optional
from fastapi import FastAPI

app = FastAPI()


@app.get("/items/{item_id}")
async def read_item(item_id: str, q: str = None):
    if q:
        return {"item_id": item_id, "q": q}
    return {"item_id": item_id}
