"""
The hybrid parsing implies that once we reach a node that we're interested in, we can start analyzing its
children to get the object we seek. 

The etree however is the best of the best.
"""

from xml.dom.pulldom import parse, START_ELEMENT

def process_group(parent):
    left_eye, right_eye = parent.getElementsByTagName("ellipse")
    # ...

event_stream = parse("face.xmlW")
for event, node in event_stream:
    if event == START_ELEMENT:
        if node.tagName == "g":
            event_stream.expandNode(node)	# Using the forward iterator to expand the node.
            process_group(node)