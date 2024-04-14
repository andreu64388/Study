package pages;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindAll;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;
import tests.ICanWinTest;

import java.time.Duration;
import java.util.List;



public class ICanWinTestPage extends AbstractPage {
    private static final String HOMEPAGE_URL = "https://pastebin.com";

    @FindBy(xpath = "//textarea[@id='postform-text']")
    private WebElement newText;

    @FindBy(xpath = "//select[@id='postform-expiration']/following::span[1]")
    private WebElement selectExpiration;

    @FindAll(
            {
                    @FindBy(xpath = "//li[@class='select2-results__option']")
            }
    )
    private List<WebElement> expirationOptions;

    @FindBy(xpath = "//input[@id='postform-name']")
    private WebElement pasteName;

    @FindBy(xpath = "//button[text()='Create New Paste']")
    private WebElement newPasteButton;

    public ICanWinTestPage(WebDriver driver) {
        super(driver);
    }
    public ICanWinTestPage openPage() {
        driver.get(HOMEPAGE_URL);
        new WebDriverWait(driver, Duration.ofSeconds(WAIT_TIME_IN_SECONDS)).until(CustomCondition.jQueryAJAXsCompleted());
        return this;
    }
    public void writeNewText(String name) {
        newText.sendKeys(name);
    }
    public void chooseExpiration(String expiration) {
        setSelectOption(selectExpiration, expiration);
    }
    public void writeName(String name) {
        pasteName.sendKeys(name);
    }
    public void clickCreateNewPasteButton() {
        newPasteButton.click();
        new WebDriverWait(driver, Duration.ofSeconds(WAIT_TIME_IN_SECONDS)).until(CustomCondition.changingURL(driver.getCurrentUrl()));
    }
    public void setSelectOption(WebElement select, String optionValue) {
        select.click();
        for (WebElement selectOption : expirationOptions) {
            if (selectOption.getText().trim().equals(optionValue.trim())) {
                selectOption.click();
                new WebDriverWait(driver, Duration.ofSeconds(WAIT_TIME_IN_SECONDS)).until(ExpectedConditions.invisibilityOf(selectOption));
                break;
            }
        }
    }
}

