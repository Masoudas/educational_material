package GoF.Behavioral.Memento;

/**
 * In this example we use a MoveCommand object (which is a Command pattern) to
 * move around graphical objects. The Execute and UnExecute commands are
 * responsible for moving around the objects.
 */

class Graphic {
    public void Move(Point point) {
    };
}

class Point {

}

class MoveCommand {
    private ConstraintSolverMemento _state;
    private Point _delta;
    private Graphic _target;

    public MoveCommand(Graphic target, Point delta) {

    }

    public void Execute() {
        ConstraintSolver solver = ConstraintSolver.Instance();
        _state = solver.CreateMemento();

        // create a memento
        _target.Move(_delta);
        solver.Solve();
    }

    public void Unexecute() {
        ConstraintSolver solver = ConstraintSolver.Instance();
        _target.Move(-_delta);  // Here we say move back -delta
        solver.SetMemento(_state);
        // restore solver state
        solver.Solve();

    };

}

/**
 * Constraint solver is a singleton.
 */
class ConstraintSolver {
    // nontrivial state and operations for enforcing
    // connectivity semantics
    private static ConstraintSolver _instance;

    static ConstraintSolver Instance() {
        return _instance;
    };

    void Solve() {
    };

    void AddConstraint(Graphic startConnection, Graphic endConnection) {
    };

    void RemoveConstraint(Graphic startConnection, Graphic endConnection) {
    };

    ConstraintSolverMemento CreateMemento() {
        return null;
    };

    void SetMemento(ConstraintSolverMemento memento) {

    };
}

/**
 * The memento interface is private and only known to the Constraint solver.
 * 
 */
interface IConstrantSolverMemento {
    // There will be some getter and setter methods here, for assigning a number of
    // parameters.
};

class ConstraintSolverMemento implements IConstrantSolverMemento {

}
