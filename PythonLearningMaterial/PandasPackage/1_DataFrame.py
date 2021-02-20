"""
The fundamental data structure of the package.
class pandas.DataFrame(data=None, index=None, columns=None, dtype=None, copy=False)
Two-dimensional, size-mutable, potentially heterogeneous tabular data.

Data structure also contains labeled axes (rows and columns). Arithmetic operations align on both row and column labels. Can be 
thought of as a dict-like container for Series objects. The primary pandas data structure.

Parameters
data: ndarray (structured or homogeneous), Iterable, dict, or DataFrame
Dict can contain Series, arrays, constants, dataclass or list-like objects. If data is a dict, column order follows 
insertion-order.

index: Index or array-like
Index to use for resulting frame. Will default to RangeIndex if no indexing information part of input data and no index provided.

columns: Index or array-like
Column labels to use for resulting frame. Will default to RangeIndex (0, 1, 2, …, n) if no column labels are provided.

dtyped: type, default None
Data type to force. Only a single dtype is allowed. If None, infer.

copy: bool, default False
Copy data from inputs. Only affects DataFrame / 2d ndarray input.
"""

import pandas as pd
import numpy as np

data = {'col1': [1, 2], 'col2': [3, 4]}

df = pd.DataFrame(data=data)
print(df)

# Data is indexed in both range and column from 0. This would be 2 rows and three columns
df = pd.DataFrame(data=np.array([[1, 2, 3], [4, 5, 6]]))
print(df)
