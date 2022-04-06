"""
Well, this library has no type annotation, so good luck using it!
"""

import lxml.etree as ET

parent = ET.Element("parent")

child = parent.makeelement("child", {"attr1": "1", "attr2" : "2"})
child.text = "This is my text"

parent.insert(1, child)
parent.insert(2, child)
###
ET.ElementTree(parent).write("myXML.xml", pretty_print=True, xml_declaration=True)
