"""
What happens when the user writes from sound.effects import *? Ideally, one would hope that this somehow goes out 
to the filesystem, finds which submodules are present in the package, and imports them all. This could take a long 
time and importing sub-modules might have unwanted side-effects that should only happen when the sub-module is 
explicitly imported.

The only solution is for the package author to provide an explicit index of the package. The import statement uses 
the following convention: if a package’s __init__.py code defines a list named __all__, it is taken to be the list 
of module names that should be imported when from package import * is encountered. It is up to the package author 
to keep this list up-to-date when a new version of the package is released. Package authors may also decide not to 
support it, if they don’t see a use for importing * from their package. For example, the file 
sound/effects/__init__.py could contain the following code:

__all__ = ["echo", "surround", "reverse"]

If __all__ is not defined, the statement from sound.effects import * does not import all submodules from the package 
sound.effects into the current namespace; it only ensures that the package sound.effects has been imported (possibly 
running any initialization code in __init__.py) and then imports whatever names are defined in the package. This 
includes any names defined (and submodules explicitly loaded) by __init__.py. It also includes any submodules of the 
package that were explicitly loaded by previous import statements. Consider this code:

import sound.effects.echo
import sound.effects.surround
from sound.effects import *

In this example, the echo and surround modules are imported in the current namespace because they are defined in the 
sound.effects package when the from...import statement is executed (This also works when __all__ is defined.)

In general, however, we avoid import all statements.
"""