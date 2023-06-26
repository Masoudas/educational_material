"""
This is all me:

A hex string is the ascii or possibily utf8 equivalent of a string. To decode this as the original string in python, we should recall that a binary string is the equivalent of this string. To do this, we first create the binary string for the hex value. This is done, using the fromhex method of bytes class. (Note that we can't simply say b'0x124', because this would convert the literal expression 0x124 to the ascii binary representation.) Then, once we have the byte array representation, we can decode it using a format like utf-8, or whatever. 

One thing to note is that fromhex requires a string as input. 
"""

x = 0x43 #
print(bytes.fromhex(str(x)).decode())