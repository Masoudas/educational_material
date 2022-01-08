"""
For updating your dependencies, Poetry provides different options depending on two scenarios:

    -   Update a dependency inside your version constraints.
    -   Update a dependency outside your version constraints.

You can find your version constraints in your pyproject.toml file. When a new version of a dependency still fulfills your version constraints, you can use the update command:

$ poetry update

The update command will update all your packages and their dependencies within their version constraints. Afterward, Poetry will update your poetry.lock file.

If you want to update one or more specific packages, then you can list them as arguments:

$ poetry update requests beautifulsoup4

With this command, Poetry will search for a new version of requests and a new version of beautifulsoup4 that fulfill the version constraints listed in your pyproject.toml file. Then it'll resolve all dependencies of your project and pin the versions into your poetry.lock file. Your pyproject.toml file will stay the same because the listed constraints remain valid.

To add a project with the latest version to our toml file directly, use the following command:
$ poetry add pytest@latest --dev

After adding a new version, you must run the install command you learned about in the section above. Only then are your updates locked into the poetry.lock file.
"""
