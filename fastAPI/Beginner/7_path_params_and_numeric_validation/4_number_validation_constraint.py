"""
With Query and Path (and other's you'll see later) you can declare string constraints, but also number constraints.

Here, with ge=1, item_id will need to be an integer number "greater than or equal" to 1.

The same thing may be done with floats as well (item_id can be a float)
"""

from fastapi import FastAPI, Path

app = FastAPI()


@app.get("/items/{item_id}")
async def read_items(
    *, item_id: int = Path(..., title="The ID of the item to get", gt=0, le=1000),
        q: str):
    results = {"item_id": item_id}
    if q:
        results.update({"q": q})
    return results
