/**
 * Note that mainwindow is created in a separate cpp file, together with a header file. Inside it, we find
 * the following content"
 
Header file:
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

TU file:
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QApplication::exit();
}

 * First of all, we see that the window inherits from QMainWindow class. Also of importance is the fact of
 * receiving an instance of QWidget in the constructor of the class, which is the widget this window is
 * on. This is passed a nullptr, because we don't have such a widget yet.
 * 
 * Of interest is the annotation of the slot handler, which is written as "private slot." The event handler 
 * afterall is a method.
 * 
 * Finally, our mainWindow class is just a wrapper for the Ui::MainWindow class of Qt, which is the window
 * of Qt, held in the class as a pointer.
 */