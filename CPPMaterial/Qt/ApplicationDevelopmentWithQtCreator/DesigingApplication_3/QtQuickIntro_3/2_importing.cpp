/*
 * QML files can depend on each other or include files of JavaScript for business logic. You've already seen one 
 * example of this at the top of every QML file: the import directive instructs the runtime to include the 
 * indicated file and version; so, when we write import QtQuick 2.12, the runtime finds the declaration of the 
 * Qt Quick module version 2.12 and includes its symbols when parsing the file. This is how you can encapsulate 
 * functionality. QML files in your project are included by default, while you can also include JavaScript files 
 * and assign them to a specific JavaScript variable.
 * 
 * For example, we can have a JavaScript file calculatorLogic.js that implements all of the functionality of our 
 * calculator. In the QML, write the following code:
 
import QtQuick 2.12 
import "calculatorLogic.js" as CalculatorLogic 
Item { 
    // someplace in code 
    CalculatorLogic.add(argument1, argument2); 
} 

 */