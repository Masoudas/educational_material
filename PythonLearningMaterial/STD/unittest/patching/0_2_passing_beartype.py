"""
If we use the patching discussed in example 1, a beartype decorated function still throws, because it uses the __class__ property to check type. We can remedy it by actually overriding this property
"""
# a.py
from unittest import TestCase, mock


class B:
    pass


class A:
    def my_method(self, name: B):
        pass


class MockB:
    @property
    def __class__(self) -> type:
        return B


class Test(TestCase):
    @mock.patch("__main__.B", MockB, spec=True)
    def test_my_method(self):
        b = MockB()
        # This raises a beartype exception
        A().my_method(b)
