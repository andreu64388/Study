package pages.hardcore;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;
import org.openqa.selenium.support.ui.WebDriverWait;
import pages.CustomCondition;

import java.time.Duration;

public class GenerateTmpEmailPage extends AbstractPage {
    private static final String HOMEPAGE_URL = "https://yopmail.com/ru/email-generator";

    @FindBy(xpath = "//button[@id='cprnd']")
    WebElement copyEmailButton;

    @FindBy(xpath = "//button/span[text()='Проверить почту']")
    WebElement checkEmailButton;

    public GenerateTmpEmailPage(WebDriver driver) {
        super(driver);
        PageFactory.initElements(driver, this);
    }

    public GenerateTmpEmailPage openPage() {
        driver.get(HOMEPAGE_URL);
        return this;
    }

    public void copyEmailButtonClick() {
        new WebDriverWait(driver, Duration.ofSeconds(WAIT_TIME_IN_SECONDS)).until(CustomCondition.isButtonEnabled(copyEmailButton));
        copyEmailButton.click();
    }

    public EmailListPage checkEmailButtonClick() {
        checkEmailButton.click();
        return new EmailListPage(driver);
    }

}
