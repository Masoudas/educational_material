"""
The same way you can specify a response model, you can also declare the HTTP status code used for the response with the parameter status_code in any of the path operations:

    -   @app.get()
    -   @app.post()
    -   @app.put()
    -   @app.delete()
etc.
"""
from fastapi import FastAPI

app = FastAPI()


@app.post("/items/", status_code=201)
async def create_item(name: str):
    return {"name": name}
