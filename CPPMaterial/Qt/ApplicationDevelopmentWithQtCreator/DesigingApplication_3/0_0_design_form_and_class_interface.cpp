/**
 * So imagine we create a ui-form like the main window, and we put some push buttons and other things inside
 * of it in the design window. Assume that the object name of this ui is called MainWindow. What Qt does is that 
 * in the UI namespace that it creates by default, it adds a class called MainWindow, which in the most barebone
 * form has the following structure:
 
namespace Ui {
    class MainWindow: public Ui_MainWindow {};
}

* Now, notice that this class inherits from another class called Ui_MainWindow. This base class is the true
* culprit here, and contains all the information (everything we put in the design window.) This is very good,
* because it does not pollute the namespace of the class. Now, when we create a MainWindow, ANOTHER class is
* created, but this one is in the GLOBAL namespace:
 
class MainWindow : public QMainWindow
{
    Q_OBJECT    // Object macro, require for every object (that has slots)

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

private:
    Ui::MainWindow *ui;
}

 * Now, notice that this class contains a pointer to an instance of UI::MainWindows. That class is actually the
 * class that contains the whole ui, and by creating a pointer instance to it, we're setting up the ui. However,
 * the slots or whatever else we want to add, is given to this MainWindow in the global namespace (I actually
 * for a second thought that there's an infinite loop here, where a class holds a pointer to itself and it
 * actually creates it in the constructor, which is impossible, because new for custom type uses a constructor!)
 * 
 * In conclusion, we have the following hierarchy:
namespace Ui{
    class UI_MainWindow;
    class MainWindow;
}
class MainWindow{
    Ui::MainWindow *ui;
}

 */