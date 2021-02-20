package GoF.Behavioral.Visitor;

import java.util.Iterator;

/**
 * The equipment class is a composite here, which has implementations like
 * FloppyDisk, Card, Chassis and Bus. We add an equipment visitor, to allow for
 * visitors to visit.
 * 
 * As an example, the PricingVisitor is a visitor, that is capable of computing
 * the price of entire composite hierarchy, by visiting them all. Or
 * InventoryVisitor can sum the number of each particular equipment we have.
 */

interface Equipment {
    String Name();

    int Power();

    int NetPrice();

    int DiscountPrice();

    void Add(Equipment e);

    void Remove(Equipment e);

    Iterator<Equipment> CreateIterator();

    void Accept(EquipmentVisitor v);
};

class FloppyDisk implements Equipment {

    @Override
    public String Name() {
        return null;
    }

    @Override
    public int Power() {
        return 0;
    }

    @Override
    public int NetPrice() {
        return 0;
    }

    @Override
    public int DiscountPrice() {
        return 0;
    }

    @Override
    public void Add(Equipment e) {
    }

    @Override
    public void Remove(Equipment e) {
    }

    @Override
    public Iterator<Equipment> CreateIterator() {
        return null;
    }

    @Override
    public void Accept(EquipmentVisitor v) {
    }

}

class Card implements Equipment {

    @Override
    public String Name() {
        return null;
    }

    @Override
    public int Power() {
        return 0;
    }

    @Override
    public int NetPrice() {
        return 0;
    }

    @Override
    public int DiscountPrice() {
        return 0;
    }

    @Override
    public void Add(Equipment e) {
    }

    @Override
    public void Remove(Equipment e) {
    }

    @Override
    public Iterator<Equipment> CreateIterator() {
        return null;
    }

    @Override
    public void Accept(EquipmentVisitor v) {
    }

}

class Chassis implements Equipment {

    @Override
    public String Name() {
        return null;
    }

    @Override
    public int Power() {
        return 0;
    }

    @Override
    public int NetPrice() {
        return 0;
    }

    @Override
    public int DiscountPrice() {
        return 0;
    }

    @Override
    public void Add(Equipment e) {
    }

    @Override
    public void Remove(Equipment e) {
    }

    @Override
    public Iterator<Equipment> CreateIterator() {
        return null;
    }

    @Override
    public void Accept(EquipmentVisitor v) {
    }

}

class Bus implements Equipment {

    @Override
    public String Name() {
        return null;
    }

    @Override
    public int Power() {
        return 0;
    }

    @Override
    public int NetPrice() {
        return 0;
    }

    @Override
    public int DiscountPrice() {
        return 0;
    }

    @Override
    public void Add(Equipment e) {
    }

    @Override
    public void Remove(Equipment e) {
    }

    @Override
    public Iterator<Equipment> CreateIterator() {
        return null;
    }

    @Override
    public void Accept(EquipmentVisitor v) {
    }

}

interface EquipmentVisitor {
    void VisitFloppyDisk(FloppyDisk fd);

    void VisitCard(Card c);

    void VisitChassis(Chassis c);

    void VisitBus(Bus b);
    // and so on for other concrete subclasses of Equipment
}

class PricingVisitor implements EquipmentVisitor {
    int price = 0;

    @Override
    public void VisitFloppyDisk(FloppyDisk fd) {
        price += fd.NetPrice();
    }

    @Override
    public void VisitCard(Card c) {
        price += c.NetPrice();
    }

    @Override
    public void VisitChassis(Chassis c) {
        price += c.NetPrice();
    }

    @Override
    public void VisitBus(Bus b) {
        price = b.NetPrice();
    }

    public int getTotalPrice() {
        return price;
    }
}

class InventoryVisitor implements EquipmentVisitor {
    int fd;
    int card;
    int chassis;
    int b;

    @Override
    public void VisitFloppyDisk(FloppyDisk fd) {
        this.fd++;
    }

    @Override
    public void VisitCard(Card c) {
        this.card++;
    }

    @Override
    public void VisitChassis(Chassis c) {
        chassis++;
    }

    @Override
    public void VisitBus(Bus b) {
        this.b++;
    }

}