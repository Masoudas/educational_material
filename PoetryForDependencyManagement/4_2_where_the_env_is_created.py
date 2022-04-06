"""
The environment is created not in the folder project, but rather cached in another location, Mine is:

Using virtualenv: /home/masoudas/.cache/pypoetry/virtualenvs/my-project-7yWyBeLf-py3.8

The seemingly random string in the middle is a hash of your parent directory. With this unique string in the middle, Poetry can handle multiple projects with the same name and the same Python version on your system. That's important because, by default, Poetry creates all your virtual environments in the same folder.

Note from me:  This is better, because then I don't have to gitignore it every time.

If you want to change the default cache directory, then you can edit Poetry's configuration. This can be useful when you're already using virtualenvwrapper or another third-party tool for managing your virtual environments. To see the current configuration, including the configured cache-dir, you can run a command:

$ poetry config --list

Usually, we needn't do this.

Again, find out where the environment is with:
$ poetry env list
"""
