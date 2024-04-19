package epam.testing.utils.factories;

import epam.testing.models.product.IProduct;
import epam.testing.models.product.Product;
import epam.testing.utils.PropsReader;

public class ProductFactory {
  public static IProduct createInstance() {
    IProduct propsReader = new PropsReader("search.properties");
    return new Product(propsReader);
  }
}
