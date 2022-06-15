"""
It is possible to receive duplicate headers. That means, the same header with multiple values.
You can define those cases using a list in the type declaration.

You will receive all the values from the duplicate header as a Python list.

For example, to declare a header of X-Token that can appear more than once, you can write as shown below.

If you communicate with that path operation sending two HTTP headers like:
#############
X-Token: foo
X-Token: bar
#############

The response would be like:
{
    "X-Token values": [
        "bar",
        "foo"
    ]
}
"""
from typing import List, Union

from fastapi import FastAPI, Header

app = FastAPI()


@app.get("/items/")
async def read_items(x_token: Union[List[str], None] = Header(default=None)):
    return {"X-Token values": x_token}
