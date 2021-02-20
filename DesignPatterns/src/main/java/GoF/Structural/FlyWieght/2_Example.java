package GoF.Structural.FlyWieght;

/**
 * Suppose we want to create a forest of a million trees. Creating a tree object
 * for each is memory demanding. Instead, we opt for a situation where we keep
 * the location (extrinsic state) in one place, and tree information in another
 * (say type for example as an string, or leaf color as string).
 * 
 * Note here that when user asks for a tree, we return an object name Tree, which
 * would still have the location info too.
 */

import java.awt.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import javax.swing.JFrame;

/** This would be the shared object. */
class TreeType {
    private Color leafColor;
    private String type;

    public TreeType(Color leafColor, String type) {
        this.leafColor = leafColor;
        this.type = type;
    }

    public void draw(Graphics g, int x, int y) {
        g.setColor(Color.BLACK);
        g.fillRect(x - 1, y, 3, 5);
        g.setColor(leafColor);
        g.fillOval(x - 5, y - 10, 10, 10);
    }
}

/**
 * This would be the class returned to the user.
 */
class Tree {
    private int x;
    private int y;
    private TreeType type;

    public Tree(int x, int y, TreeType type) {
        this.x = x;
        this.y = y;
        this.type = type;
    }

    public void draw(Graphics g) {
        type.draw(g, x, y);
    }
}

/**
 * This is the factory for creating the shared state.
 */
class TreeFactory {
    static Map<String, TreeType> treeTypes = new HashMap<>();

    public static TreeType getTreeType(String type, Color color) {
        TreeType result = treeTypes.get(type);
        if (result == null) {
            result = new TreeType(color, type);
            treeTypes.put(type, result);
        }
        return result;
    }
}

/**
 * This is the class that mushes everything together.
 */
class Forest extends JFrame {
    private ArrayList<Tree> trees = new ArrayList<>();

    public void plantTree(int x, int y, String name, Color color, String type) {
        TreeType treeType = TreeFactory.getTreeType(type, color);
        Tree tree = new Tree(x, y, treeType);
        trees.add(tree);
    }

    @Override
    public void paint(Graphics graphics) {
        for (Tree tree : trees) {
            tree.draw(graphics);
        }
    }
}


