"""
Notice that when we introduce a dependency (function), what's passed as the arguments of that dependency are like query parameters. 

Me: Consider the following example. A query would be something like this:

/items/?q=something&skip=10&limit=20
"""
from typing import Union

from fastapi import Depends, FastAPI

app = FastAPI()


async def common_parameters(
    q: Union[str, None] = None, skip: int = 0, limit: int = 100
):
    return {"q": q, "skip": skip, "limit": limit}


@app.get("/items/")
async def read_items(commons: dict = Depends(common_parameters)):
    return commons


@app.get("/users/")
async def read_users(commons: dict = Depends(common_parameters)):
    return commons

