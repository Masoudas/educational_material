"""
As always, note that mathematical operators have priority over logical operators.

== has higher precendece than logical operators. As such the following statement is wrong:
if True == not False:

Also note that not has a higher precedence than or and and. Moreover, and has higher precedence than or. This
is the same as multiplication, where * has higher precedence than +.
"""

if not 0 + 0 and 1 + 1:
	print("Mathematical has precedence over logical")

if True and True or False:
	print("And has higher precedence than or")

