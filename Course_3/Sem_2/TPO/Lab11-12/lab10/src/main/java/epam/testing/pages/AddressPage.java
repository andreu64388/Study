package epam.testing.pages;

import epam.testing.intefaces.IErrorDetector;
import epam.testing.intefaces.ISubmite;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;

public class AddressPage extends Page implements ISubmite, IErrorDetector {
  @FindBy(xpath = "//*[@id=\"account_address_main_firstname\"]")
  private WebElement fioBlock;

  @FindBy(xpath = "//*[@id=\"account_address_main_city\"]")
  private WebElement cityBlock;

  @FindBy(xpath = "//*[@id=\"account_address_main_city\"]")
  private WebElement indexBlock;

  @FindBy(xpath = "//*[@id=\"account_address_main_address_1\"]")
  private WebElement addressBlock;

  @FindBy(xpath = "//*[@id=\"simpleaddress\"]/div[2]/div[2]/a/span")
  private WebElement submitButton;

  public AddressPage(WebDriver driver) {
    super(driver, "https://superlama.by/index.php?route=account/simpleaddress/insert");
  }

  public void addAddress(String fio, String city, String index, String address) {
    fioBlock.clear();
    cityBlock.clear();
    indexBlock.clear();
    addressBlock.clear();

    fioBlock.sendKeys(fio);
    cityBlock.sendKeys(city);
    indexBlock.sendKeys(index);
    addressBlock.sendKeys(address);
  }

  @Override
  public void submit() {
    submitButton.click();
  }

  public boolean isThereError() {
    return driver.findElements(org.openqa.selenium.By.cssSelector(".simplecheckout-error-text")).size() > 0;
  }
}
