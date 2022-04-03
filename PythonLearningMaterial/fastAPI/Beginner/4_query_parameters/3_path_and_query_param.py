"""
We can mix query params and path params together, and fast api is clever enough to detect that. For example. a query would look something like this:

$ /items/my_parameter/?q=my_query
"""

from typing import Optional
from fastapi import FastAPI

app = FastAPI()


@app.get("/items/{item_id}")
async def read_item(item_id: str, q: Optional[str] = None):
    if q:
        return {"item_id": item_id, "q": q}
    return {"item_id": item_id}
