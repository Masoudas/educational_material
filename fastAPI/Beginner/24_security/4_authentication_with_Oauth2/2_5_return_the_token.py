"""
The response of the token endpoint must be a JSON object.

It should have a token_type. In our case, as we are using "Bearer" tokens, the token type should be "bearer". And it should have an access_token, with a string containing our access token.

For this simple example, we are going to just be completely insecure and return the same username as the token.

----
By the spec, you should return a JSON with an access_token and a token_type, the same as in this example. This is something that you have to do yourself in your code, and make sure you use those JSON keys.

It's almost the only thing that you have to remember to do correctly yourself, to be compliant with the specifications.

For the rest, FastAPI handles it for you.
"""