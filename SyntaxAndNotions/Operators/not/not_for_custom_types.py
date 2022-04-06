"""
We know that if we overload the bool operator, then in boolean contexts (including None,) the bool operator will be used.

The question is, what happens if the bool operator is not overridden? The answer is (Abo tai!) that in that case, the truth of the variable is checked, and if that variable is None or False, it will return True, otherwise, it returns False.
"""


class C1:
    def __bool__(self):
        return False


class C:
    pass


print(not C1())
print(not C())    # This will return False
