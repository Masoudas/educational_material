"""
The first argument of defaults is the one that is used:
defaults
    - db: mysql

However, it's possible to have multiple defaults:
defaults:
 - db: mysql
 - db/mysql/engine: innodb  # Me: Still used for the db object, but now contains a more
                            # elaborate path.

The defaults are ordered:
    -   If multiple configs define the same value, the last one wins.
    -   If multiple configs contribute to the same dictionary, the result is the combined dictionary.

"""