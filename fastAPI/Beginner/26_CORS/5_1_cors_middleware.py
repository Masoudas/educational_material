"""
You can configure it in your FastAPI application using the CORSMiddleware.
    -   Import CORSMiddleware.
    -   Create a list of allowed origins (as strings).
    -   Add it as a "middleware" to your FastAPI application.

You can also specify if your backend allows:
    -   Credentials (Authorization headers, Cookies, etc).
    -   Specific HTTP methods (POST, PUT) or all of them with the wildcard "*".
    -   Specific HTTP headers or all of them with the wildcard "*".
"""
from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware

app = FastAPI()

origins = [
    "http://localhost.tiangolo.com",
    "https://localhost.tiangolo.com",
    "http://localhost",
    "http://localhost:8080",
]

app.add_middleware(
    CORSMiddleware,
    allow_origins=origins,
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)


@app.get("/")
async def main():
    return {"message": "Hello World"}
