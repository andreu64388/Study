package pages.hardcore;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;

import java.time.Duration;

public class EmailListPage extends AbstractPage{
    private static final String PAGE_URL = "https://yopmail.com/ru/wm";
    @FindBy(xpath = "//button[@id='refresh']")
    WebElement refreshEmailsButton;

    @FindBy(xpath = "//iframe[@id='ifinbox']")
    WebElement inboxFrame;

    @FindBy(xpath = "//iframe[@id='ifmail']")
    WebElement emailFrame;

    @FindBy(xpath = "//div[@id='mail']/descendant::h3[2]")
    WebElement estimateEmailCost;

    @Override
    protected EmailListPage openPage() {
        driver.navigate().to(PAGE_URL);
        return this;
    }

    public EmailListPage(WebDriver driver) {
        super(driver);
        PageFactory.initElements(driver, this);
    }

    public void openEmail() {
        while (!inboxFrame.isDisplayed()) {
            new WebDriverWait(driver, Duration.ofSeconds(WAIT_TIME_IN_SECONDS)).until(ExpectedConditions.elementToBeClickable(refreshEmailsButton));
            refreshEmailsButton.click();
        }
    }

    public String getEstimateEmailCost() {
        driver.switchTo().frame(emailFrame);
        new WebDriverWait(driver, Duration.ofSeconds(WAIT_TIME_IN_SECONDS)).until(ExpectedConditions.visibilityOf(estimateEmailCost));
        return estimateEmailCost.getText();
    }
}
