"""
The required headers, or sub-headers, in the protocol header’s dictionary are as follows:

    Name	                    Description
    byteorder	        The byte order of the machine (uses sys.byteorder). This may not be required for your application.
    content-length	    The length of the content in bytes.
    content-type	    The type of content in the payload, for example, text/json or binary/my-binary-type.
    content-encoding	The encoding used by the content, for example, utf-8 for Unicode text or binary for binary data.

These headers inform the receiver about the content in the payload of the message. This allows you to send arbitrary data while providing enough information so that the content can be decoded and interpreted correctly by the receiver. Because the headers are in a dictionary, it’s easy to add additional headers by inserting key-value pairs as needed.    

There’s still a bit of a problem. You have a variable-length header, which is nice and flexible, but how do you know the length of the header when reading it with .recv()?

When you previously learned about using .recv() and message boundaries, you also learned that fixed-length headers can be inefficient. That’s true, but you’re going to use a small, 2-byte, fixed-length header to prefix the JSON header that contains its length.

You can think of this as a hybrid approach to sending messages. In effect, you’re bootstrapping the message receive process by sending the length of the header first. This makes it easy for your receiver to deconstruct the message.

To give you a better idea of the message format, check out a message in its entirety in the message image. A message starts with a fixed-length header of two bytes, which is an integer in network byte order. This is the length of the next header, the variable-length JSON header. Once you’ve read two bytes with .recv(), then you know you can process the two bytes as an integer and then read that number of bytes before decoding the UTF-8 JSON header.

The JSON header contains a dictionary of additional headers. One of those is content-length, which is the number of bytes of the message’s content (not including the JSON header). Once you’ve called .recv() and read content-length bytes, then you’ve reached a message boundary, meaning you’ve read an entire message.
"""