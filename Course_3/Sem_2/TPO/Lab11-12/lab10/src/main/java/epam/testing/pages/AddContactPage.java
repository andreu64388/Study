package epam.testing.pages;

import epam.testing.intefaces.ISubmite;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;

public class AddContactPage extends Page implements ISubmite {
  @FindBy(xpath = "//*[@id=\"account_info_main_email\"]")
  private WebElement email;
  @FindBy(xpath = "//*[@id=\"account_info_main_firstname\"]")
  private WebElement firstName;
  @FindBy(xpath = "//*[@id=\"account_info_main_telephone\"]")
  private WebElement telephone;
  @FindBy(xpath = "//*[@id=\"account_info_main_fax\"]")
  private WebElement vk;
  @FindBy(xpath = "//*[@id=\"simpleedit\"]/div[2]/div[2]/a/span")
  private WebElement submitButton;

  public AddContactPage(WebDriver driver) {
    super(driver, "https://superlama.by/simpleedit");
  }

  public void addContact(String email, String fio, String telephone, String vk) {
    this.firstName.clear();
    this.email.clear();
    this.telephone.clear();
    this.vk.clear();

    this.email.sendKeys(email);
    this.firstName.sendKeys(fio);
    this.telephone.sendKeys(telephone);
    this.vk.sendKeys(vk);
  }

  public void submit() {
    submitButton.click();
  }

  public int getErrorCount() {
    return driver.findElements(org.openqa.selenium.By.cssSelector(".simplecheckout-error-text")).size();
  }

    public void sumbit() {
    }
}
