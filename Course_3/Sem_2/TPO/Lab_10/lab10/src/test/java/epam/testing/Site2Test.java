package epam.testing;

import org.junit.*;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.edge.EdgeDriver;

import java.util.List;

public class Site2Test {
  private static WebDriver driver;
  private NewestPage page;

  @BeforeClass()
  public static void init() {
    driver = new EdgeDriver();
  }

  @Before()
  public void openPages() {
    page = new NewestPage(driver);
    page.open();
    page.setMaxPrice("40");
    page.clickOnCatElement();
  }

  @Test()
  public void shouldBeRedirectedToProductsPage() throws InterruptedException {
    List<Integer> prices = page.getPrices();
    for (Integer price : prices) {
      Assert.assertTrue(price <= 40);
    }
  }

  @AfterClass()
  public static void close() {
    driver.quit();
  }
}
