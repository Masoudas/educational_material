/**
 * To create a custom signal, first we need to inherit from QObject, and then we need to define a signal (just
 * like a slot.) Once a signal is created, to activate it, or emit the signal, use the emit example. Hence,
 * the syntax of a class that contains custom signal and slot looks something like this:

class custom_signal : QObject {
Q_Object

signals:
    void   my_signal(int, float);   // A custom signal, which as we said must always have void return.

public:
    int invoke_signal(){    // Function as part of which, a signal is emitted.
        // Do some work
        emit my_signal(10, 12.3f);  // Emit this signal to whomever listenning to it. It waits for completion
                                    // of slots.

        // Do some other work after
    }

} 

 */ 