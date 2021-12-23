"""
Often, the problem we encounter in the strategy pattern is that we need to pass arguments to particular strategies. 

Suppose:

class Strategy:
    def __call__(self)

Three solutions are suggested:

    -   Add kwargs to the keyword argument. The problem is that we lose type naming and information if we do so.

    -   Add a StrategyParams class. The problem with this method is that there would be a coupling between different strategies (which we tried to avoid by using the pattern in the first place.)

class StrategyParams
    param_strategy1 # For strategy 1
    param_strategy2 # For strategy 2

class Strategy:
    def __call__(self, StrategyParams)

# See the coupling between the two strategies.
class Strategy1:
    def __call__(self, StrategyParams)  # coupling

class Strategy2:
    def __call__(self, StrategyParams)  # coupling

    -   Third strategy is the best one, and that is to add params to the initializers,

class Strategy1:
    def __init__(self, StrategyParams)
    def __call__(self)  # coupling


"""