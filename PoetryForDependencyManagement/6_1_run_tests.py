"""
With your project’s package installed, you can import rp_poetry into your tests and check for the __version__ string. With pytest installed, you can use the poetry run command to execute the tests:

$ poetry run pytest
========================= test session starts ==========================
platform darwin -- Python 3.9.1, pytest-5.4.3, py-1.10.0, pluggy-0.13.1
rootdir: /Users/philipp/Real Python/rp-poetry
collected 1 item

tests/test_rp_poetry.py .                                        [100%]

========================== 1 passed in 0.01s ===========================

Notice that the pytest we have in this project is greater than the version we defined. Why? The carrot before the pytest version implies we can use greater versions of it.
"""
