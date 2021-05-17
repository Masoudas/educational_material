/**
 * Suppose we want to paint a rectangle on our app. We need to do something as follows:
 
QRectangle r{0,0,16,16};
QPainter p; 
p.setBrush(QBrush(Qt::blue)); 
p.drawRect(r);

 * The QtQuick QML turns this into a simple couple lines of code:

import QtQuick 2.12 # Python like import

Rectangle{
    width : 16
    height: 16
    color: "blue"   # String values go into quotation.
}

 * Qt Quick's underlying language is QML. QML is based heavily on JavaScript, and, in fact, most things that we 
 * can write in JavaScript, we can also express in QML. Expression syntax is essentially unchanged; assignments, 
 * arithmetic, and so forth all are the same, and the name/value system is functionally the same, although 
 * object frames might be preceded by a type declaration (as you we see with the Rectangle example).
 * 
 * A key exception to the what works in JavaScript works in QML rule is the lack of a document object model 
 * (DOM), and things such as the document root for global variables because there's no root context or DOM on 
 * which other things hang. If you're porting a web application to QML, be prepared to refactor those parts of 
 * your application's architecture.
 * 
 * Objects in QML must be parented in the fashion of a tree; each QML file must contain an encapsulating object, 
 * and then can have child objects that have child objects. However, there must be a single root for the 
 * hierarchy at the top of the file. Often, this root is a Rectangle object, which draws a base rectangle on 
 * which its children are presented, or an Item object, which is a container for a more complex user interface 
 * element that doesn't actually draw anything. Each item can have a name, which is stored in its id property.
 * 
 * Most visible QML items can have states—that is, a collection of properties that apply when a particular state 
 * is active. This lets you do things such as declare the difference between a button's dormant and pressed 
 * state; pressing the button just toggles between the states, and the button's color, shadow, and so on can 
 * all change, with you not needing to change each individual property.
 * 
 * A key concept in QML that's not present in JavaScript is that of binding: if two QML object properties share 
 * the same value, changing one changes the other. Binding is a method that couples values with notifications 
 * about value changes; it's similar to how references work in C++, or how pass-by-reference works in other 
 * languages. This is very handy in coding things such as animations because you can use the value of one object 
 * as the value for another object, and when the underlying value changes in one place, both objects are updated.
 * 
 */