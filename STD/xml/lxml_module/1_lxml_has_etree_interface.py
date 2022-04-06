"""
lxml has the same interface as etree (read the standard_lib_overview section over the etree module,) but has a 
greater performance, and it can also validate against an schema, DTD, etc.

The following shows how to validate messages with respect to an schema.
"""
import lxml.etree as ET

xml_schema = ET.XMLSchema(
    ET.fromstring("""\
        <xsd:schema xmlns:xsd="http://www.w3.org/2001/XMLSchema">
            <xsd:element name="parent"/>
            <xsd:complexType name="SomeType">
                <xsd:sequence>
                    <xsd:element name="child" type="xsd:string"/>
                </xsd:sequence>
            </xsd:complexType>
        </xsd:schema>"""))

valid = ET.fromstring("<parent><child></child></parent>")
invalid = ET.fromstring("<child><parent></parent></child>")

xml_schema.validate(valid)
True 

xml_schema.validate(invalid)
False