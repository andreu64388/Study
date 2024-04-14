package pages;

import org.openqa.selenium.JavascriptExecutor;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;
import org.openqa.selenium.support.pagefactory.AjaxElementLocatorFactory;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;


import java.time.Duration;
import java.util.List;

public class SearchResultPage extends AbstractPage {

    @FindBy(xpath = "//a[contains(@class,'gs-title')]/b")
    private List<WebElement> searchResults;

    protected SearchResultPage(WebDriver driver) {
        super(driver);
    }

    public CalculatorPage goToResult(String resultName) {
        for (WebElement searchResult : searchResults) {
            if (searchResult.getText().equals(resultName)) {
                new WebDriverWait(driver, Duration.ofSeconds(WAIT_TIME_IN_SECONDS)).until(ExpectedConditions.elementToBeClickable(searchResult)).click();
                break;
            }
        }
        return new CalculatorPage(driver);
    }


    @Override
    protected AbstractPage openPage() {
        return null;
    }
}
