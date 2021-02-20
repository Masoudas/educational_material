package GoF.Behavioral.Command;

import java.util.ArrayList;
import java.util.List;

/**
 * 
 * Notice how the action handler is unaware of the content of the Order. The order is 
 * just being received and executed by the broker. No knowledge of the content is required.
 * Notice in this implementation how the StockBroker takes orders from the clients
 * (or commands) and then fills them later on when it finds them appropriate!
 * It could also execute the orders at once.
 * 
 * 
 */

/**
 * The Order interface executes a command. This would be either buying or
 * selling a stock
 */
interface Order {
    public void execute();
}

class Stock {
    String name = "Stock Name";

    public Stock(String name) {
        this.name = name;
    }

    public void buy() {
        System.out.println("Stock is bought");
    }

    public void sell() {
        System.out.println("Stock is sold");
    }
}

class BuyStockCommand implements Order {
    Stock stock;

    public BuyStockCommand(Stock stock) {
        this.stock = stock;
    }

    @Override
    public void execute() {
        stock.buy();
    }

}

class SellStockCommand implements Order {
    Stock stock;

    public SellStockCommand(Stock stock) {
        this.stock = stock;
    }

    @Override
    public void execute() {
        stock.sell();
    }

}

class StockBroker {
    List<Order> orders = new ArrayList<>();

    public void takeOrdersFromClinet(Order order) {
        orders.add(order);
    }

    public void executeOrders() {
        for (Order order : orders) {
            order.execute();
        }
    }
}