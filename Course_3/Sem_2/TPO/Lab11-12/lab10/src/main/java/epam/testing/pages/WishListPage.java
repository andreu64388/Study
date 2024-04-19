package epam.testing.pages;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindAll;

import java.util.List;

public class WishListPage extends Page {
  public WishListPage(WebDriver driver) {
    super(driver, "https://superlama.by/wishlist");
  }

  public List<String> getProductsNames() {
    return driver.findElements(By.cssSelector(".wishlist-info tr > .name > a"))
            .stream()
            .map(el -> el.getText())
            .collect(java.util.stream.Collectors.toList());
  }

  public boolean isThereProduct(String name) {
    return getProductsNames().contains(name);
  }
}
