"""
In a real application, you probably would have your tests in a different file. And your FastAPI application might also be composed of several files/modules, etc.

Me: The whole thing is to import the FastAPI from the module.

As such, this would be the test module:
###################
from fastapi.testclient import TestClient

from .main import app

client = TestClient(app)


def test_read_main():
    response = client.get("/")
    assert response.status_code == 200
    assert response.json() == {"msg": "Hello World"}
##################
"""
from fastapi import FastAPI

app = FastAPI()


@app.get("/")
async def read_main():
    return {"msg": "Hello World"}
