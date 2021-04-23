/**
 * Once, "after going through so much trouble getting the project up and running," we can either std::cout
 * the result of the factorial function. Better yet, we can use it as part of the qDebug function, and
 * execute it The following is the main function of the MathTest project in our previous example:
 
#include <QCoreApplication>
#include "mathfunctions.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug("6! is %u", MathFunctions::factorial(6));
    std::getchar();
    return a.exec();
}


 * Note: We can think of qDebug sort of like the assert function, where the first argument is the message
 * rather than the check.
 * 
 * Note: qDebug has a stream savvy version as well. Hence, the previous example could have been written
 * equivalently as:
 
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "6! is" << MathFunctions::factorial(6) << '\n';
    std::getchar();
    return a.exec();
}
 * 
 * Note: qDebug isn't really a debugging log; it's an output stream for debugging information, regardless of 
 * build levels. If you want to turn off its output in release builds, you'll need to edit the .pro file. 
 * Double-click on your .pro file and add the following line:

CONFIG(release, debug|release): DEFINES += QT_NO_DEBUG_OUTPUT

 * This is another scope; it says that if your build configuration is release, add the QT_NO_DEBUG_OUTPUT 
 * preprocessor definition to the list of preprocessor definitions for the project.
 * Note that we need to rebuild the project (not just built it) to see the result.
 */