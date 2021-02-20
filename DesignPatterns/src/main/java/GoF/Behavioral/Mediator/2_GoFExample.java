package GoF.Behavioral.Mediator;

import java.util.List;

/**
 * In this example, we try to implement a dialogbox (user puts a text,
 * highlights it, and selects some font and some properties, and based on that
 * the text font change), with mediator for some of the widgets.
 * 
 * The dialogDirector is the mediator interface. Widget is abstract base class
 * for widgets that knows its director.
 * 
 * The ListBox, EntryField, and Button are subclasses of Widget for specialized
 * user interface elements. ListBox provides a GetSelection operation to get the
 * current selection, and EntryField's SetText operation puts new text into the
 * field.
 * 
 * The FontDialogDirector class mediates between widgets in the dialog box.
 * FontDialogDirector is a subclass of DialogDirector. It's interesting that
 * this director is also responsible for creating the widgets it needs to do
 * it's action. This is mostly because if this weren't the case, we would have
 * had to pass several references to it of different buttons.
 */

interface DialogDirector {
    void ShowDialog();

    void WidgetChanged(Widget widget);

    void CreateWidgets();
}

class MouseEvent {
}

abstract class Widget {
    Widget(DialogDirector director) {
        _director = director;
    }

    void Changed() {
        _director.WidgetChanged(this);
    };

    abstract void HandleMouse(MouseEvent event);

    // ...
    private DialogDirector _director;
};

class ListBox extends Widget {
    ListBox(DialogDirector d) {
        super(d);
    };

    String GetSelection() {
    };

    void SetList(List<Character> listItems) {
    };

    void HandleMouse(MouseEvent event) {
    }
    // ...
};

class EntryField extends Widget {
    EntryField(DialogDirector d) {
        super(d);
    };

    void SetText(String text) {
    }

    String GetText() {
        return null;
    }

    void HandleMouse(MouseEvent event) {
    }
}

class Button extends Widget {
    Button(DialogDirector d) {
        super(d);
    }

    void SetText(String text) {
    }

    void HandleMouse(MouseEvent event) {
        Changed();
    }
}

class FontDialogDirector implements DialogDirector {
    Button _ok;
    Button _cancel;
    ListBox _fontList;
    EntryField _fontName;

    FontDialogDirector() {
    }

    public void WidgetChanged(Widget theChangedWidget) {
        if (theChangedWidget == _fontList) {
            _fontName.SetText(_fontList.GetSelection());
        } else if (theChangedWidget == _ok) {
            // apply font change and dismiss dialog
            // ...
        } else if (theChangedWidget == _cancel) {
            // dismiss dialog
        }
    }

    public void CreateWidgets() {
        _ok = new Button(this);
        _cancel = new Button(this);
        _fontList = new ListBox(this);
        _fontName = new EntryField(this);
        // fill the listBox with the available font names
        // assemble the widgets in the dialog
    }

    public void ShowDialog() {

    }

};
