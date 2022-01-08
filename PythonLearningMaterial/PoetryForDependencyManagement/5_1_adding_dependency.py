"""
Make sure that you’re inside the rp-poetry/ project folder and run a command:

$ poetry install

With the install command, Poetry checks your pyproject.toml file for dependencies then resolves and installs them. The resolving part is especially important when you have many dependencies that require different third-party packages with different versions of their own. Before installing any packages, Poetry figures out which version of a package fulfills the version constraints that other packages set as their requirements.

Besides pytest and its requirements, Poetry also installs the project itself. This way, you can import rp_poetry into your tests right away:

"""
