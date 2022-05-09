"""
Recall that we may define dicts with arbitrary types as a body parameter. In this case, you would accept any dict as long as it has int keys with float values:

Me: Here's something to think about. Why is this not a query param, but rather a body param? Just because the method is post? So, I added the q parameter to understand why fastapi considers weights to be a body parameter. This is because it's a DICTINARY. We see in the docs that q is considered a query parameter rather.

Me: So, how can I understand this from the openapi docs? Simple. Notice that it shows both q, and then below it says 'Request body (required)'. Also notice that when sending the request, I have to use quotation marks when creating the json request. That is, I have to say:

{
    "1": 1.1
}
This all but makes sense, because a json has to have string keys. However, inside the function, it's converted to int.

Have in mind that JSON only supports str as keys. But Pydantic has automatic data conversion.

This means that, even though your API clients can only send strings as keys, as long as those strings contain pure integers, Pydantic will convert them and validate them. And the dict you receive as weights will actually have int keys and float values.
"""
from fastapi import FastAPI

app = FastAPI()


@app.post("/index-weights/")
async def create_index_weights(weights: dict[int, float], q: str):
    return weights  # Converts directly to str keys when converting to json.
