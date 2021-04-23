/**
 * To understand how to link outside libraries to a Qt project, first we create a factorial library. Now,
 * we can create this library both in our usual editors, but this time around we'll build it in Qt creator.
 * 
 * To create a new project, just create a C++ library from the projcts. In this example, we call our lib
 * "MathFunctions." We also choose its type shared, and the main class would be MathFunctions, for which
 * Qt will build a header file as well as a TU. In the same window, we let it use QtCore modules for our
 * library, and we don't use for example GUI libraries.
 * 
 * Now, inside the mathfunctions.h add a factorial function as follows:
 
static unsigned factorial(unsigned);

 * and inside the mathfunctions.cpp add the following piece of code (recall that we musn't repeat the
 * static keyword when defining the function:)
 
unsigned MathFunctions::factorial(unsigned v){
    switch (v) {
        case 0: return 0;
        case 1: return 1;
        default: return v * factorial(v-1);
    }

}

 * Now, we can build this library as usuall with the build button, oe if we're using CMake, go ahead and
 * run and build it from the menu on the left hand side.
 * 
 * We can now see that the so (shared) library is in the build folder.
 * 
 * Note: Suppose we have a number of projects open. Then one project is going to be the active one. Right
 * click on the list of projects to select the active project. Then by clicking on the projects button,
 * we'll see a more fine grained setting on how to build the project. Select for example the debug config
 * for this project. Check that the path to the project and the build folder is correct.
 */