package epam.testing.pages;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindAll;
import org.openqa.selenium.support.FindBy;

import static epam.testing.utils.Logger.*;

import java.util.List;

public class ProductsPage extends Page {
  @FindAll({@FindBy(css = ".product-grid > div > .name > a")})
  private List<WebElement> products;

  public ProductsPage(WebDriver driver) {
    super(driver, null);
  }

  public void clickOnFirst () {
    String href = products.get(0).getAttribute("href");
    driver.get(href);

    log("Clicked on first product");
  }
}
