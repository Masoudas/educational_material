"""
To exclude a parameter from the documents in openapi, set the parameter include_in_schema of Query to False. 
"""

from typing import Optional

from fastapi import FastAPI, Query

app = FastAPI()


@app.get("/items/")
async def read_items(
        hidden_query: Optional[str] = Query(None, include_in_schema=False)):
    if hidden_query:
        return {"hidden_query": hidden_query}
    else:
        return {"hidden_query": "Not found"}
