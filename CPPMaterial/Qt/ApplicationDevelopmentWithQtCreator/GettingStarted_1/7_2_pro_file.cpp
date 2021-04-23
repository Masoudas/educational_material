/**
 * The .pro file is like the MAKEFILE for the maker of Qt, which is called qmake.
 * 
 * These files are declarative, in that you declare the relationships between the files that make up your 
 * application and qmake figures out how to build your application from there. In most cases, you'll need 
 * to make few or no changes to a .pro file, but it doesn't hurt to understand how they work.
 * 
 * For example, for a C++ library that has a mathfuncions TU and header file, the content of this file is as 
 * follows:

QT -= gui 

TARGET = MathFunctions 

TEMPLATE = lib 

CONFIG += staticlib 

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += mathfunctions.cpp 
HEADERS += mathfunctions.h 

unix {     
    target.path = /usr/lib    
    INSTALLS += target 
}

 *  QT: This variable indicates the Qt modules that your project will link against. By default, all projects 
 *      include QtCore and QtGui; there's a plethora of other modules available, which include key features 
 *      such as the WebEngine web browsing engine (QtWebEngine) and multimedia libraries (QtMultimedia). Our 
 *      assignment here indicates that we use the default Qt modules, but don't link them against QtGui.
 *  TARGET: This variable is the name of the compiled library or executable.
 *  TEMPLATE: This variable indicates the kind of template that qmake should use to generate the binary. In 
 *            our case, we're saying that it should use the template to create a lib file – a static library.
 *  CONFIG: This variable passes an additional configuration to qmake's template. Here, we say that we want a 
 *          statically linked library.
 *  DEFINES: This variable specifies preprocessors that should be set throughout the build process 
 *           (the -D option). In this case, qmake displays warning messages when detecting deprecated features 
 *           being used in our project.
 *  SOURCES and HEADERS: These variables contain lists of the source and header files that make up our project.
 *  INSTALLS: This variable indicates where the resulting build product should be installed. Here, it's set in 
 *             a scope. Scopes let you specify conditional options in qmake; the condition for the scope is a 
 *             variable or an expression, which might be true or false, and the code that follows is executed 
 *             if the variable is true. The scope at the end of this file says, if we're building for a Unix 
 *             variant, set the target.path variable to /usr/lib and the INSTALLS variable to target.
 * 
 * Another additional variable that you're likely to want to know about is LIBS. Now, LIBS indicates additional 
 * libraries against which Qt Creator should link your project.
 * 
 * Note how variables are managed: you use = for assignment, += to add an item to a list, and -= to remove an 
 * item from a list.
 */
