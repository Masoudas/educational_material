"""
For optional arguments, we may use Optional annotation. Optional implies Union[Type, None]
"""
from typing import Optional

def has_optional(v1 : int, opt: Optional[str] = "This is optional"):
    return None