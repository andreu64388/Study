package epam.testing;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;

public class MainPage {
  private final WebDriver driver;

  @FindBy(xpath = "//*[@id=\"top\"]/ul/li[2]/div/input")
  private WebElement searchInput;
  @FindBy(xpath = "//*[@id=\"top\"]/ul/li[2]/div/div")
  private WebElement searchButton;

  @FindBy(xpath = "//*[@id=\"top\"]/ul/li[1]/a")
  private WebElement menuElement;

  public MainPage(WebDriver driver) {
    this.driver = driver;
    PageFactory.initElements(driver, this);
  }

  public void open() {
    driver.get("https://superlama.by");
  }

  public void search(String text) {
    searchInput.sendKeys(text);
    searchButton.click();
  }

  public void clickOnMenuElement() {
    menuElement.click();
  }
}
