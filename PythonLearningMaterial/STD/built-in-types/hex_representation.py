"""
These snippets are from me, taken from various parts of std.

An int has a to_bytes method. 
(1024).to_bytes(2, byteorder='big')
b'\x04\x00'

Now, what does the result mean? It means a hexadecimal representation in a binary string. It implies that what's under the hood stored for this string is indeed 0x04 in hex format. Hence, if I decode it to a string, then it would be the equivalent char. Note that b'04' is not a hex string. This would be the literals 0 and 4 stored under the hood as bytes. Note that the hex method on b'\x04\x00' indeed returns 0400
"""
print(b'\x04\x00'.hex())
