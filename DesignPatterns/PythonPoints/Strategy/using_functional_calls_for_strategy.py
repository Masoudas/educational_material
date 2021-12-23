"""
Normally, we use a function in the strategy interface. However, we may use the the __call__ function to make our strategies functional, as the following example demonstrates.
"""
from abc import ABC, abstractmethod

class Strategy(ABC):
    @abstractmethod
    def implement(self, i: int):
        raise NotImplementedError

class myStrategy(Strategy):
    def implement(self, i: int):
        print("Implementation")


### Functional approach
class FStrategy(ABC):
    @abstractmethod
    def __call__(self, i: int):
        raise NotImplementedError

class myFStrategy(FStrategy):
    def __call__(self, i: int):
        print("Implementation.")
