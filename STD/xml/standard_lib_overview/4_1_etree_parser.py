"""
The previous ones are old, and even have incomplete implementation in CPython. The ElementTree is the best among
the bunch.

What we do with element tree is to essentially parse the file, then we get the root element, and parse over it.
Now, from the root element, we can iterate, or we can directly search for an element, which we discuss later.

By default, iterparse() emits only the end events associated with the closing XML tag. However, you can subscribe 
to other events as well. You can find them with string constants such as "comment".

Here's a list of events
	-	start: Start of an element
	-	end: End of an element
	-	comment: Comment element
	-	pi: Processing instruction, as in XSL
	-	start-ns: Start of a namespace
	-	end-ns: End of a namespace
"""
import xml.etree.ElementTree as ET

with open("face.xml") as file:
    ET.parse(file)	# The xml file.

with open("face.xml") as file:
	for event, element in ET.iterparse(file):
		print(event, element.tag)
# end {http://www.inkscape.org/namespaces/inkscape}custom

# 
for event, element in ET.iterparse("face.xml", ["comment"]):
    print(element.text.strip())