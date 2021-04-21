/**
 * The code file looks something like this:
#include <QCoreApplication> 
#include <iostream> 
 
using namespace std; 

int main(int argc, char *argv[]) 
{ 
    QCoreApplication a(argc, argv); 
    cout << "Hello world!"; 
 
    return a.exec(); 
}

 * The QCoreApplication task handles the entire system startup for an application, and every Qt Console app 
 * needs to create one and call its exec method as part of your main method. It sets up Qt's event handler 
 * and provides a bunch of porting helpers to determine things such as your application directory, library 
 * paths, and other details.
 * 
 * For a console application, that's all you need; you can freely mix and match Qt classes with the C++ 
 * standard library and Standard Template Library (STL) although once you master Qt's foundation classes, 
 * many STL constructs might feel somewhat limiting.
 * 
 * Finally, note that we can both build the project, or debug it.
 */