package epam.testing.pages;

import epam.testing.intefaces.ISubmite;
import epam.testing.models.auth_info.IAuthInfo;
import epam.testing.utils.factories.AuthInfoFactory;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import static epam.testing.utils.Logger.*;
public class AuthPage extends Page implements ISubmite {
  private final IAuthInfo authInfo;

  @FindBy(xpath = "//*[@id=\"content\"]/div/div[2]/div[1]/form/div/div[1]/input")
  private WebElement emailInput;

  @FindBy(xpath = "//*[@id=\"content\"]/div/div[2]/div[1]/form/div/div[4]/input")
  private WebElement passwordInput;

  @FindBy(xpath ="//*[@id=\"content\"]/div/div[2]/div[1]/form/div/input")
  private WebElement submitButton;

  public AuthPage(WebDriver driver) {
    super(driver, "https://superlama.by/login");
    this.authInfo = AuthInfoFactory.createInstance();
  }

  public void signIn() {
    emailInput.sendKeys(authInfo.getEmail());
    passwordInput.sendKeys(authInfo.getPassword());
    submit();
    log("Signed in");
  }

  public void submit() {
    submitButton.click();
  }
}
