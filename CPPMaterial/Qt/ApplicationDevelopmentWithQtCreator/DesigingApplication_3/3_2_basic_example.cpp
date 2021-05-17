/**
 * In the following example, we create a class called value_container, which contains an int value. As soon as
 * the set_value of this class is set, it emits a signal called value_changed. Then, a command line printer that
 * is subscribed to this signal prints the value of the signal on the command line. The slot is called printer.
 * 
 * Another slot for this signal is just a lambda, which prints another message, which we use to show how signals
 * can be connected to lambda slots.
 
#include <QCore>
struct value_container : QObject{
Q_OBJECT


public:
    value_container(printer* p){
        QObject::connect(this, value_container::value_changed, p, Printer::print)

        // Connecting a simple lambda to this signal as well.
        QObject::connect(this, value_container::value_changed, engine, [](int){
            qDebug() << "The lambda slot receiving the value\n";
        })
    }

    set_value(int val){
        this->val = val;
        emit value_changed(this->val);   // All slots are called first.

        qDebug << "Calling the slots has terminated\n";
    }

signals:
    void value_changed(int val);    // Our signal has a single argument.

private:
    int val = 0;

}

struct Printer : QObject {
Q_Object

private slots:  // Setting the slots private to show that the can be connected to signals regardless
    void printer(int val){
        qDebug << "The value received from the signal in the printer object is: " << val << "\n";
    }
}

int main(){
    Printer p{};
    Value_container c{&p};

    c.set(10);
    c.set(20);
}

 */