"""
The same way, you can declare optional query parameters, by setting their default to None:
Moreover, you can declare boolean parameters as well. Also, notice how the path parameters are placed before query parameters, allowing us to use both. Notice that we put the question mark right after the path parameter.

Notice the following queries:
http://127.0.0.1:8000/items/foo?short=1
http://127.0.0.1:8000/items/foo?short=true

ME: So, what I was thinking about this morning is this. You mustn't check for existence of body params. If they don't have a default value, that means they have to be supplied and if not, then fastapi throws an error message.
"""
from typing import Optional

from fastapi import FastAPI

app = FastAPI()


@app.get("/items/{item_id}")
async def read_item(item_id: str, q: Optional[str] = None, short: bool = False):
    if q:
        return {"item_id": item_id, "q": q}
    return {"item_id": item_id}
