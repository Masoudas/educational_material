from typing import Optional

from fastapi import FastAPI, Header, Response
from starlette.status import HTTP_200_OK, HTTP_401_UNAUTHORIZED

app = FastAPI()


@app.post("/login/")
def login(
    authorization: Optional[str] = Header(None)
) -> Response:
    if authorization == "a":
        return Response(status_code=HTTP_200_OK)
    return Response(status_code=HTTP_401_UNAUTHORIZED)
