package pages.hardcore;

import org.openqa.selenium.WebDriver;

public abstract class AbstractPage
{
    protected WebDriver driver;
    protected abstract AbstractPage openPage();
    protected final int WAIT_TIME_IN_SECONDS = 40;
    protected AbstractPage(WebDriver driver)
    {
        this.driver = driver;
    }
}