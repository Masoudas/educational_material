"""
When packages are structured into subpackages (as with the sound package in the example), you can use absolute 
imports to refer to submodules of siblings packages. For example, if the module sound.filters.vocoder needs to use 
the echo module in the sound.effects package, it can use from sound.effects import echo.

You can also write relative imports, with the from module import name form of import statement. These imports use 
leading dots to indicate the current and parent packages involved in the relative import. From the surround module 
for example, you might use:

from . import echo
from .. import formats
from ..filters import equalizer		

Me: The latter is better for tracking of packages in environments like VSCode. We should recall that the root is
where the main module resides.
"""