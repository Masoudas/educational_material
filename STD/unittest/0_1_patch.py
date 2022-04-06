"""
With unittests, patch is used for replacing a method with a replacement. It's good for creating mock
tests methods.

We use patch with the 'with' statement, as shown in the following example.
"""
from unittest.mock import patch
from unittest import TestCase, main

class S:
	def method():
		pass


class Test_S(TestCase):
	def test_method(self):
		def replacement():
			print("Using replacement method.")

		with patch(S.method, replacement) as mock_method:
			s = S()
			s.method()
		

if __name__ == "__main__":
	main()
