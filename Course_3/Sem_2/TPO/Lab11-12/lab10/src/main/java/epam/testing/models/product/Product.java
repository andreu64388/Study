package epam.testing.models.product;

public class Product implements IProduct {
  private final String name;
  private final Double price;

  public Product(IProduct product) {
    this(product.getName());
  }

  public Product(String name) {
    this.name = name;
    this.price = 0.0;
  }

  public Product(String name, Double price) {
    this.name = name;
    this.price = price;
  }

  @Override
  public String getName() {
    return name;
  }

  public Double getPrice() {
    return price;
  }
}
