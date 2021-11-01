"""
In this example, we try and implement an indexable tree, manually without collections.abc

First, consider the a simple traversing of the tree. We can overload the __getitem__ to index a tree. 

Me As such, for example a default iterator would iterate over this class using the default iter method built 
class. Then, we can also use operators such as 'in', as shown in the usage.

We've also implemented the len method. The problem is that we don't have access to an index method, or count,
etc.

The collections.abc, however, implements these for us automatically.
"""
class BinaryNode:
     def __init__(self, value, left=None, right=None):
         self.value = value
         self.left = left
         self.right = right

class IndexableNode(BinaryNode):
    def _traverse(self):
        """We're not using return to allow for continuation of iteration in this manner, using yield.
        Yield would allow the function to continue.
        """
        if self.left is not None:
            yield from self.left._traverse()	
        yield self
        if self.right is not None:
            yield from self.right._traverse()

    def __getitem__(self, index):
        for i, item in enumerate(self._traverse()):
            if i == index:
                return item.value
        raise IndexError(f'Index {index} is out of range')

    def __len__(self):
        for count, _ in enumerate(self._traverse(), 1):	# Clever. count starts from 1 and goes up. Yeah.
														# Be careful that for loops don't create a new
														# scope in python.
            pass
        return count

tree = IndexableNode(
    10,
    left=IndexableNode(
        5,
        left=IndexableNode(2),
        right=IndexableNode(
            6,
            right=IndexableNode(7))),
    right=IndexableNode(
        15,
        left=IndexableNode(11)))

for node in iter(tree):
    print(node)