package epam.testing.models.order;

public class Order implements IOrder {
  private final String phone;
  private final String vk;
  private final String comment;

  public Order(IOrder order) {
    this(order.getPhone(), order.getVk(), order.getComment());
  }

  public Order(String phone, String vk, String comment) {
    this.phone = phone;
    this.vk = vk;
    this.comment = comment;
  }

  @Override
  public String getPhone() {
    return phone;
  }

  @Override
  public String getVk() {
    return vk;
  }

  @Override
  public String getComment() {
    return comment;
  }
}
