"""
It's now easy to see how me serialize a pydantic object. We first, use the to json method to convert it to a
json object, and then dump that object. Then, we can recreate that object from that json object.
"""
from pydantic import BaseModel
import json 

class Data(BaseModel):
	id: int = 10 

# Serialization
json_str = Data().json() 
json_str_serializable = json.dumps(json_str)	# This one has the \" for quotations, and is not a string. We need to load
									# it to become a string.

# Deserialization
json_str_loaded = json.loads(json_str_serializable)

print(Data.parse_raw(json_str_loaded))