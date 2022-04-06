"""
When you start a new Python project, it's good practice to create a virtual environment. Otherwise, you may confuse different dependencies from different projects. Working with virtual environments is one of Poetry's core features, and it'll never interfere with your global Python installation.

However, Poetry doesn't create a virtual environment right away when you start a project. You can confirm that Poetry hasn't created a virtual environment by having Poetry list all virtual environments connected to the current project. If you haven't already, cd into rp-poetry/ and then run a command:

$ poetry env list

Poetry will create a virtual environment along the way when you run certain commands. If you want to have better control over the creation of a virtual environment, then you might decide to tell Poetry explicitly which Python version you want to use for it and go from there:

$ poetry env use python3
#Or just
$ poetry env

With this command, you’re using the same Python version that you used to install Poetry. Using python3 works when you have the Python executable in your PATH.

Note: The python version is defined in the toml file. The executable that we path with this command, be it absolute path or a system variable, must match that constranit.
"""
