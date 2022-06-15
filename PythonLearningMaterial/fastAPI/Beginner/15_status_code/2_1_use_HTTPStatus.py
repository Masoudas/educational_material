"""
status_code can alternatively also receive an IntEnum, such as Python's http.HTTPStatus

It will:
    -   Return that status code in the response.
    -   Document it as such in the OpenAPI schema (and so, in the user interfaces):
"""
from http import HTTPStatus
