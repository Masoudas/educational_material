"""
The value of some objects can change. Objects whose value can change are said to be mutable; objects whose value is 
unchangeable once they are created are called immutable. (The value of an immutable container object that contains 
a reference to a mutable object can change when the latter’s value is changed; however the container is still 
considered immutable, because the collection of objects it contains cannot be changed. So, immutability is not 
strictly the same as having an unchangeable value, it is more subtle.) An object’s mutability is determined by its 
type; for instance, numbers, strings and tuples are immutable, while dictionaries and lists are mutable.

Some objects contain references to other objects; these are called containers. Examples of containers are tuples, 
lists and dictionaries. The references are part of a container’s value. In most cases, when we talk about the value 
of a container, we imply the values, not the identities of the contained objects; however, when we talk about the 
mutability of a container, only the identities of the immediately contained objects are implied. So, if an immutable 
container (like a tuple) contains a reference to a mutable object, its value changes if that mutable object is 
changed (me: but is still considered immutable, like we talked above.)


"""