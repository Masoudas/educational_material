"""
Suppose you want to design a collection of modules (a “package”) for the uniform handling of sound files and sound 
data. Here’s a possible structure for your package (expressed in terms of a hierarchical filesystem):

sound/                          Top-level package
      __init__.py               Initialize the sound package
      formats/                  Subpackage for file format conversions
              __init__.py
              wavread.py
              wavwrite.py
              aiffread.py
              aiffwrite.py
              auread.py
              auwrite.py
              ...
      effects/                  Subpackage for sound effects
              __init__.py
              echo.py
              surround.py
              reverse.py
              ...
      filters/                  Subpackage for filters
              __init__.py
              equalizer.py
              vocoder.py
              karaoke.py

The __init__.py files are required to make Python treat directories containing the file as packages. This prevents 
directories with a common name, such as string, unintentionally hiding valid modules that occur later on the module 
search path. In the simplest case, __init__.py can just be an empty file, but it can also execute initialization 
code for the package or set the __all__ variable, described later.

Users can import individual modules, which must be used we full-name (or with as):

import sound.effects.echo
sound.effects.echo.equalize(..)

Alternatively:
from sound.effects import echo
from sound.effects.echo import echofilter

If import does not exist, and ImportError exception is raised.
"""