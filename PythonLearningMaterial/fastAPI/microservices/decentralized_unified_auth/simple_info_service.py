from functools import wraps
from typing import Any, Callable, Optional

import requests
from fastapi import FastAPI, Header, Response
from fastapi.responses import JSONResponse

app = FastAPI()

LOGIN_ENDPOINT = "http://0.0.0.0:8001/login/"


def auth_required(func: Callable) -> Callable:
    @wraps(func)
    def wrapper(*args: Any, **kwargs: Any):
        try:
            response = requests.post(
                url=LOGIN_ENDPOINT,
                headers={
                    "Authorization": kwargs["authorization"],
                },
            )
            response.raise_for_status()
            return func(*args, **kwargs)
        except requests.HTTPError as error:
            return Response(
                status_code=error.response.status_code
            )

    return wrapper


@app.get("/info/")
@auth_required
def get_information(
        authorization: Optional[str] = Header(None)) -> JSONResponse:
    return JSONResponse(content={"info": "The answer is 42."})
