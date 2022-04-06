"""
As such, instead of using pip install, we now use poetry add:

$ poetry add numpy

To install packages only in the dev environment, we need to use the -D flag:

$ poetry add autopep8 -D

Differentiating between project dependencies and development dependencies prevents installing requirements that a user doesn’t need to run the program. The development dependencies are only relevant for other developers of your package who want to run tests with pytest and make sure the code is properly formatted with black. When users install your package, they only install requests with it.

Note: You can go even further and declare optional dependencies. This can be handy when you want to give users the option to install a specific database adapter that isn’t required but enhances your package. You can learn more about optional dependencies in the Poetry documentation.

Besides the changes to the pyproject.toml file, Poetry also created a new file named poetry.lock. In this file, Poetry keeps track of all packages and the exact versions you’re using in the project.
"""
