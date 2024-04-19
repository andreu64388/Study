package epam.testing.utils;

import epam.testing.models.auth_info.IAuthInfo;
import epam.testing.models.order.IOrder;
import epam.testing.models.product.IProduct;

public class PropsReader implements IAuthInfo, IProduct, IOrder {
  public PropsReader(String fileName) {
    try {
      System.getProperties().load(ClassLoader.getSystemResourceAsStream(fileName));
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  @Override
  public String getEmail() {
    return System.getProperty("email");
  }

  @Override
  public String getPassword() {
    return System.getProperty("password");
  }

  @Override
  public String getName() {
    return System.getProperty("product");
  }

  @Override
  public String getPhone() {
    return System.getProperty("phone");
  }

  @Override
  public String getVk() {
    return System.getProperty("vk");
  }

  @Override
  public String getComment() {
    return System.getProperty("comment");
  }
}
