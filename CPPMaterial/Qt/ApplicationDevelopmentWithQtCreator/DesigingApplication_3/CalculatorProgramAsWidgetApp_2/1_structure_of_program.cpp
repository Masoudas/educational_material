/**
 * We build the famous calculator program here. The program consists of a main window, as well as a result 
 * window. The pointer to result window is held inside the main window. Naturlich, we have four bottons for
 * plus, minus, times and divide, and we need to define slots for their click signals. The role of the slots
 * is to read the content of two line editors we've put in our program, and ensure that they're given the
 * correct numberic values. Once this is verified, we calculate the result of the operation inside this class.
 * The calculated value is then emitted via a custom signal called computed (which takes a float as argument.)
 * This result is printed on the result window. 
 * 
 * Note that a line editer has the nice property that once we get its text, we can convert it to a float, using
 * intrinsic functions of it. The function also takes the reference to a bool, setting it to true, if conversion
 * to float has been successful:
 * 
 * LineEditor::text()::toFloat(bool);
 * 
 * In that sense, here's the header file of the mainWindow class:
 
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    typedef QPair<float, float> Arguments;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Arguments arguments();

public slots:
    void aboutButtonClicked();
    void plusButtonClicked();
    void minusButtonClicked();
    void timesButtonClicked();
    void divideButtonClicked();
    void showResult(float r);

signals:
    void computed(float f);

private:
    Ui::MainWindow *ui;
    ResultWindow* results = nullptr;
};

 */