package epam.testing.pages;

import epam.testing.intefaces.IErrorDetector;
import epam.testing.intefaces.ISubmite;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;

import static epam.testing.utils.Logger.*;

public class ChangePasswordPage extends Page implements ISubmite, IErrorDetector {
  @FindBy(xpath = "//*[@id=\"content\"]/div/form/div/table/tbody/tr[1]/td[2]/input")
  private WebElement newPassword;

  @FindBy(xpath = "//*[@id=\"content\"]/div/form/div/table/tbody/tr[2]/td[2]/input")
  private WebElement repeatNewPassword;

  @FindBy(xpath = "//*[@id=\"content\"]/div/form/div/table/tbody/tr[3]/td[2]/input")
  private WebElement submitButton;

  public ChangePasswordPage(WebDriver driver) {
    super(driver, "https://superlama.by/cpass");
  }

  public void changePassword(String password) {
    newPassword.sendKeys(password);
    repeatNewPassword.sendKeys(password);
    submit();

    log("Password changed");
  }

  public void submit() {
    submitButton.click();
  }

  public boolean isThereError() {
    WebElement error = driver.findElement(org.openqa.selenium.By.xpath("//*[@id=\"content\"]/div/form/div/table/tbody/tr[1]/td[2]/span"));
    return error.isDisplayed();
  }
}
