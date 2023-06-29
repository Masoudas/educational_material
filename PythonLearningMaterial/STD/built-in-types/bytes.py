"""
Firstly, the syntax for bytes literals is largely the same as that for string literals, except that a b prefix is added:

    -   Single quotes: b'still allows embedded "double" quotes'
    -   Double quotes: b"still allows embedded 'single' quotes"
    -   Triple quoted: b'''3 single quotes''', 

Only ASCII characters are permitted in bytes literals (regardless of the declared source code encoding). Any binary values over 127 must be entered into bytes literals using the appropriate escape sequence.

As with string literals, bytes literals may also use a r prefix to disable processing of escape sequences. See String and Bytes literals for more about the various forms of bytes literal, including supported escape sequences.

While bytes literals and representations are based on ASCII text, bytes objects actually behave like immutable sequences of integers, with each value in the sequence restricted such that 0 <= x < 256 (attempts to violate this restriction will trigger ValueError). This is done deliberately to emphasise that while many binary formats include ASCII based elements and can be usefully manipulated with some text-oriented algorithms, this is not generally the case for arbitrary binary data (blindly applying text processing algorithms to binary data formats that are not ASCII compatible will usually lead to data corruption).

In addition to the literal forms, bytes objects can be created in a number of other ways:

    -   A zero-filled bytes object of a specified length: bytes(10)
    -   From an iterable of integers: bytes(range(20))
    -   Copying existing binary data via the buffer protocol: bytes(obj)

Since 2 hexadecimal digits correspond precisely to a single byte, hexadecimal numbers are a commonly used format for describing binary data. Accordingly, the bytes type has an additional class method to read data in that format. Since bytes objects are sequences of integers (akin to a tuple), for a bytes object b, b[0] will be an integer, while b[0:1] will be a bytes object of length 1. (This contrasts with text strings, where both indexing and slicing will produce a string of length 1)

    -   classmethod fromhex(string)
    This bytes class method returns a bytes object, decoding the given string object. The string must contain two hexadecimal digits per byte, with ASCII whitespace being ignored.

    >>> bytes.fromhex('2Ef0 F1f2  ')
    b'.\xf0\xf1\xf2'

    Me: Why is 2E converted to .? I guess numbers below 127 are converted to their ascii represenation when printing.

    Me: Also note that bytes.fromhex('2Ef0 F1f2  ')[1] of the above string prints 240, which is expected.

    -   classmethod hex([sep[, bytes_per_sep]])
    Return a string object containing two hexadecimal digits for each byte in the instance.

    >>> b'\xf0\xf1\xf2'.hex()
    'f0f1f2'

Me: An important note is that if a bytes types can't show the the value in ascii, then it will show it in hex, which is something very odd. Imagine someone sends me a byte string as 0x2e0xf0. Now, because 2e is equivalent to a single dot, then its equivalent ascii is shown. However, f0 does not have an ascii equivalent (it's greater than 127,) so 0xf0 is shown. Moreover, this binary string can't be decoded as ascii, because the second char is greater than 127. This is why we get:
bytes.fromhex('2ef0') --> prints b".\xf0"
print(b"\x2e\f0") --> prints .\xf0
"""
print(b"\x2e\xf0")
