package tests;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.edge.EdgeDriver;
import org.testng.Assert;
import org.testng.AssertJUnit;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;
import pages.BringItOnPage;
import pages.SavedPastePage;

public class BringItOnTest {
    private WebDriver driver;
    private static final String PASTETEXT = "git config --global user.name  \"New Sheriff in Town\"\n" + "git reset $(git commit-tree HEAD^{tree} -m \"Legacy code\")\n" + "git push origin master --force";
    private static final String PASTE_NAME = "how to gain dominance among developers";
    private static final String PASTE_HIGHLIGHTING = "Bash";
    private static final String PASTE_EXPIRATION = "10 Minutes";
    SavedPastePage savedPastePage;

    @BeforeMethod
    public void createNewPaste() {
        System.setProperty("webdriver.edge.driver", "E:\\Rubish\\Drivers\\msedgedriver.exe");
        driver = new EdgeDriver();
        BringItOnPage bringItOnPage = new BringItOnPage(driver);
        bringItOnPage.openPage();
        bringItOnPage.writeNewText(PASTETEXT);
        bringItOnPage.chooseHighlighting(PASTE_HIGHLIGHTING);
        bringItOnPage.chooseExpiration(PASTE_EXPIRATION);
        bringItOnPage.writeName(PASTE_NAME);
        savedPastePage = bringItOnPage.clickCreateNewPasteButton();
    }

    @Test
    public void compareHighlighting() {
        AssertJUnit Assert = null;
        Assert.assertEquals(savedPastePage.getHighlighting(),PASTE_HIGHLIGHTING);
    }
    @Test
    public void compareTitle() {
        Assert.assertEquals(savedPastePage.getPageTitle().split("-")[0].trim(), PASTE_NAME);
    }
    @Test
    public void compareText() {
        Assert.assertEquals(savedPastePage.getRawPaste(), PASTETEXT);
    }

    @AfterMethod
    public void     browserTearDown() {
        driver.quit();
        driver = null;
    }
}
