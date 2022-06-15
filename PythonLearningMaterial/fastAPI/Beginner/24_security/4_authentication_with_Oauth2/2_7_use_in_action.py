"""
To use authorization in action. Click the "Authorize" button in the docs.

After punching in the username and password, you can see your user data with the get method, which in this case would be:
{
  "username": "johndoe",
  "email": "johndoe@example.com",
  "full_name": "John Doe",
  "disabled": false,
  "hashed_password": "fakehashedsecret"
}

If you click the lock icon and logout, and then try the same operation again, you will get an HTTP 401 error of:

Inactive password:
Now try with an inactive user, authenticate with:

    -   User: alice
    -   Password: secret2

And try to use the operation GET with the path /users/me. You will get an "inactive user" error, like:
{
  "detail": "Inactive user"
}
"""
