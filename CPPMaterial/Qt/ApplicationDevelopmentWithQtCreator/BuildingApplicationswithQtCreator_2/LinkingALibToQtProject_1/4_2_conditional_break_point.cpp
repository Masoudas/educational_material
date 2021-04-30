/**
 * We can also conditionally break the execution when a variable changes; this is called a conditional breakpoint 
 * or a data breakpoint. For example, let's put a loop in our main function and break as we execute the loop. 
 * 
 * Consider the following main function:
 
 #include <QCoreApplication>
 #include <QDebug>

 int main(int argc, char *argv[]) 
{ 
    QCoreApplication a(argc, argv);

    int values[] = { 6, 7, 8 }; 
    for(unsigned int i = 0; i < sizeof(values)/sizeof(int); i++)
    {
        qDebug() << values[i] << "! = " << 
          MathFunctions::factorial(values[i]);
    }

    return a.exec(); 
}

 * Now, set a break point at the first include line, then execute the code. Step over until the for loop, then 
 * right-click on i in the right pane and choose Add Data Breakpoint at Object's Address from the Add Data 
 * Breakpoint submenu.. Now, everytime we execute the code using F5, we stop when i changes.
 * 
 * 
 */