package epam.testing;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;

import java.util.ArrayList;
import java.util.List;

public class NewestPage {
  private final WebDriver driver;

  @FindBy(xpath = "//*[@id=\"cat_102\"]")
  private WebElement catElement;

  @FindBy(xpath = "//*[@id=\"max_price\"]")
  private WebElement maxPriceElement;

  public NewestPage(WebDriver driver) {
    this.driver = driver;
    PageFactory.initElements(driver, this);
  }

  public void open() {
    driver.get("https://superlama.by/latest");
  }

  public void clickOnCatElement() {
    catElement.submit();
  }

  public void setMaxPrice(String maxPrice) {
    maxPriceElement.clear();
    maxPriceElement.sendKeys(maxPrice);
  }

  public List<Integer> getPrices() {
    By prodsSelector = By.cssSelector(".product-grid > div > .cat-info > .price");
    List<WebElement> element = driver.findElements(prodsSelector);
    List<Integer> prices = new ArrayList<Integer>();

    for (WebElement el : element) {
      String price = el.getText();
      price = price.substring(0, price.length() - 4);
      price = price.replace(",", ".");
      prices.add((int) (Double.parseDouble(price) * 100));
    }

    return prices;
  }
}
