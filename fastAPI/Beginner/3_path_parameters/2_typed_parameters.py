"""
You can declare the type of a path parameter in the function, using standard Python type annotations. The cool thing is that in such a case, if the path is given the wrong type (string below for example,) then fastAPI would return a 404 error with a nice error message:

{
    "detail":[
    {
        "loc":["path","item_id"],
        "msg":"value is not a valid integer",
        "type":"type_error.integer"
        }
    ]
}

NOTE: Again, just with that same Python type declaration, FastAPI gives you automatic, interactive documentation (integrating Swagger UI). Notice that the path parameter is declared to be an integer.
"""
from fastapi import FastAPI

app = FastAPI()


@app.get("/items/{item_id}")
async def read_item(item_id: int):
    return {"item_id": item_id}
