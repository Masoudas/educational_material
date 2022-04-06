"""
It's possible to pass namespaces to the iterator as well.
"""
import xml.etree.ElementTree as ET

tree = ET.parse("smiley.svg")
root = tree.getroot()

namespaces = {
    "": "http://www.w3.org/2000/svg",
    "custom": "http://www.w3.org/2000/svg"
}

for descendant in root.iterfind("g", namespaces):
	print(descendant)
# <Element '{http://www.w3.org/2000/svg}g' at 0x7f430baa0270>