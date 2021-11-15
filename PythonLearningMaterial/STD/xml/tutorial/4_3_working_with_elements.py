"""
We can work with elements directly, and iterate over them.
"""
import xml.etree.ElementTree as ET
tree = ET.parse("smiley.svg")
root = tree.getroot()

# The length of an element equals the number of its children.
len(root)
5

# The square brackets let you access a child by an index.
root[1]
# <Element '{http://www.w3.org/2000/svg}defs' at 0x7fe05d2e8860>
root[2]
# <Element '{http://www.w3.org/2000/svg}g' at 0x7fa4c9848400>

# Elements are mutable. For example, you can swap their children.
root[2], root[1] = root[1], root[2]

# You can iterate over an element's children.
for child in root:
    print(child.tag)
# {http://www.inkscape.org/namespaces/inkscape}custom
# {http://www.w3.org/2000/svg}g
# {http://www.w3.org/2000/svg}defs
# {http://www.w3.org/2000/svg}text
# {http://www.w3.org/2000/svg}script

# Accessing elements of a node
element = root[0]

element.tag
'{http://www.inkscape.org/namespaces/inkscape}custom'

element.text
'Some value'

element.attrib
{'x': '42', '{http://www.inkscape.org/namespaces/inkscape}z': '555'}

element.get("x")
'42'