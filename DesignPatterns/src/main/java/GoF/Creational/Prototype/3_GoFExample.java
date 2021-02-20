package GoF.Creational.Prototype;

/**
 * The MazePrototypeFactory gets the protypes of all objects (wall, door, etc)
 * here. Each object has a clone method of its own. When the protype factory is
 * called to create an object, it just clones an object (see the methods in the
 * factory and how they use the clone method). Notice how after cloning an object Door,
 * we have an initializer method to set the content of the class anew. Point being the
 * class becomes mutuable with this form of implementation of clone. A point to remember
 * is that GoF asks us that the return type of clone should be the type we expect from the
 * clone method, not for example in the case of the Java interface an Object class. This
 * because they say the client is not responsible for the cast. In Java as we recall,
 * the return type of an overridden method can change too, and it better be covariant of
 * the original type! In any case, in Maze, I've set the return type to Maze, rather than
 * object.
 * 
 * The most important thing here is that MazePrototypeFactory is not limited to
 * these defined types. It can be used with subtypes of Maze or Wall or any
 * other class to create classes, and when we provide the prototypes for the
 * factory, it just uses the clones to create the maze.
 * 
 */

class Maze {
    @Override
    protected Maze clone() {
        try {
            return (Maze)super.clone();
        } catch (CloneNotSupportedException e) {
            return null;
        }
    }
}

class Wall {
    @Override
    protected Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            return null;
        }
    }

}

class Door {
    Room _room1;
    Room _room2;

    public Door(Door door){}

    public void Initialize(Room room1, Room room2){};
    public void Enter(){};
    Room OtherSideFrom(Room room){
        return _room1;
    };

    @Override
    protected Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            return null;
        }
    }

}

class Room {
    @Override
    protected Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            return null;
        }
    }

}

// MazeFactory is a class we created in the abstract factory pattern.
interface MazeFactory {
    Maze MakeMaze();

    Wall MakeWall();

    Room MakeRoom(int n);

    Door MakeDoor(Room r1, Room r2);
}

class MazePrototypeFactory implements MazeFactory {
    Maze _prototypeMaze;
    Room _prototypeRoom;
    Wall _prototypeWall;
    Door _prototypeDoor;

    public MazePrototypeFactory(Maze m, Wall w, Room r, Door d) {
        _prototypeMaze = m;
        _prototypeWall = w;
        _prototypeRoom = r;
        _prototypeDoor = d;
    }

    @Override
    public Maze MakeMaze() {
        return (Maze) _prototypeMaze.clone();
    }

    @Override
    public Wall MakeWall() {
        return (Wall) _prototypeWall.clone();
    }

    @Override
    public Room MakeRoom(int n) {
        return (Room) _prototypeRoom.clone();
    }

    @Override
    public Door MakeDoor(Room r1, Room r2) {
        Door door = (Door) _prototypeDoor.clone();

        door.Initialize();

        return door;
    }
}