package GoF.Structural.FlyWieght;

import javax.swing.JFrame;
import javax.swing.text.AttributeSet.FontAttribute;

/**
 * GoF tries to implement a text-editor using the flyweight pattern. For the
 * sake of argument, we will refer to each of the 128 charcaters we seek (almost
 * same size as ASCII), using integers.
 * 
 * The point of this example as we see it is that Glyph is the extrinsic state (having
 * font size and other info), and a draw method, whereas CHaracter is the intrinsic state.
 * So CHaracter implementents this Glyph and, and that makes the total number of Glyphs (
 * or CHars for that matter) 128. So whenever we need to paint a CHar, we just feed a GlyphContext
 * to it and it will draw it.
 */

class GlyphFactory {
    private final int NCHARCODES = 128;

    private CHaracter[] _character = { null }; // This is the character flyweight we have created.

    // Use ints to create char
    public CHaracter createCharacter(int c) {
        if (_character[c] == null) {
            _character[c] = new CHaracter(c);
        }

        return _character[c];
    }

    public Row createRow() {
        return new Row();
    }

    public Column createColumn() {
        return new Column();
    }
}

class Row {

}

class Column {

}

/**
 * We can define a Glyph base class for flyweight graphical objects. Logically,
 * glyphs are Composites (see Composite (183)) that have graphical attributes
 * and can draw themselves. Here we focus on just the font attribute, but the
 * same approach can be used for any other graphical attributes a glyph might
 * have.
 */
abstract class Glyph {
    abstract public void draw(JFrame window, GlyphContext c);
    abstract public void setFont(FontAttribute font, GlyphContext g);

    abstract public void getFont();

    abstract public void first(GlyphContext g);

    abstract public void next(GlyphContext g);

    abstract boolean isDone(GlyphContext g);

    abstract Glyph current(GlyphContext g);

    abstract public void insert(Glyph g, GlyphContext c);
}


/** The CHaracter class merely stores a char  But then again, it is able to draw itself,
 * because it's a Glyph.
*/
class CHaracter extends Glyph{
    private final char _c;

    public CHaracter(int c) {
        this._c = (char) c;
    }

    // This is a graphical method that given the context and information about the
    // character location, font, size and color, draws it.
    public void draw() {

    }

    @Override
    public void draw(JFrame window, GlyphContext c) {
        // TODO Auto-generated method stub

    }

    @Override
    public void setFont(FontAttribute font, GlyphContext g) {
        // TODO Auto-generated method stub

    }

    @Override
    public void getFont() {
        // TODO Auto-generated method stub

    }

    @Override
    public void first(GlyphContext g) {
        // TODO Auto-generated method stub

    }

    @Override
    public void next(GlyphContext g) {
        // TODO Auto-generated method stub

    }

    @Override
    boolean isDone(GlyphContext g) {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    Glyph current(GlyphContext g) {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public void insert(Glyph g, GlyphContext c) {
        // TODO Auto-generated method stub

    }

}

/**
 * The glyph context here acts as repository for extrinsic states, making sure
 * that they are stored in a very efficient manner.For this end it uses a tree structure.
 */
class GlyphContext {

}