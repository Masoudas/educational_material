"""
-   Is a message sent when establishing the connection? In other words, when we 'accept' the connection, does the connection establishment message (whatever it is) have a payload?
* No. The connection establishment is a low-level protocol process, and no message is conveyed. We need to receive data by explicitly calling the receive method.

-   Image we receive some data, and then we want to send some data back to the client. When is the write event initiated? 
*   From what I understand, the logic is that we first use the send function of socket, then an event is fired when the socket is ready for a write event. The point is that using the send (or send_all function) fi

- How do we ensure that under connection failure, we don't get the "address already in use error"?
"""