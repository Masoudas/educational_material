"""
The library is easy to use, and once a file is parsed, the root element is returned.

The problem with the library is that namespaces are added with underscore after the tag name. For example,
for NameSpace namespace, a tag will be read as 'myTag_myNameSpace'

Because the root element is accessed by name, use dir to get the name:
"""

import untangle

document = untangle.parse("file.xml")

document.my_root_tag	# Access the root element
document.my_root_tag["my_attribute"]	# Access the root element

dir(document)
"my_root_tag"

dir(document.my_root_tag)	# Access child tags.
"{tag1, tag2, ...}"

for element in document.my_root_tag:
	print(element)