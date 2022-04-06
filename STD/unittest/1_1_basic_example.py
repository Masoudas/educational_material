"""
A basic test unit is given below, where a testcase is created by subclassing unittest.TestCase. The three individual 
tests are defined with methods whose names start with the letters test. This naming convention informs the test 
runner about which methods represent tests.

The crux of each test is a call to assertEqual() to check for an expected result; assertTrue() or assertFalse() to 
verify a condition; or assertRaises() to verify that a specific exception gets raised. These methods are used 
instead of the assert statement so the test runner can accumulate all test results and produce a report.

The setUp() and tearDown() methods allow you to define instructions that will be executed before and after each 
test method.
"""

import unittest
class TestStringMethods(unittest.TestCase):
    def test_upper(self):
        self.assertEqual('foo'.upper(), 'FOO')

    def test_isupper(self):
        self.assertTrue('FOO'.isupper())
        self.assertFalse('Foo'.isupper())

    def test_split(self):
        s = 'hello world'
        self.assertEqual(s.split(), ['hello', 'world'])	# Notice that assert equal is recursive
		
        # check that s.split fails when the separator is not a string
		# Yeah, this is complicated!
        with self.assertRaises(TypeError):
            s.split(2)

if __name__ == '__main__':
    unittest.main()