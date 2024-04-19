package epam.testing.pages;

import epam.testing.models.order.IOrder;
import epam.testing.utils.factories.OrderFactory;
import lombok.SneakyThrows;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;

import static epam.testing.utils.Logger.log;

public class CreateOrderPage extends Page {
  public CreateOrderPage(WebDriver driver) {
    super(driver, null);
  }

  @SneakyThrows
  public boolean createOrder() {
    IOrder order = OrderFactory.createInstance();

    WebElement takeOnMyOwnInput = driver.findElement(By.xpath("//*[@id=\"pickup.pickup\"]"));

    WebElement vkInput = driver.findElement(By.cssSelector("#checkout_customer_main_fax"));
    WebElement commentInput = driver.findElement(By.cssSelector("#checkout_customer_main_comment"));
    WebElement confirmLink = driver.findElement(By.xpath("//*[@id=\"simplecheckout_button_confirm\"]"));

    vkInput.sendKeys(order.getVk());
    commentInput.sendKeys(order.getComment());

    takeOnMyOwnInput.click();

    confirmLink.click();

    log("Take on my own input clicked");

    return driver.getCurrentUrl().equals("https://superlama.by/index.php?route=checkout/success");
  }
}
