"""
OAuth2PasswordRequestForm is a class dependency that declares a form body with:
    -   The username.
    -   The password.
An optional scope field as a big string, composed of strings separated by spaces.
An optional grant_type.
    -   An optional client_id (we don't need it for our example).
    -   An optional client_secret (we don't need it for our example).

Tip:
    -   The OAuth2 spec actually requires a field grant_type with a fixed value of password, but OAuth2PasswordRequestForm doesn't enforce it. If you need to enforce it, use OAuth2PasswordRequestFormStrict instead of OAuth2PasswordRequestForm.

Info:
The OAuth2PasswordRequestForm is not a special class for FastAPI as is OAuth2PasswordBearer.
OAuth2PasswordBearer makes FastAPI know that it is a security scheme. So it is added that way to OpenAPI. But OAuth2PasswordRequestForm is just a class dependency that you could have written yourself, or you could have declared Form parameters directly.

But as it's a common use case, it is provided by FastAPI directly, just to make it easier.
"""
