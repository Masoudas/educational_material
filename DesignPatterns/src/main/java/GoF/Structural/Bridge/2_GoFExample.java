package GoF.Structural.Bridge;

/**
 * Windows is the abstraction interface. WindowImp is the implementation
 * abstraction.
 * 
 * Subclasses of Window define the different kinds of windows the application
 * might use, such as application windows, icons, transient windows for dialogs,
 * floating palettes of tools, and so on.
 * 
 * The AppleWindowImp is an example of a system dependent window implementation.
 * 
 */
class View {
    void DrawOn(Window w){

    }
}

class Point {

}

class Coord {

}

abstract class Window {
    Window(View contents) {

    }

    // requests handled by window
    abstract void DrawContents();

    abstract void Open();

    abstract void Close();

    abstract void Iconify();

    abstract void Deiconify();

    // requests forwarded to implementation
    abstract void SetOrigin(Point at);

    abstract void SetExtent(Point extent);

    abstract void Raise();

    abstract void Lower();

    abstract void DrawLine(Point p, Point p1);

    abstract void DrawRect(Point p, Point p1);

    abstract void DrawPolygon(Point[] p, int n);

    abstract void DrawText(char c, Point p);

    protected WindowImp GetWindowImp() {
        return _imp;
    };

    protected View GetView() {
        return _contents;
    };

    private WindowImp _imp;
    private View _contents; // the window's contents
}

abstract class WindowImp {
    protected WindowImp() {
    };

    abstract void ImpTop();

    abstract void ImpBottom();

    abstract void ImpSetExtent(Point p);

    abstract void ImpSetOrigin(Point p);

    abstract void DeviceRect(Coord p1, Coord p2, Coord p3, Coord p4);

    abstract void DeviceText(char c1, Coord c2, Coord c3);

    abstract void DeviceBitmap(char c1, Coord c2, Coord c3);
}

class ApplicationWindow extends Window
{        
    ApplicationWindow(View contents) {
        super(contents);
    }

    void DrawContents() {
        GetView().DrawOn(this);
    }

    @Override
	void Open() {

	}

    @Override
	void Close() {

	}

    @Override
	void Iconify() {

	}

    @Override
	void Deiconify() {

	}

    @Override
	void SetOrigin(Point at) {

	}

    @Override
	void SetExtent(Point extent) {

	}

    @Override
	void Raise() {

	}

    @Override
	void Lower() {

	}

    @Override
	void DrawLine(Point p, Point p1) {

	}

    @Override
	void DrawRect(Point p, Point p1) {

	}

    @Override
	void DrawPolygon(Point[] p, int n) {

	}

    @Override
	void DrawText(char c, Point p) {

    }
}

class AppleWindowImp extends WindowImp {
 
}