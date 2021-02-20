package GoF.Behavioral.Memento;

/**
 * In this simple example, we see how a memento can be defined for an object.
 * The management of the memento is by the caretaker (in terms of saving it and
 * giving it back). The caretaker could perhaps be an observer (object being
 * observable). So every time the Originator's state changes, it registers with
 * the care taker. On the other hand, the care taker, can return the state, and
 * Originator can apply it. Ideally, we expect the Memento to have to a private
 * interface, which only the originator have access to (friend in C++).
 */

class Originator {
    private String state;
    CareTaker careTaker;

    public Originator(CareTaker careTaker) {
        this.careTaker = careTaker;
    }

    public void setState(String state) {
        this.state = state;
        this.registerToCareTaker();
    }

    public String getState() {
        return state;
    }

    private void registerToCareTaker() {
        careTaker.addMemento(new Memento(state));
    }

    public void setStateFromMemento(Memento memento) {
        this.state = memento.getState();
    }

}

class Memento {
    private String state;

    public Memento(String state) {
        this.state = state;
    }

    public String getState() {
        return state;
    }

}

class CareTaker {
    Memento[] mementos = new Memento[5];
    int counter = 0;

    public void addMemento(Memento memento) {
        mementos[counter++] = memento;
    }

    public Memento getState(int n) {
        return mementos[n];
    }
}

class Orchestrator {
    public static void main(String[] args) {
        CareTaker careTaker = new CareTaker();
        Originator originator = new Originator(careTaker);

        originator.setState("state 1");
        originator.setState("state 2");
        originator.setState("state 3");

        originator.setStateFromMemento(careTaker.getState(1));
        System.out.println("Returning back to the previous state: " + originator.getState());

    }

}