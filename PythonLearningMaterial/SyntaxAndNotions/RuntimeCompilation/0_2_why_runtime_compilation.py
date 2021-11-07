"""
Apparently, the idea of runtime compilation is what made languages dynamic. Beginner programmers tend to
use eval to for example access a property that is defined at runtime (like for example when a user 
chooses something from a box:)

eval('object.'+attr_name)

But the correct way of doing this is through getattr:
getattr(object, attr_name)
"""