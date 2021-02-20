package GoF.Behavioral.ChainOfResponsibility;

/**
 * Consider the widget application, where every element has a help button
 * associated with it.
 * 
 * Help handler is the chain of responsibility interface. Topic is the topic of
 * help the interface can handle. If it's -1, it doesn't handle any type of
 * help. Now every widget that has a help button should implement this
 * interface. For example, Widget extends this class, and also assigns a
 * successor in case it has one and that it has a help topic.
 * 
 * Note that dialog is the parent of a widget, hence higher in the food chain.
 * 
 * On top, there's the application, which is ultimately responsible for any
 * handling that may not occur at the buttom of the chain. It's the predecessor
 * for every helper that's out there.
 * 
 * 
 */

class Topic {
    int t = -1;
}

class HelpHandler {
    HelpHandler _successor;
    Topic t;

    // Default constructor, for defining no handler and no topic
    HelpHandler() {
        this._successor = null;
        this.t = new Topic();
    }

    HelpHandler(HelpHandler h, Topic t) {
        this._successor = h;
        this.t = t;
    }

    boolean HasHelp() {
        return _successor == null;
    }

    void SetHandler(HelpHandler h, Topic t) {
        this._successor = null;
        this.t = new Topic();
    };

    void HandleHelp() {
        if (_successor != null) {
            _successor.HandleHelp();
        }
    }
}

class Widget extends HelpHandler {
    Widget _parent;

    Widget() {
        super();
        _parent = null;
    }

    Widget(Widget parent, Topic t) {
        super(parent, t);  // Setting the HelpHandler successor via the super constructor! Akh!
        _parent = parent;

    }
}

class Button extends Widget {
    Button() {
        super();
        _parent = null;
    }

    Button(Widget d, Topic t) {
        super(d, t); // Setting the HelpHandler successor via the super constructor! Akh!
        _parent = d;
    }

    void HandleHelp() {
        if (HasHelp()) {
            // offer help on the button
        } else {
            this.HandleHelp();
        }
    }

}

class Dialog extends Widget {

    Dialog() {
        super();

    };

    Dialog(HelpHandler h, Topic t) {
        SetHandler(h, t);
    };

    void HandleHelp() {
        // Widget operations that Dialog overrides...
        // ...
    }
}

class Application extends HelpHandler {

    Application(Topic t) {
        super(null, t);
    }

    void HandleHelp() {
        // application-specific operations...
    };

}