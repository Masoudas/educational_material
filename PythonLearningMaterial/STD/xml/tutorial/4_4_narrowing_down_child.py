"""
It's possible to narrow down the tag we search for, and then iterate over that.
"""
import xml.etree.ElementTree as ET
tree = ET.parse("smiley.svg")
root = tree.getroot()

tag_name = "{http://www.w3.org/2000/svg}ellipse"

for descendant in root.iter(tag_name):
	print(descendant)	