"""
Me: What is encoding and decoding of strings? It's the process of getting the binary representation of an string in a particular encoding and back. bytes are decoded, here as strings are encoded to their binary representation.
"""
print("a".encode("utf-16"))
print(b"\xf43f2f1".decode("utf-16"))
