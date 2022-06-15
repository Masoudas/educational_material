"""
Now we are going to update our dependencies. We want to get the current_user only if this user is active. So, we create an additional dependency `get_current_active_user` that in turn uses `get_current_user` as a dependency.

Both of these dependencies will just return an HTTP error if the user doesn't exist, or if is inactive.

So, in our endpoint, we will only get a user if the user exists, was correctly authenticated, and is active:

Note:
The additional header WWW-Authenticate with value Bearer we are returning here is also part of the spec. Any HTTP (error) status code 401 "UNAUTHORIZED" is supposed to also return a WWW-Authenticate header. In the case of bearer tokens (our case), the value of that header should be Bearer. You can actually skip that extra header and it would still work. But it's provided here to be compliant with the specifications. Also, there might be tools that expect and use it (now or in the future) and that might be useful for you or your users, now or in the future. That's the benefit of standards.
"""
