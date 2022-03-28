"""
Me: Matching paths (I assume) is a sensitive topic. The way paths are handled is through the order they're defined in our script. For example, suppose we have two paths:

! /users/me
! /users/{id}

where id is a string. Now, if the first path (with me) is defined second in the code, it will never be handled. Why? Because the first one always matches. So, we must use version II, which is the correct way.

# Version I
from fastapi import FastAPI

app = FastAPI()

@app.get("/users/{user_id}")
async def read_user(user_id: str):
    return {"user_id": user_id}

# Never called!
@app.get("/users/me")
async def read_user_me():
    return {"user_id": "the current user"}



# Version II
from fastapi import FastAPI

app = FastAPI()


@app.get("/users/me")
async def read_user_me():
    return {"user_id": "the current user"}


@app.get("/users/{user_id}")
async def read_user(user_id: str):
    return {"user_id": user_id}

"""
