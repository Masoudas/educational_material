"""
IF a module changes after being imported (in interactive sessions,) we need to reload it:

We must also not forget the famous "__name__ == __main__", which happens in case the module being executed is the
main module.
"""

import copy

# copy.reload()	Does not seem to have this function.