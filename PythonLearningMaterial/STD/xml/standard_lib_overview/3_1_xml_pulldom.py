"""
The parsers in the Python standard library often work together. For example, the xml.dom.pulldom module wraps 
the parser from xml.sax to take advantage of buffering and read the document in chunks. At the same time, it 
uses the default DOM implementation from xml.dom.minidom for representing document elements. However, those 
elements are processed one at a time without bearing any relationship until you ask for it explicitly.

This would be the StAX method, allowing for a simple iteration over the file.

event indicates what the parser has found (START_DOCUMENT, START_ELEMENT, ... ), and node is the information
of that node.
Nodes, however, know nothing about their children, siblings, etc.
"""

# Simple parser
from xml.dom.pulldom import parse, START_ELEMENT

event_stream = parse("face.xml")

for event, node in event_stream:
	print(event, node)
	
# Knows nothing about other information, only a parser.
event_stream = parse("smiley.svg")
for event, node in event_stream:
    if event == START_ELEMENT:
        print(node.parentNode, node.previousSibling, node.childNodes)

"""
START_DOCUMENT <xml.dom.minidom.Document object at 0x7f6e18109be0>
START_ELEMENT <DOM Element: svg at 0x7f6e1886e670>
"""