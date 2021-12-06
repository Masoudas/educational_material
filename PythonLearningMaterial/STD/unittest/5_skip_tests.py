"""
The unittest library has a skiptest decorator, which allows us to skip tests, as the following example demonstrates. We also have skif, and skipunless.
"""
from unittest import skip, skipIf, skipUnless, TestCase

class Tests(TestCase):
    a = 20
    b = 10
    
    @skip("I haven't implemented this test")
    def test_skip():
        assert False, "OMG"
    
    @skipIf(a>b, "Skip over this routine")
    def testsub(self):
      """sub"""
      result = self.a-self.b
      self.assertTrue(result == -10)
   
    @skipUnless(b == 0, "Skip over this routine")
    def testdiv(self):
      """div"""
      result = self.a/self.b
      self.assertTrue(result == 1)