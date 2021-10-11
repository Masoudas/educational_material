"""
If we want to return the class type from a method inside the class, we need to import annotations from the 
__future__ package.
"""

from __future__ import annotations

class MyClass:
	def return_this_type() -> MyClass:
		return MyClass()