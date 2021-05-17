/**
 * From the Qt documentation we read "Signals and slots are used for communication between objects. The signals 
 * and slots mechanism is a central feature of Qt and probably the part that differs most from the features 
 * provided by other frameworks. Signals and slots are made possible by Qt's meta-object system."
 * 
 * In GUI programming, when we change one widget, we often want another widget to be notified. More generally, we 
 * want objects of any kind to be able to communicate with one another. For example, if a user clicks a Close 
 * button, we probably want the window's close() function to be called.
 * 
 * Other toolkits achieve this kind of communication using callbacks. A callback is a pointer to a function, so 
 * if you want a processing function to notify you about some event you pass a pointer to another function (the 
 * callback) to the processing function. The processing function then calls the callback when appropriate. While
 * successful frameworks using this method do exist, callbacks can be unintuitive and may suffer from problems in 
 * ensuring the type-correctness of callback arguments.
 * 
 * In Qt, we have an alternative to the callback technique: We use signals and slots. A signal is emitted when a 
 * particular event occurs. Qt's widgets have many predefined signals, but we can always subclass widgets to add 
 * our own signals to them. A slot is a function that is called in response to a particular signal. Qt's widgets 
 * have many pre-defined slots, but it is common practice to subclass widgets and add your own slots so that you 
 * can handle the signals that you are interested in.
 * 
 * The signals and slots mechanism is type safe: The signature of a signal must match the signature of the 
 * receiving slot. (In fact a slot may have a shorter signature than the signal it receives because it can ignore 
 * extra arguments.) Since the signatures are compatible, the compiler can help us detect type mismatches when 
 * using the function pointer-based syntax. The string-based SIGNAL and SLOT syntax will detect type mismatches 
 * at runtime. Signals and slots are loosely coupled: A class which emits a signal neither knows nor cares which 
 * slots receive the signal. Qt's signals and slots mechanism ensures that if you connect a signal to a slot, the 
 * slot will be called with the signal's parameters at the right time. Signals and slots can take any number of 
 * arguments of any type. They are completely type safe.
 * 
 * All classes that inherit from QObject or one of its subclasses (e.g., QWidget) can contain signals and slots.
 * Signals are emitted by objects when they change their state in a way that may be interesting to other objects. 
 * This is all the object does to communicate. It does not know or care whether anything is receiving the signals 
 * it emits. This is true information encapsulation, and ensures that the object can be used as a software component.
 * 
 * Slots can be used for receiving signals, but they are also normal member functions. Just as an object does not 
 * know if anything receives its signals, a slot does not know if it has any signals connected to it. This ensures 
 * that truly independent components can be created with Qt.
 * 
 * You can connect as many signals as you want to a single slot, and a signal can be connected to as many slots as 
 * you need. It is even possible to connect a signal directly to another signal. (This will emit the second signal 
 * immediately whenever the first is emitted.)
 * 
 * 
 */