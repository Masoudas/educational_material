"""
We can use the abstract container types to implement a container type. For example, we implement our tree as
a sequence like object.

Of course, Notice that we still need to implement some of the methods. Others, however, are implemented
by the abstract method. __get_item__ and __len__ are the methods to be implemented.
"""
from collections.abc import Sequence    # Abstract sequence type.

class BetterNode(Sequence):
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
        yield self
        if self.right is not None:
            yield from self.right._traverse()

    def __getitem__(self, index):
        for i, item in enumerate(self._traverse()):
            if i == index:
                return item.value
        raise IndexError(f'Index {index} is out of range')

    def __len__(self):
        for count, _ in enumerate(self._traverse(), 1):	
            pass
        return count

tree = BetterNode(
    10,
    left=BetterNode(
        5,
        left=BetterNode(2),
        right=BetterNode(
            6,
            right=BetterNode(7))),
    right=BetterNode(
        15,
        left=BetterNode(11))
)
