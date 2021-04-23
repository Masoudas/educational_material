/**
 * Just like OpenCV, Qt consists of modules, which are in essense from the documentation of the project:
 *  -   QtCore	Core non-graphical classes used by other modules.
 *  -   QtGUI	Base classes for graphical user interface (GUI) components. Includes OpenGL.
 *  -   QtMultimedia	Classes for audio, video, radio and camera functionality.
 *  -   QtMultimedia Widgets	Widget-based classes for implementing multimedia functionality.
 *  -   QtNetwork	Classes to make network programming easier and more portable.
 *  -   QtQML	Classes for QML and JavaScript languages.
 *  -   QtQuick	A declarative framework for building highly dynamic applications with custom user 
 *              interfaces.
 *  -   Qt Quick Controls	Provides lightweight QML types for creating performant user interfaces for 
 *                          desktop, embedded, and mobile devices. These types employ a simple styling 
 *                          architecture and are very efficient.
 *  -   Qt Quick Dialogs	Types for creating and interacting with system dialogs from a Qt Quick 
 *                          application.    
 *  -   Qt Quick Layouts	Layouts are items that are used to arrange Qt Quick 2 based items in the user 
 *                          interface.
 *  -   QtQuickTest	        A unit test framework for QML applications, where the test cases are written as 
 *                          JavaScript functions.
 *                          Note: The binary compatibility guarantee does not apply to Qt Quick Test. 
 *                          However, it will remain source compatible.
 *  -   QtSQL	            Classes for database integration using SQL.
 *  -   QtTest	            Classes for unit testing Qt applications and libraries.
 *                          Note: The binary compatibility guarantee does not apply to Qt Test. However, 
 *                          it will remain source compatible.
 *  -   QtWidgets	        Classes to extend Qt GUI with C++ widgets.
 * 
 * Note: If you use qmake to build your projects, the Qt Core and Qt GUI modules are included by default. To 
 * link only against Qt Core, add the following line to your .pro file:
 * Qt -= GUI
 */