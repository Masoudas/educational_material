"""
If the client requests http://example.com/items/foo (an item_id "foo"), that client will receive an HTTP status code of 200, and a JSON response of:
'''
{
  "item": "The Foo Wrestlers"
}
'''

But if the client requests http://example.com/items/bar (a non-existent item_id "bar"), that client will receive an HTTP status code of 404 (the "not found" error), and a JSON response of:
'''
{
  "detail": "Item not found"
}
'''

Note that when raising an HTTPException, you can pass any value that can be converted to JSON as the parameter detail, not only str. You could pass a dict, a list, etc.

They are handled automatically by FastAPI and converted to JSON.
"""
