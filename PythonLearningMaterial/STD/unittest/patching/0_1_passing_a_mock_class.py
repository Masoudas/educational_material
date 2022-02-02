"""
This scenario mocks the type as well, so that isinstance is also tricked into accepting the type,
"""
# a.py
from unittest import TestCase, mock


class B:
    pass


class A:
    def my_method(self, name: B):
        pass


# test.py
class MockB:
    pass


class Test(TestCase):
    @mock.patch("__main__.B", MockB, spec=True)
    def test_my_method(self):
        b = MockB()
        # This raises a beartype exception
        A().my_method(b)
