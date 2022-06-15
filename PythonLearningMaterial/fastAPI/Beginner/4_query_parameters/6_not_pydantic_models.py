"""
Me: This may seem odd to mention here, but query params can't be pydantic models it does appear. Why do I mention this? Becuase we can mix query params with path and request (body) params, and use them all together. If we could use pydantic models as query params, we wouldn't be able to distinguish between query params and request body. 
"""
