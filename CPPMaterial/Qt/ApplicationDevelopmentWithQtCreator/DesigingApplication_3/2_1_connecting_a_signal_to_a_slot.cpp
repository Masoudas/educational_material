/**
 * Going over the simplest example of connecting a signal to a slot, the idea is that we want to open a message
 * box when an about button on our main window is clicked.
 * 
 * The (static) function that connects a signal to a slot is called QObject::connect(). This function essentially
 * requires four things:
 *      -   Pointer to object that generates the signal
 *      -   Pointer to signal member function
 *      -   Pointer to slot object
 *      -   Pointer to slot member function
 * 
 * In our case, the signal generator is the push button in the main window (ui), the signal is called clicked,
 * and we want to create an object called About_Handler, with a method called create_about_message_box. Recall
 * that based on the documentation of Qt, we can have neither stand-alone functions nor static class methos be
 * slots (the latter I'm 98% sure about, because a slot object has to be passed to the connect method.)
 * 
 * If an object is to be an object that has slots, it needs to inherit from the QObject class, and it also needs
 * to implement the Q_Object macro in the beginning of the class. Hence, the header of the class looks something
 * like this:
 
 #include <QWidgets>    // Required for building QMessageBox class.

 struct about_handler : QObject // Inherits
 {
     void create_about_message_box();
 }

 * Then, we need to implement this method. Below, I'll create a messagebox, then I set it's size, text and title,
 * then also I add from a qrc file (discussed next), a logo, which I scale to the proper size that fits the 
 * message box. Notice also how I set only an Ok button for this baby, but I can set yes or no buttons. 
 * Important notes: Notice the : before the path to Logo in QPixmap. Notice that I need to call both the exec and
 * the show methods of the box for it to be available after the call.

void About_Handler::create_about_message_box(){
        QMessageBox m{};
        m.setStandardButtons( QMessageBox::Ok );

        m.setText("This application is my first signal to slot connection");
        m.setWindowTitle("About");

        QPixmap log{":/myLogo.svg"};

        m.setIconPixmap(log.scaled(200, 200));
        m.setBaseSize(QSize(600, 320));
        m.exec();
        m.show();
}

 * Once this process is complete, we need to access the about button of the main frame, and then connect it to
 * this slot. This can be done, by noting that the button is actually in the ui instance of the frame. Hence,
 * somewhere in the frame class, preferably in the constructor, I create an instance of the handler, and then
 * connect the signal to the slot as follows:
 
// Note a pointer instance field has been added to the MainWindow class in the header file.
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), handler(new About_Handler)
{
    ui->setupUi(this);

    // Connecting ui->about to the handler. Notice that everything is passed as pointer.
    QObject::connect(ui->about, &QPushButton::clicked,  handler, &about_Handler::create_about_message_box);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete handler; // Upon destruction, we need to delete this pointer.
}
 
 * Once this is complete, we can go on ahead and execute our program and click on the about button.
 */