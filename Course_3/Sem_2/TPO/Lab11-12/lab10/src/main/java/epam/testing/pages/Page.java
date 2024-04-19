package epam.testing.pages;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.support.PageFactory;

import static epam.testing.utils.Logger.*;

public abstract class Page {
  protected String BASE_URL;
  protected final WebDriver driver;

  public Page(WebDriver driver, String baseUrl) {
    this.BASE_URL = baseUrl;
    this.driver = driver;

    PageFactory.initElements(driver, this);

    if (baseUrl != null)
      this.open();
  }

  public void open() {
    driver.get(BASE_URL);
    log("Opened " + BASE_URL);
  }

  public void close() {
    driver.close();
    log("Closed " + BASE_URL);
  }
}
