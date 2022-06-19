"""
    -- Get username and password.
OAuth2 specifies that when using the "password flow" (that we are using) the client/user must send a username and password fields as form data.

And the spec says that the fields have to be named like that. So user-name or email wouldn't work.
But don't worry, you can show it as you wish to your final users in the frontend.

And your database models can use any other names you want.

But for the login path operation, we need to use these names to be compatible with the spec (and be able to, for example, use the integrated API documentation system).

The spec also states that the username and password must be sent as form data (so, no JSON here).

    -- scope
The spec also says that the client can send another form field "scope". The form field name is scope (in singular), but it is actually a long string with "scopes" separated by spaces.

Each "scope" is just a string (without spaces). They are normally used to declare specific security permissions, for example:
    -   users:read or users:write are common examples.
    -   instagram_basic is used by Facebook / Instagram.
    -   https://www.googleapis.com/auth/drive is used by Google.

Note: In OAuth2 a "scope" is just a string that declares a specific permission required. It doesn't matter if it has other characters like : or if it is a URL. Those details are implementation specific. For OAuth2 they are just strings.
"""
