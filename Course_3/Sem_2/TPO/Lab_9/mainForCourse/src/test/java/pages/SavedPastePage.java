package pages;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;

public class SavedPastePage extends AbstractPage {
    @FindBy(xpath = "//div[contains(@class, 'top-buttons')]/div[contains(@class, 'right')]/a[contains(text(), 'raw')]")
    private WebElement rawLink;

    @FindBy(xpath = "//div[contains(@class,'highlighted-code')]/descendant::a")
    private WebElement resultHighlighting;

    @FindBy(xpath = "//textarea[contains(@class,'js-paste-raw')]")
    private WebElement resultRawPaste;

    @FindBy(xpath = "//pre")
    private WebElement rawPaste;

    protected SavedPastePage(WebDriver driver) {
        super(driver);
    }
    public String getPageTitle() {
        return driver.getTitle();
    }

    public String getHighlighting() {
        return resultHighlighting.getText();
    }

    public String getRawPaste() {
        rawLink.click();
        String paste = rawPaste.getText().trim();
        driver.navigate().back();
        return paste;
    }

    @Override
    protected AbstractPage openPage() {
        return null;
    }
}
