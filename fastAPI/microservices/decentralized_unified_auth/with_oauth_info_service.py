from functools import wraps
from typing import Any, Callable, Optional

import requests
from fastapi import FastAPI, Header, Response, Depends
from fastapi.responses import JSONResponse
import uvicorn
from with_oauth_auth_service import get_current_user, get_current_active_user, User

app = FastAPI()

LOGIN_ENDPOINT = "http://0.0.0.0:8102/users/me/items/is_authorized"


def validate(token: str) -> Callable:
    response = requests.post(
        url=LOGIN_ENDPOINT,
        headers={
            "Token": token,
        },
    )
    return response.json()


@app.get("/info/")
async def get_information(
        token: str = Header(...)) -> JSONResponse:
    user = validate(token)
    return user

if __name__ == "__main__":
    uvicorn.run(
        "with_oauth_info_service:app", host="0.0.0.0", reload=True, port=8101, log_level="info")
