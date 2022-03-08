"""
This one is really serious. We need to use context managers when we want to set the prevision during calculation with Decimal numbers:

>>> from decimal import Decimal, localcontext

>>> with localcontext() as ctx:
...     ctx.prec = 42
...     Decimal("1") / Decimal("42")
"""