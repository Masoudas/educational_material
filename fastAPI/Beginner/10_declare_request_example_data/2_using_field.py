"""
We may also do the same with Field. That is, we may define example for the particular parameter (Me: This looks to be a better approach as well.)
"""
from fastapi import FastAPI
from pydantic import BaseModel, Field
from typing import Optional
app = FastAPI()


class Item(BaseModel):
    name: str = Field(example="Foo")
    description: Optional[str] = Field(
        default=None, example="A very nice Item")
    price: float = Field(example=35.4)
    tax: Optional[float] = Field(default=None, example=3.2)


@app.put("/items/{item_id}")
async def update_item(item_id: int, item: Item):
    results = {"item_id": item_id, "item": item}
    return results
