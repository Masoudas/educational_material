"""
One of the most important files for working with Poetry is the pyproject.toml file. This file isn't an invention of Poetry. It's a configuration file standard that was defined in PEP 518:
####
This PEP specifies how Python software packages should specify what build dependencies they have in order to execute their chosen build system. As part of this specification, a new configuration file is introduced for software packages to use to specify their build dependencies (with the expectation that the same configuration file will be used for future configuration details). 
####

Here's a look inside the toml file:
You can see four sections in the pyproject.toml file. These sections are called tables. They contain instructions that tools like Poetry recognize and use for dependency management or build routines. Notice that there's difference between dev and buil dependencies.

# pyproject.toml

[tool.poetry]
name = "rp-poetry"
version = "0.1.0"
description = ""
authors = ["Philipp <philipp@realpython.com>"]

[tool.poetry.dependencies]
python = "^3.9"

[tool.poetry.dev-dependencies]
pytest = "^5.2"

[build-system]
requires = ["poetry-core>=1.0.0"]
build-backend = "poetry.core.masonry.api"
#

The last table of the pyproject.toml file is [build-system] on line 15. This table defines data that Poetry and other build tools can work with, but as it's not tool-specific, it doesn't have a prefix. Poetry created the pyproject.toml file with two keys in place:

        requires: a list of dependencies that are required to build the package, making this key mandatory
        build-backend: the Python object used to perform the build process
"""
