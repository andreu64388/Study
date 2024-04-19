package epam.testing.pages;

import epam.testing.models.product.Product;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;

import static epam.testing.utils.Logger.*;

import java.util.ArrayList;
import java.util.List;

public class NewestPage extends Page {
  @FindBy(css = "#min_price")
  private WebElement minPriceInput;

  @FindBy(css = "#max_price")
  private WebElement maxPriceInput;

  @FindBy(xpath = "//*[@id=\"content\"]/div[1]/div/div[2]/select")
  private WebElement sortSelection;

  public NewestPage(WebDriver driver) {
    super(driver, "https://superlama.by/latest");
  }

  public void choiceCategory(String categoryName) {
    List<WebElement> inputs = driver.findElements(org.openqa.selenium.By.cssSelector("#filter_categories input"));
    List<WebElement> labels = driver.findElements(org.openqa.selenium.By.cssSelector("#filter_categories label"));

    for (int i = 0; i < labels.size(); i++) {
      if (labels.get(i).getText().equals(categoryName)) {
        inputs.get(i).click();
        break;
      }
    }

    log("Category chosen");
  }

  public void setMinPrice(String minPrice) {
    minPriceInput.clear();
    minPriceInput.sendKeys(minPrice);

    log("Min price set");
  }

  public void setMaxPrice(String maxPrice) {
    maxPriceInput.clear();
    maxPriceInput.sendKeys(maxPrice);

    log("Max price set");
  }

  public List<Product> getProducts() {
    List<Product> prods = new ArrayList<>();
    List<WebElement> productsNames = driver.findElements(org.openqa.selenium.By.cssSelector(".product-grid .name"));
    List<WebElement> productsPrices = driver.findElements(org.openqa.selenium.By.cssSelector(".product-grid .price"));

    String price, name;

    for (int i = 0; i < productsNames.size(); i++) {
      name = productsNames.get(i).getText();
      price = productsPrices.get(i).getText();
      if(name.equals("")) continue;
      prods.add(new Product(name, toDouble(price)));
    }

    log("Products got");

    return prods;
  }

  private double toDouble(String _price) {
    String price = _price;

    if(price.contains("-")) {
      price = price.replaceAll(" ", "");
      String[] prices = price.split("-");
      return (toDouble(prices[1]) + toDouble(prices[0])) / 2;
    }

    price = onlyNumsAndDoth(price);
    price = price.replace(",", ".");
    return Double.parseDouble(price);
  }

  private String onlyNumsAndDoth(String str) {
    return str.replaceAll("[^0-9.]", "");
  }

  public void clickOnSortOptions() {
    sortSelection.click();
    WebElement option = driver.findElement(By.xpath("//*[@id=\"content\"]/div[1]/div/div[2]/select/option[2]"));
    option.click();

    log("Sort option clicked");
  }
}
