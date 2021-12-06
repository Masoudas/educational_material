"""
Another way unittest takes care of this is through subtests. As the standard docs say:

When there are very small differences among your tests, for instance some parameters, unittest allows you to distinguish them inside the body of a test method using the subTest() context manager.

subTest is inherent to TestCase class.
"""
from unittest import TestCase

class NumbersTest(TestCase):

    def test_even(self):
        """
        Test that numbers between 0 and 5 are all even.
        """
        for i in range(0, 6):
            with self.subTest(i=i): # This is the subtest context.
                self.assertEqual(i % 2, 0)