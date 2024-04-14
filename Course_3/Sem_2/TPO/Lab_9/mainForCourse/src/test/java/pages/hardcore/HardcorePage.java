package pages.hardcore;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;

public class HardcorePage extends AbstractPage {
    private static final String HOMEPAGE_URL = "https://cloud.google.com/";
    @FindBy(xpath = "//*[@id=\"kO001e\"]/div[2]/div[1]/div/div[2]/div[2]/div[1]/form/div")
    private WebElement searchButton;

    @FindBy(xpath = "//*[@id=\"kO001e\"]/div[2]/div[1]/div/div[2]/div[2]/div[1]/form/div/input")
    private WebElement searchInput;

    public HardcorePage(WebDriver driver) {
        super(driver);
        PageFactory.initElements(driver, this);
    }

    public HardcorePage openPage() {
        driver.get(HOMEPAGE_URL);
        return this;
    }

    public SearchResultPage startSearch(String searchText) {
        searchButton.click();
        searchInput.sendKeys(searchText + "\n");
        return new SearchResultPage(driver);
    }

}
