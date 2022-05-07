"""
Import Enum and create a sub-class that inherits from str and from Enum.

By inheriting from str the API docs will be able to know that the values must be of type string and will be able to render correctly.

Then create class attributes with fixed values, which will be the available valid values.

Notice that if we check the docs, we see that the enumeration values appear there, which is very cool!

NOTE: You can return enum members from your path operation, even nested in a JSON body 
(e.g. a dict.) They will be converted to their corresponding values (strings in this case) before returning them to the client. This is what we've done in the return statement. (Me: And I assume if we do the same with pydantic classes, the same would happen there as well.)
"""
from enum import Enum
from fastapi import FastAPI


class ModelName(str, Enum):
    alexnet = "alexnet"
    resnet = "resnet"
    lenet = "lenet"


app = FastAPI()


@app.get("/models/{model_name}")
async def get_model(model_name: ModelName):
    if model_name == ModelName.alexnet:
        return {"model_name": model_name, "message": "Deep Learning FTW!"}

    if model_name.value == "lenet":
        return {"model_name": model_name, "message": "LeCNN all the images"}

    return {"model_name": model_name, "message": "Have some residuals"}
