"""This is from PEP 526
It's possible to annotate local variables using the column operator as shown below, which is very good!

Note that to annotate lists, sets, etc, we import from the typing module. Moreover, notice that for static (or class)
variables, we use the ClassVar annotation. Notice that variables can have default or non-default values. Also notice
that we this annotation (and if I may add finally!) we define the class variables where they should be defined, 
which is outside the init method.
"""

from typing import ClassVar, List, Dict


x : List[int] = [1, 2, 3]

class S:
	static_val: ClassVar[Dict[str, int]]  	# This would be a static variable.
	val1: int = 10

S().val1 = 20	# Ensuring that this is not a static variable.
print(S().val1)
