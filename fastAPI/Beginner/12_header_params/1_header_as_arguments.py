"""
You can define Header parameters the same way you define Query, Path and Cookie parameters.

Then declare the header parameters using the same structure as with Path, Query and Cookie.
The first value is the default value, you can pass all the extra validation or annotation parameters:

Note: To declare headers, you need to use Header, because otherwise the parameters would be interpreted as query parameters.
"""

from typing import Union

from fastapi import FastAPI, Header

app = FastAPI()


@app.get("/items/")
async def read_items(user_agent: Union[str, None] = Header(default=None)):
    return {"User-Agent": user_agent}
