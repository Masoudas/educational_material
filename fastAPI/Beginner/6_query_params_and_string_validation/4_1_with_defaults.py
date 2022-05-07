"""
We may also request a list of params with a defualt, as the following example demonstrates.

"""
from typing import List, Optional

from fastapi import FastAPI, Query

app = FastAPI()


@app.get("/items/")
async def read_items(q: Optional[List[str]] = Query(["v1", "v2"])):
    query_items = {"q": q}
    return query_items
