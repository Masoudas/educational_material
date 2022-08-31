import os
import secrets

from fastapi import FastAPI, Depends, HTTPException, status
from fastapi.security import HTTPBasic, HTTPBasicCredentials

security = HTTPBasic()


def authorize(credentials: HTTPBasicCredentials = Depends(security)):
    is_user_ok = secrets.compare_digest(credentials.username, "1")
    is_pass_ok = secrets.compare_digest(credentials.password, "1")

    if not (is_user_ok and is_pass_ok):
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail='Incorrect email or password.',
            headers={'WWW-Authenticate': 'Basic'},
        )


app = FastAPI(openapi_url="/api/access/openapi.json",
              docs_url="/api/access/docs")


@app.get('/api/access/auth', dependencies=[Depends(authorize)])
def auth():
    return {"Granted": True}
