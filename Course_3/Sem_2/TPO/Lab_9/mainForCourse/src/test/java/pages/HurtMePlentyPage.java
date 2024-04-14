package pages;

import org.openqa.selenium.Keys;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;


public class HurtMePlentyPage extends AbstractPage{
    private static final String HOMEPAGE_URL = "https://cloud.google.com/";

    @FindBy(xpath = "//*[@id=\"kO001e\"]/div[2]/div[1]/div/div[2]/div[2]/div[1]/div/div")
    private WebElement searchButton;

    @FindBy(xpath = "//*[@id=\"i5\"]")
    private WebElement searchInput;


    public HurtMePlentyPage(WebDriver driver) {
        super(driver);
    }

    public HurtMePlentyPage openPage() {
        driver.get(HOMEPAGE_URL);
        return this;
    }

    public SearchResultPage startSearch(String searchText) {
        searchButton.click();
        searchInput.sendKeys(searchText);
        searchInput.sendKeys(Keys.RETURN);
        return new SearchResultPage(driver);
    }
}
