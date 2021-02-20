package GoF.Creational.Builder;

/**
 * Intent: To separate the representation of an object from it's implementation. 
 * so that the same construction process can make different presentations.
 * 
 * 
 * The aim is to define a builder interface (normally not a class, because the builders
 * don't have common interfaces). Then ConcreteBuilders implement this interface. Then
 * There's a Director (Parser) class, that uses these builders to create a final product,
 * using these builders. A client first invokes a builder, then the director to create it.
 * Finally, each builder gives back the product using perhaps a specific method.
 * 
 * Example: 
 * Builder interface: TextBuilder
 * ConcreteBuilders: ASCIITextBuilder, TexTextBuilder ...
 * Product methods: getASCII(), getText(), ....
 * Director: RichTextPresentor (it gets a TextBuilder interface as input. Parses through
 * a test, and gives it to the builders for them to create the product they want).
 */