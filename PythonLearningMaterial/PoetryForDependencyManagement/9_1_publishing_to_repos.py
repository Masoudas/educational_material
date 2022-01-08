"""
Adding a new repository is easy with the config command.

$ poetry config repositories.foo https://foo.bar/simple/
This will set the url for repository foo to https://foo.bar/simple/.

If you want to store your credentials for a specific repository, you can do so easily:

$ poetry config http-basic.foo username password


## Install dependencies from a private repository
Now that you can publish to your private repository, you need to be able to install dependencies from it.

For that, you have to edit your pyproject.toml file, like so

[[tool.poetry.source]]
name = "foo"
url = "https://foo.bar/simple/"

Of course for this, I shall be using my own private pypi server.
"""
