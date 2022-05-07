"""
The query parameter q is of type Optional[str]. Now, we set a validator for it, to check its length in the query.
"""
from typing import Optional
import fastapi

app = fastapi.FastAPI()


@app.get("/items/")
async def read_items(q: Optional[str] = fastapi.Query(None, min_length=3, max_length=50)):
    results = {"items": [{"item_id": "Foo"}, {"item_id": "Bar"}]}
    if q:
        results.update({"q": q})
    return results
