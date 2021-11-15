"""
It's possible to create an xml document by noting that we can creathe the xml header from a string, and then
elements from there on by adding elements.

Note that there's no pretty printing here. To that end, we must specify indentation using the indent directly.

"""
from os import write
import xml.etree.ElementTree as ET

def prettify(elem):
    """Return a pretty-printed XML string for the Element.
    """
    rough_string = ET.tostring(elem, 'utf-8')
    reparsed = DOM.parseString(rough_string)
    return reparsed.toprettyxml(indent="\t")

parent = ET.Element("parent")

child = parent.makeelement("child", {"attr1": "1", "attr2" : "2"})
child.text = "This is my text"

parent.insert(1, child)

###
tree = ET.ElementTree(parent)
ET.indent(tree, '\t')
tree.write("myXML.xml", encoding="UTF-8", xml_declaration=True)

