"""
The Lib/dataclasses.py module provides a decorator and functions for automatically adding generated special methods 
such as __init__() and __repr__() to user-defined classes. It was originally described in PEP 557.

The member variables to use in these generated methods are defined using PEP 526 type annotations. For example, 
we can see the code below.

This class, among other methods (such as __lq__, __repr__, __str__, etc) generates the following initializer:

def __init__(self, name: str, unit_price: float, quantity_on_hand: int = 0):
    self.name = name
    self.unit_price = unit_price
    self.quantity_on_hand = quantity_on_hand
"""

from dataclasses import dataclass

@dataclass
class pod:
	"""Class for keeping track of an item in inventory."""
	name: str
	unit_price: float
	quantity_on_hand: int = 0

	def total_cost(self) -> float:
		return self.unit_price * self.quantity_on_hand