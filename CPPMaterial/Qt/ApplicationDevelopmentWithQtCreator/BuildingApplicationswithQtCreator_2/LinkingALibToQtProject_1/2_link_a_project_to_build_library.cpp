/**
 * Note: The following linking process is possible ONLY if we choose qmake as our make system. If we go for
 * CMake, we have to manually link against the library inside the cmake folder.
 * 
 * Note: In the following exercise, make sure that you have both the include and library on the path you
 * want to link to. That is, the header files and the library files are ready.
 * 
 * So now that we've a shared library, we want to use it in project. To link a library to a project, say
 * MathTest library in our case, it suffices to right click on the project, then add library. Then we choose 
 * an external library, and then define the path and everything. Once we're finished, the project is linked 
 * to the library.
 * 
 * Having done the above task, the following is added to the .pro file:

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-MathFunctions-Desktop-Debug/ -lMathFunctions
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-MathFunctions-Desktop-Debug/ -lMathFunctionsd
else:unix: LIBS += -L$$PWD/../build-MathFunctions-Desktop-Debug/ -lMathFunctions

INCLUDEPATH += $$PWD/../build-MathFunctions-Desktop-Debug
DEPENDPATH += $$PWD/../build-MathFunctions-Desktop-Debug

 */