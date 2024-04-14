package tests;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.edge.EdgeDriver;
import org.testng.Assert;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;
import pages.ICanWinTestPage;
///pastebin.com Selenium
public class ICanWinTest {
    private WebDriver driver;

    @BeforeMethod(alwaysRun = true)
    public void driverSetup() {
        driver = new EdgeDriver();
    }

    @Test
    public void tryNewPateCreated() {
        System.setProperty("webdriver.edge.driver", "E:\\Rubish\\Drivers\\msedgedriver.exe");


        ICanWinTestPage iCanWinTestPage = new ICanWinTestPage(driver);
        iCanWinTestPage.openPage();
        iCanWinTestPage.writeNewText("Andrey");
        iCanWinTestPage.chooseExpiration("1 Day");
        iCanWinTestPage.writeName("Andr");
        String oldUrl = driver.getCurrentUrl();
        iCanWinTestPage.clickCreateNewPasteButton();
        Assert.assertNotEquals(oldUrl, driver.getCurrentUrl());
    }

    @AfterMethod(alwaysRun = true)
    public void browserClose() {
        driver.quit();
    }
}
