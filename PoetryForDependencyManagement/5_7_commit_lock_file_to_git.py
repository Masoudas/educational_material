"""
While the version requirement in the pyproject.toml file can be loose, Poetry locks the versions you’re actually using in the poetry.lock file. That’s why you should commit this file if you’re using Git. By providing a poetry.lock file in a Git repository, you ensure that all developers will use identical versions of required packages. When you come across a repository that contains a poetry.lock file, it’s a good idea to use Poetry for it.

With poetry.lock, you can make sure that you use exactly the versions the other developers are using. And if the other developers aren’t using Poetry, you can add it to an existing project that wasn’t set up with Poetry.
"""
