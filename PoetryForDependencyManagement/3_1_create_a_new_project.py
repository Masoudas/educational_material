"""
You can create a new Poetry project by using the new command and a project name as an argument. In this tutorial, the project is called rp-poetry. Create the project, and then move into the newly created directory:

$ poetry new rp-poetry
$ cd rp-poetry

By running poetry new rp-poetry, you create a new folder named rp-poetry/. When you look inside the folder, you’ll see a structure:

rp-poetry/
│
├── rp_poetry/
│   └── __init__.py
│
├── tests/
│   ├── __init__.py
│   └── test_rp_poetry.py
│
├── README.rst
└── pyproject.toml

Poetry automatically normalizes package names for you. It transformed the dash (-) in your project name into an underscore (_) in the folder name of rp_poetry/. Otherwise, the name wouldn’t be allowed in Python, so you couldn’t import it as a module. To have more control over creating the package name, you can use the --name option to name it differently than the project folder:

$ poetry new rp-poetry --name realpoetry

If you prefer to store your source code in an additional src/ parent folder, then Poetry lets you stick to that convention by using the --src flag:
$ poetry new --src rp-poetry

Notice that when you hop over to the tests/ folder and open test_rp_poetry.py, you’ll notice that rp_poetry is already importable:

from rp_poetry import __version__

def test_version():
    assert __version__ == "0.1.0"

Notice that the project version is also defined in the pyproject folder as well.

"""
