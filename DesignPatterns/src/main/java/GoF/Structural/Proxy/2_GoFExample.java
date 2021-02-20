package GoF.Structural.Proxy;

import java.io.File;

/**
 * We implement a virtual proxy here, which is a proxy that creates expensive
 * objects on demand. Like for example with an image, it keeps all the
 * information (like the size, etc), inside before actually having to display
 * it.
 * 
 * The graphics interface is the common interface for all graphical tools. Image
 * implements the Graphics to let the users see an image. It also let's them
 * resize an image. Here as we can see, image proxy has the same interface as
 * image. In C++ terms, it serves as a pointer to the original image. As we can
 * see, it keeps all the information inside of it about the image in the
 * constructor, but the image pointer is initially set to null. Moreover, the
 * Draw method draws the image if it has been cached, and the handleEvent method
 * forwards the event to the Image class.
 * 
 */

interface Graphic {
    void Draw(Point at);

    void HandleMouse(Event event);

    Point GetExtent();

    void Load(File from);

    void Save(File to);
}

class Image implements Graphic {
    Image(String file) { // loads image from a file

    };

    public void Draw(Point at) {
    };

    public void HandleMouse(Event event) {
    };

    public Point GetExtent() {
        return null;
    };

    public void Load(File from) {
    };

    public void Save(File to) {
    };
}

class ImageProxy implements Graphic {
    Image _image;
    Point _extent;
    String _fileName;

    ImageProxy(String fileName) {
        _fileName = fileName;
        _extent = null; // don't know extent yet
        _image = null;
    };

    public void Draw(Point at) {
        GetImage().Draw(at);
    };

    public void HandleMouse(Event event) {
        _image.HandleMouse(event);
    };

    public Point GetExtent() {
        if (_extent == null) {
            _extent = GetImage().GetExtent();
        }
        return _extent;
    };

    public void Load(File from) {
    };

    public void Save(File to) {
    };

    protected Image GetImage() {
        if (_image == null) {
            _image = new Image(_fileName);
        }
        return _image;
    }
}

class Point {
}

class Event {
}