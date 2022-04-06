"""
If our project does not comply to the normal folder structure of poetry, we can directly specify the packages. That way, the project name would be different from the modules!

[tool.poetry]
name =
version =
description =
authors =
license =
packages = [
    { include = "my_package" },
    { include = "extra_package/**/*.py" },
]

Or 

[tool.poetry]
name =
version =
description =
authors =
license =
packages = [
    { include = "my_package", from = "lib" },
]
"""
