"""
The recursive yields are interesting. When yield is called with another function, instead of execution of the
function, the function object is returened, which is odd.

To remedy this, we must use 'yield from', which yields from another function. So, use it.

Try the following without the from keyword, and you'll see that it does not go through the function calls, but
rather it returns the function itself!
"""

class Node:
	def __init__(self, value, left=None, right=None):
		self.value = value
		self.left = left
		self.right = right

	def _traverse(self):
		"""We're not using return to allow for continuation of iteration in this manner, using yield.
		Yield would allow the function to continue.
		"""
		if self.left is not None:
			yield from self.left._traverse()		
		
		yield self.value
		
		if self.right is not None:
			yield from self.right._traverse()

tree = Node(
	1,
	Node(2, Node(3, None, None), Node(4, None, None)),
	Node(5, Node(6, None, None), None)
)
for value in tree._traverse():
	print(value)