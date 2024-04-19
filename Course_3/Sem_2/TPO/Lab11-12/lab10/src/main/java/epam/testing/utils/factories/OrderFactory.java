package epam.testing.utils.factories;

import epam.testing.models.order.IOrder;
import epam.testing.models.order.Order;
import epam.testing.utils.PropsReader;

public class OrderFactory {
  public static IOrder createInstance() {
    IOrder order = new PropsReader("order.properties");
    return new Order(order);
  }
}
