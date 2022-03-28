"""
Here's how to handle a simple get request. Notice how simple it is to aynchronize the handler of the requset. As such, we don't have queus for handling requests, and the api becomes responsive. Note, however, that we can define the handler synchronous as well (not async.) Also note that we can return a dict, list, singular values as str, int, etc.

To run the API, simply run the following:
$ cd fastAPI/Beginner/
$ uvicorn 2_1_firstAPI:app --reload
"""
import fastapi

app = fastapi.FastAPI()


@app.get("/")
def root():
    return {"message": "Hello World!"}
