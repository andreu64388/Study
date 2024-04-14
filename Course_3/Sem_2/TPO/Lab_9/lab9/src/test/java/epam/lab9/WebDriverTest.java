package epam.lab9;

import org.openqa.selenium.*;
import org.openqa.selenium.edge.EdgeDriver;

public class WebDriverTest {
  public static void main(String[] args) throws InterruptedException {


    System.setProperty("webdriver.edge.driver", "E:\\Rubish\\Drivers\\msedgedriver.exe");


    WebDriver driver  = new EdgeDriver();
    driver.get("https://superlama.by");

    By searchInputSelector = By.xpath("//*[@id=\"top\"]/ul/li[2]/div/input");
    By searchButtonSelector = By.xpath("//*[@id=\"top\"]/ul/li[2]/div/div");

    WebElement searchInput = driver.findElement(searchInputSelector);
    WebElement searchButton = driver.findElement(searchButtonSelector);

    searchInput.sendKeys("Мини-фигурки Genshin Impact (8 см)");
    searchButton.click();

    Thread.sleep(5000);
    By linkToProductPageSelector = By.xpath("/html/body/div[4]/div[2]/div[3]/div[2]/div[1]/div/div[1]/a");
    WebElement linkToProductPage = driver.findElement(linkToProductPageSelector);
    Thread.sleep(5000);

    String href = linkToProductPage.getAttribute("href");
    driver.get(href);
    Thread.sleep(2000);

    driver.quit();
  }
}
