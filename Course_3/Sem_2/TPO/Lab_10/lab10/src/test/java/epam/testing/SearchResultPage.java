package epam.testing;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;
import org.openqa.selenium.support.ui.WebDriverWait;

import java.time.Duration;

public class SearchResultPage {
  private final WebDriver driver;

  private WebElement linkToProductPage;
  private String href = "";

  public SearchResultPage(WebDriver driver) {
    this.driver = driver;
  }

  public void clickOnProduct() throws InterruptedException {
    linkToProductPage = driver.findElement(By.xpath("//*[@id=\"content\"]/div[2]/div[1]/div/div[3]/a"));

    String href = linkToProductPage.getAttribute("href");
    this.href = href;
    driver.get(href);
  }

  public String getHref() {
    return href;
  }
}
