"""
We can manually add dependencies to our toml file.

# rp_poetry/pyproject.toml (Excerpt)

[tool.poetry.dependencies]
python = "^3.9"
beautifulsoup4 = "4.10.0"       # Manually added.

When you add a requirement to the pyproject.toml file, it's not installed yet. As long as there's no poetry.lock file present in your project, you can run poetry install after manually adding dependencies, because Poetry looks for a poetry.lock file first. If it doesn't find one, Poetry resolves the dependencies listed in the pyproject.toml file.

As soon as a poetry.lock file is present, Poetry will rely on this file to install dependencies. Running only poetry install would trigger a warning that both files are out of sync and would produce an error because Poetry wouldn’t know of any beautifulsoup4 versions in the project yet.

To pin manually added dependencies from your pyproject.toml file to poetry.lock, you must first run the poetry lock command:

$ poetry lock

Note: The poetry lock command also updates your existing dependencies if newer versions that fit your version constraints are available . If you don’t want to update any dependencies that are already in the poetry.lock file, then you have to add the --no-update option to the poetry lock command:

$ poetry lock --no-update

In this case, Poetry only resolves the new dependencies but leaves any existing dependency versions inside the poetry.lock file untouched.

"""
