"""
At this point we have the user data from our database, but we haven't checked the password. Let's put that data in the Pydantic UserInDB model first.

You should never save plaintext passwords, so, we'll use the (fake) password hashing system. If the passwords don't match, we return the same error.
"""
