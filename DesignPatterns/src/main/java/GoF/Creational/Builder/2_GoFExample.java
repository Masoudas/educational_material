package GoF.Creational.Builder;

/**
 * The MazeGame here is the director. It takes as argument a builder interface
 * to create a Maze. The builder of the maze can change in this implementation,
 * but it's clients don't have to, as is apparent in the MazeGame class. Or if
 * we look at the createComplexMaze(), we see that we can use the encapsulation
 * of how an object should be created is used to create a complex Maze. It's
 * important to note that MazeBuilder does not create the Maze itself, but
 * rather, it prepares the construction of the maze.
 * 
 * A more interesting case here is the CountingMazeBuilder, which only counts
 * how many doors and walls would have been needed had we wanted to build a
 * maze!
 */
class Maze {

}

interface MazeBuilder {
    public void BuildMaze();

    public void BuildRoom(int room);

    public void BuildDoor(int roomFrom, int roomTo);

    default public Maze GetMaze() {
        return null;
    }
};

class MazeGame {
    public Maze createMaze(MazeBuilder builder) {
        builder.BuildMaze();
        builder.BuildRoom(1);
        builder.BuildRoom(2);
        builder.BuildDoor(1, 2);
        return builder.GetMaze();
    }

    public Maze CreateComplexMaze(MazeBuilder builder) {
        builder.BuildRoom(1);
        // ...
        builder.BuildRoom(1001);
        return builder.GetMaze();
    }

}

class StandardMazeBuilder implements MazeBuilder {
    public class Direction {
    };

    public class Room {
    };

    StandardMazeBuilder() {
    };

    public void BuildMaze() {
    };

    public void BuildRoom(int no) {
    };

    public void BuildDoor(int no, int no1) {
    };

    public Maze GetMaze() {
        return null;
    };

    public Direction CommonWall(Room room1, Room room2) {
        return null;
    };

    Maze _currentMaze;
}

class CountingMazeBuilder implements MazeBuilder {
    private int _doors;
    private int _rooms;

    public class Direction {
    };

    public CountingMazeBuilder() {
    };

    public void BuildMaze() {
    };

    public void BuildRoom(int r) {
    };

    public void BuildDoor(int d1, int d2) {
    };

    public void AddWall(int r, Direction d) {
    };

    public void GetCounts(int n1, int n2) {
    };

};
