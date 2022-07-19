"""
Import TestClient (comes from starlette). Create a TestClient by passing your FastAPI application to it. Create functions with a name that starts with test_ (this is standard pytest conventions). Use the TestClient object the same way as you do with requests. Write simple assert statements with the standard Python expressions that you need to check (again, standard pytest).

Notice that the testing functions are normal def, not async def. And the calls to the client are also normal calls, not using await. This allows you to use pytest directly without complications
"""
from fastapi import FastAPI
from fastapi.testclient import TestClient

app = FastAPI()


@app.get("/")
async def read_main():
    return {"msg": "Hello World"}


client = TestClient(app)


def test_read_main():
    response = client.get("/")
    assert response.status_code == 200
    assert response.json() == {"msg": "Hello World"}
