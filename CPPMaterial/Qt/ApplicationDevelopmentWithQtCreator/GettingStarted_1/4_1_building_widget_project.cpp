/**
 * After creating the project, Qt Creator creates a default subclass of the class that provides the 
 * platform's basic window in the mainwindow.h and mainwindow.cpp files and creates a form that will contain 
 * the widgets for your application's window.
 * 
 * If we click on the ui file of the project, it will take us to the design window.
 * 
 * To create the first window, we click on the "type here" and remove the menu bar. We can for example put
 * a label in the frame.
 * 
 * Next, we add a button, then we right click it on it, and select slots (which is the events.) Then we go
 * to the event handler, and there we first add the QApplication header, and after, we use the static exit
 * method of the QApplication class to exit the app when clicking this button. (We could do the same thing
 * with std::exit as well.)
 * 
 * Once finished, we debug the program, and our window appears right there.
 * 
 * 
 */