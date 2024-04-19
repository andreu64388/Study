package epam.testing.pages;

import epam.testing.models.product.IProduct;
import epam.testing.utils.factories.ProductFactory;
import lombok.SneakyThrows;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;

import java.util.List;

import static epam.testing.utils.Logger.*;

public class ProductPage extends Page {
  @FindBy(xpath = "//*[@id=\"content\"]/div[2]/div[1]/div/div[1]/h1")
  private WebElement productNameDiv;

  @FindBy(xpath = "//*[@id=\"button-cart\"]")
  private WebElement addToCartButton;

  @FindBy(xpath = "//*[@id=\"cart-total\"]")
  private WebElement countElementInCart;

  @FindBy(xpath = "//*[@id=\"button-wishlist\"]/i")
  private WebElement addToWishListButton;

  public ProductPage(WebDriver driver) {
    this(driver, null);
  }

  public ProductPage(WebDriver driver, String baseUrl) {
    super(driver, baseUrl);
  }

  public String getProductName() {
    return productNameDiv.getText();
  }

  public boolean compareName() {
    IProduct product = ProductFactory.createInstance();
    String name = productNameDiv.getText();

    if (name.contains(product.getName())) {
      log("Product name is correct");
      return true;
    }
    warn("Product name is incorrect");
    return false;
  }

  public void addToCart() {
    addToCartButton.click();
    log("Add to cart button clicked");
  }

  @SneakyThrows
  public void createOrder() {
    Thread.sleep(2000);
    WebElement createOrderButton = driver.findElement(By.xpath("//*[@id=\"cartpopup\"]/button[2]"));
    createOrderButton.click();
    log("Create order button clicked");
  }

  @SneakyThrows
  public void removeFromCart(String name) {
    Thread.sleep(3000);
    List<WebElement> productsNames = driver.findElements(By.cssSelector(".mini-cart-info tr > .name"));
    List<WebElement> productsRemoves = driver.findElements(By.cssSelector(".mini-cart-info tr > .remove > img"));

    String _name;
    WebElement removeButton;

    for (int i = 0; i < productsNames.size(); i++) {
      _name = productsNames.get(i).getText();
      removeButton = productsRemoves.get(i);

      if (!_name.equals(name)) continue;

      removeButton.click();
      break;
    }

    log(name + " удален из корзины");
  }

  public int getCountElementInCart() {
    try {
      return Integer.parseInt(countElementInCart.getText());
    } catch (Exception e) {
      WebElement countElementInCart = driver.findElement(By.xpath("//*[@id=\"cart-total\"]"));
      return Integer.parseInt(countElementInCart.getText());
    }
  }

  public void addToFavorite() {
    addToWishListButton.click();
  }
}
