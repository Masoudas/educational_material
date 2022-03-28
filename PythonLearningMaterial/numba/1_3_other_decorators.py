"""
Numba has quite a few decorators, we’ve seen @jit, but there’s also:

    -   @njit - this is an alias for @jit(nopython=True) as it is so commonly used!
    -   @vectorize - produces NumPy ufunc s (with all the ufunc methods supported).
    -   @guvectorize - produces NumPy generalized ufunc s.
    -   @stencil - declare a function as a kernel for a stencil like operation.
    -   @jitclass - for jit aware classes.
    -   @cfunc - declare a function for use as a native call back (to be called from C/C++ etc).
    -   @overload - register your own implementation of a function for use in nopython mode, e.g.
"""
