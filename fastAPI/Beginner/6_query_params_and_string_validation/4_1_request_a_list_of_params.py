"""
We can ask for several values for a particular parameter. This would be stored in a list, as the following example demonstrates.

http://localhost:8000/items/?q=foo&q=bar

The response to this URL would be something like:
{
  "q": [
    "foo",
    "bar"
  ]
}

"""
from typing import List, Optional

from fastapi import FastAPI, Query

app = FastAPI()


@app.get("/items/")
async def read_items(q: Optional[List[str]] = Query(None)):
    query_items = {"q": q}
    return query_items
