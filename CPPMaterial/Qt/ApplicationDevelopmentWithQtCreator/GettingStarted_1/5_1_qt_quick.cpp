/**
 * Qt Quick is Qt's newer declarative framework for the user interface. With this, it's incredibly easy to
 * create fluid applications with animated transitions and flowing user interfaces. Using Qt Quick, you can 
 * describe your user interface using QML, a JavaScript-like language that lets you declare user interface 
 * elements and how they relate; the Qt Quick runtime does most of the heavy lifting in the implementation 
 * of your application.
 * 
 * When the quick project is created, the qml file appears in the qml.qrc folder. The first file look something
 * like below:

import QtQuick 2.12
import QtQuick.Window 2.12

Window {    
    visible: true   
    width: 640    
    height: 480    
    title: qsTr("Hello World")
}

 * 
 * If you know JavaScript, the syntax of this might look a little familiar, but it's still different. The 
 * first two lines are the import statements; they indicate which classes should be available to the QML 
 * runtime. At a minimum, all of your Qt Quick applications must import QtQuick, as this one does.
 * 
 * Note that the value of the title property is actually the result of a function call to the qsTr function,
 * which is Qt's built-in localization function. This looks at application resources to return the localized 
 * version of Hello World if it has been provided.
 * 
 * It's worth making a note of the qsTr function here; you can use this if you want your application to support 
 * multiple languages.
 */