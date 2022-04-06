"""
We can determine, during function definition, whether a set of parameters should be passed to function 
positionally, or by keyword, using the /* operator.

def f(pos1, pos2, /, pos_or_kwd, *, kwd1, kwd2):
      -----------    ----------     ----------
        |             |                  |
        |        Positional or keyword   |
        |                                - Keyword only
         -- Positional only

Examples are given below. Notice that no error is shown upon scripting, however, errors are thrown upon execution.

"""
def standard_arg(arg):
    print(arg)

def pos_only_arg(arg, /):
    print(arg)

def kwd_only_arg(*, arg):
    print(arg)

def combined_example(pos_only, /, standard, *, kwd_only):
    print(pos_only, standard, kwd_only)

combined_example(standard=3, pos_only=1, kwd_only=2)

