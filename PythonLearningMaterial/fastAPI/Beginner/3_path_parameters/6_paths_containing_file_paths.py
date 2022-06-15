"""
Question is, how can we define paths in the path? 

Let's say you have a path operation with a path /files/{file_path}. But you need file_path itself to contain a path, like home/johndoe/myfile.txt. So, the URL for that file would be something like: /files/home/johndoe/myfile.txt.

OpenAPI doesn't support a way to declare a path parameter to contain a path inside, as that could lead to scenarios that are difficult to test and define. Nevertheless, you can still do it in FastAPI, using one of the internal tools from Starlette.

And the docs would still work, although not adding any documentation telling that the parameter should contain a path.

Using an option directly from Starlette you can declare a path parameter containing a path using a URL like:

! /files/{file_path:path}

You can use it as the following code demonstrates.

NOTE: You could need the parameter to contain /home/johndoe/myfile.txt, with a leading slash (/).
In that case, the URL would be: /files//home/johndoe/myfile.txt, with a double slash (//) between files and home. 

ME: Example
http:/files//home/example.txt
"""
from fastapi import FastAPI

app = FastAPI()


@app.get("/files/{file_path:path}")
async def read_file(file_path: str):
    return {"file_path": file_path}
