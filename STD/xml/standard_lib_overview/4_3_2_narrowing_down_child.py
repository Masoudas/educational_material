"""
To narrow down a child (or equivalently find a tag), we need to use the root element's find.
	-	find: Finds the first instance of a tag.

Note: Even if an element is in the global name space, because the elements are read with their namespace URI
attached to them (like "{http://www.w3.org/2000/svg}ellipse"), we need to pass either the list of name spaces,
or the URI of the namespace we look for. For example, if we're looking for a tag named ellipse, we can do either
of the following. Essentially, defining the namespaces is a must, but how we search a particular namespace (or
all of them) is the question:

#### Method1: Put namespace before the tag name:
tag_name = "{http://www.w3.org/2000/svg}ellipse"	# Namespace is http://www.w3.org/2000/svg
element = element.find(tag_name)

#### Method2: Define namespaces and pass them. If no namespace is assigned to tag, all tags of this name from
all the namespaces are found:

namespaces = {
	"", "http://www.w3.org/2000/svg"
}
element = element.find("ellipse", namespaces)

#### Method3: Define namespaces and pass them.
namespaces = {
	"", "http://www.w3.org/2000/svg"
	"inkspace", "http://www.inkscape.org/namespaces/inkscape"
}
element = element.find("inkspace:ellipse", namespaces)

Note: Once over an element, we can never go over its siblings with the methods of the element class. As such,
we need to keep the parent method alive to go over the siblings of the current method.

Note: Once we're over an element, iterating over it does not move the cursor of the file or anything. When
the element object is there, we can once again start working from there.

Note the following methods work the same way:
	-	iter: Start looking from the given element, and search all the document from there for tags that
			  match the given tag name. It DOES NOT iterate over the children of the given tag.
	-	findall: In the CHILDREN of the given element, find all subelements that match the given tag.
	-	iterfind: Essentially like findall, but creates an iterator. It's a lazy version of findall.
	-	findtext: Finds based on tag name, but returns element text instead of the element itself. We can pass
		a default value to be returned in case an element is not found.

It's possible to narrow down the tag we search for, and then iterate over that.
"""
import xml.etree.ElementTree as ET
tree = ET.parse("STD/xml/tutorial/face.xml")
root = tree.getroot()

tag_name = "{http://www.w3.org/2000/svg}text"
print(root.findtext(tag_name))

for descendant in root.iter(tag_name):
	print(descendant)	