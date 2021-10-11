"""
Beside the notion of structured binding (assigning to several parameters in a for loop,) the standard states that
"Code that modifies a collection while iterating over that same collection can be tricky to get right. Instead, 
it is usually more straight-forward to loop over a copy of the collection or to create a new collection:"

Me: In particular, in the following example, we're deleting from the middle of the dictionary, which as we know,
is always a problematic function.
"""
users = {}
for user, status in users.copy().items():	
    if status == 'inactive':
        del users[user]

# Strategy:  Create a new collection
active_users = {}
for user, status in users.items():
    if status == 'active':
        active_users[user] = status