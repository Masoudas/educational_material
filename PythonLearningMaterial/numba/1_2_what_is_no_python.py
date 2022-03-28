"""
What is nopython mode?
The Numba @jit decorator fundamentally operates in two compilation modes, nopython mode and object mode. In the go_fast example above, nopython=True is set in the @jit decorator; this is instructing Numba to operate in nopython mode. The behaviour of the nopython compilation mode is to essentially compile the decorated function so that it will run entirely without the involvement of the Python interpreter. This is the recommended and best-practice way to use the Numba jit decorator as it leads to the best performance.

Should the compilation in nopython mode fail, Numba can compile using object mode. This is a fall back mode for the @jit decorator if nopython=True is not set (as seen in the use_pandas example above). In this mode Numba will identify loops that it can compile and compile those into functions that run in machine code, and it will run the rest of the code in the interpreter. For best performance avoid using this mode!
"""
