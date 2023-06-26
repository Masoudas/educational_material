"""
process_events() is simple. It can only do two things: call .read() and .write().

This is where managing state comes in. If another method depended on state variables having a certain value, then they would only be called from .read() and .write(). This keeps the logic as simple as possible as events come in on the socket for processing.

You might be tempted to use a mix of some methods that check the current state variables and, depending on their value, call other methods to process data outside .read() or .write(). In the end, this would likely prove too complex to manage and keep up with.

You should definitely modify the class to suit your own needs so that it works best for you, but you’ll probably have the best results if you keep the state checks and the calls to methods that depend on that state to the .read() and .write() methods if possible.

Now look at .read(). This is the server’s version, but the client’s is the same. It just uses a different method name, .process_response() instead of .process_request():
"""