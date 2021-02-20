package GoF.Structural.Composite;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Objects;
import java.util.function.Consumer;

/**
 * This is an interesting example. So we try and create an structure of
 * employees, but we assume a tree structure, where an employee has
 * subordiantes. Hence, we use composite to respresent such a tree structure.
 */

class Employee implements Iterable<Employee> {
    String name;
    List<Employee> subordinates = new ArrayList<>();

    public Employee(String name) {
        this.name = name;
    }

    public void addSubordinate(Employee subordinate) {
        subordinates.add(subordinate);
    }

    public List<Employee> getSubordinates() {
        return subordinates;
    }

    /**
     * This is the method that's used in the foreach loop.
     */
    @Override
    public Iterator<Employee> iterator() {
        return subordinates.iterator();
    }

    /**
     * The goal of the for each method is to return an object every time.
     */
    @Override
    public void forEach(Consumer<? super Employee> action) {
        Objects.requireNonNull(action);
        for (Employee t : this.subordinates) {
            action.accept(t);
        }
    }

    @Override
    public String toString() {
        return name;
    }

    public static void main(String[] args) {
        Employee sophie = new Employee("Sophie");
        Employee masoud = new Employee("Masoud");
        Employee guiGuy = new Employee("GUI guy");
        Employee valentina = new Employee("Valentina");

        sophie.addSubordinate(masoud);
        sophie.addSubordinate(valentina);
        masoud.addSubordinate(guiGuy);

        Consumer<? super Employee> consumer = new Consumer<Employee>() {
            @Override
            public void accept(Employee t) {
                System.out.println(t);
    
            }
    
        };

        sophie.forEach(consumer);
        for (Employee employee : sophie) {
            System.out.println(employee);            
        }

        

    
    }

    
}