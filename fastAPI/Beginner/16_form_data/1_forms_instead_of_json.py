"""
To receive forms in place of json, we may use Form from fastapi. But notice we need to install form library first:

$ pip install python-multipart

Create form parameters the same way you would for Body or Query.

Form is a class that inherits directly from Body, so everything that applies to body applies here as well.

Me: Form also requires a default value in this case, just like request or body params. Setting it to three dots implies that it's required. Setting it to None means it's not required. Also notice that even though the argument is a Form, it has a type, a string.
"""

from fastapi import FastAPI, Form

app = FastAPI()


@app.post("/login/")
async def login(username: str = Form(...), password: str = Form(None)):
    return {"username": username}
