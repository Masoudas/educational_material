"""
You can define Cookie parameters the same way you define Query and Path parameters.

Then declare the cookie parameters using the same structure as with Path and Query.
The first value is the default value, you can pass all the extra validation or annotation parameters:
"""
from typing import Union

from fastapi import Cookie, FastAPI

app = FastAPI()


@app.get("/items/")
async def read_items(ads_id: Union[str, None] = Cookie(default=None)):
    return {"ads_id": ads_id}
