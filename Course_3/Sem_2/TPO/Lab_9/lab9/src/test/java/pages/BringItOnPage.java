package pages;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindAll;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;

import java.time.Duration;
import java.util.List;

public class BringItOnPage extends AbstractPage{
    private static final String HOMEPAGE_URL = "https://pastebin.com";

    public BringItOnPage(WebDriver driver) {
        super(driver);
    }

    @FindBy(xpath = "//textarea[@id='postform-text']")
    private WebElement newText;
    @FindBy(xpath = "//select[@id='postform-format']/following::span[1]")
    private WebElement selectHighlighting;
    @FindBy(xpath = "//select[@id='postform-expiration']/following::span[1]")
    private WebElement selectExpiration;
    @FindAll(
            {
                    @FindBy(xpath = "//li[contains(@class,'select2-results__option')]")
            }
    )
    private List<WebElement> activeSelectTwoOptions;
    @FindBy(xpath = "//input[@id='postform-name']")
    private WebElement pasteName;
    @FindBy(xpath = "//button[text()='Create New Paste']")
    private WebElement newPasteButton;

    public void writeNewText(String name) {
        newText.sendKeys(name);
    }
    public void chooseHighlighting(String highlighting) {
        setSelectOption(selectHighlighting, highlighting);
    }

    public void chooseExpiration(String expiration) {
        setSelectOption(selectExpiration, expiration);
    }

    public void writeName(String name) {
        pasteName.sendKeys(name);
    }

    public SavedPastePage clickCreateNewPasteButton() {
        newPasteButton.click();
        new WebDriverWait(driver, Duration.ofSeconds(WAIT_TIME_IN_SECONDS)).until(CustomCondition.changingURL(driver.getCurrentUrl()));
        return new SavedPastePage(driver);
    }

    public void setSelectOption(WebElement select, String optionValue) {
        select.click();
        for (WebElement selectOption : activeSelectTwoOptions) {
            if (selectOption.getText().trim().equals(optionValue.trim())) {
                selectOption.click();
                new WebDriverWait(driver, Duration.ofSeconds(WAIT_TIME_IN_SECONDS)).until(ExpectedConditions.invisibilityOf(selectOption));
                break;
            }
        }
    }

    public BringItOnPage openPage() {
        driver.get(HOMEPAGE_URL);
        new WebDriverWait(driver, Duration.ofSeconds(WAIT_TIME_IN_SECONDS)).until(CustomCondition.jQueryAJAXsCompleted());
        return this;
    }
}
