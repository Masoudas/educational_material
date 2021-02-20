package GoF.Structural.Composite;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * Let's say we want to model a computer, with equipments, buses, chassis,
 * containters and so forth.
 * 
 * Equipment interface would be the component interface (note that it has
 * default implementations in original example). Then floppy disk would be an
 * equipment. 
 * 
 * We also have CompositeEquipment (could be a computer too), that
 * implements the same interface. See for example how the net price is being
 * calculated. It calls the net price of the child componets, which in turn call
 * their net price. Notice also that a composite equipment (it's a node not a leaf) may or may
 * not add its own price before adding the price of child nodes. Now we see that
 * for example that a chassis is a composite component.
 * 
 */

interface Equipment {
    String Name();

    int Power();

    int NetPrice();

    int DiscountPrice();

    void Add(Equipment e);

    void Remove(Equipment e);

    Iterator<Equipment> CreateIterator(); // Default implementation for this would be return empty iterator!
};

class FloppyDisk implements Equipment {
    String name = "Floppy disk";
    List<Equipment> equipment = new ArrayList<>();

    @Override
    public String Name() {
        return name;
    }

    @Override
    public int Power() {
        return 0;
    }

    @Override
    public int NetPrice() {
        return 1;
    }

    @Override
    public int DiscountPrice() {
        return 0;
    }

    @Override
    public void Add(Equipment e) {
        equipment.add(e);
    }

    @Override
    public void Remove(Equipment e) {
        equipment.remove(e);
    }

    @Override
    public Iterator<Equipment> CreateIterator() {
        return equipment.iterator();
    }

}

/**This would be the definition of a node component, where it has several child (or leaf).
 * Hence, a chassis would be a composite component.
 */
class CompositeComponent implements Equipment {
    String name = "";
    List<Equipment> equipment = new ArrayList<>();

    @Override
    public String Name() {
        return name;
    }

    @Override
    public int Power() {
        return 0;
    }

    @Override
    public int NetPrice() {
        Iterator<Equipment> i = CreateIterator();
        int total = 0;
        while (i.hasNext()) {
            total = i.next().NetPrice();
        }
        return total;
    }

    @Override
    public int DiscountPrice() {
        return 0;
    }

    @Override
    public void Add(Equipment e) {
        equipment.add(e);
    }

    @Override
    public void Remove(Equipment e) {
        equipment.remove(e);
    }

    @Override
    public Iterator<Equipment> CreateIterator() {
        return equipment.iterator();
    }

}

class Chassis extends CompositeComponent{
    String name = "Chassis";

}