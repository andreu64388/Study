package epam.testing.tests;

import dev.failsafe.internal.util.Assert;
import epam.testing.models.product.Product;
import epam.testing.pages.*;
import lombok.SneakyThrows;
import org.junit.jupiter.api.Test;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.edge.EdgeDriver;

import java.util.List;

public class SuperlamaTests {
  private final WebDriver driver = new EdgeDriver();

  @Test
  public void shouldBeSignedIn() {
    AuthPage authPage = new AuthPage(driver);
    authPage.signIn();
  }

  @Test
  public void shouldBeFounded() {
    MainPage mainPage = new MainPage(driver);
    mainPage.search();

    ProductsPage productsPage = new ProductsPage(driver);
    productsPage.clickOnFirst();

    ProductPage productPage = new ProductPage(driver);
    Assert.isTrue(productPage.compareName(), "Product name is incorrect");
  }

  @Test
  public void shouldBeNotOrdered() {
    AuthPage authPage = new AuthPage(driver);
    authPage.signIn();

    ProductPage productPage = new ProductPage(driver, "https://superlama.by/genshin-impact-paimon-figure");
    productPage.addToCart();
    productPage.createOrder();

    CreateOrderPage createOrderPage = new CreateOrderPage(driver);
    Assert.isTrue(!createOrderPage.createOrder(), "Order is created");
  }

  @Test
  public void shouldBeDeletedFromCart() {
    int startCount, endCount;
    ProductPage productPage1 = new ProductPage(driver, "https://superlama.by/genshin-impact-paimon-figure");
    startCount = productPage1.getCountElementInCart();
    productPage1.addToCart();
    ProductPage productPage2 = new ProductPage(driver, "https://superlama.by/genshin-impact-paimon-figure");
    productPage2.addToCart();

    productPage2.removeFromCart(productPage2.getProductName());
    endCount = productPage2.getCountElementInCart();

    Assert.isTrue((startCount + 1) == endCount, "Несоотвествие");
  }

  @SneakyThrows
  @Test
  public void shouldBeFiltered() {
    NewestPage newestPage = new NewestPage(driver);
    final Integer MAX_PRICE = 30;
    newestPage.setMaxPrice(MAX_PRICE.toString());
    Thread.sleep(6000);
    newestPage.choiceCategory("Кольца");

    Thread.sleep(6000);
    List<Product> prods = newestPage.getProducts();
    Assert.isTrue(prods.stream().filter(p -> p.getPrice() > MAX_PRICE).count() == 0, "Несоотвествие");
  }

  @Test
  public void shouldBeErrorInAddingContact() {
    AuthPage authPage = new AuthPage(driver);
    authPage.signIn();

    AddContactPage addContactPage = new AddContactPage(driver);
    addContactPage.addContact("111", "123", "12", "132");
    addContactPage.submit();

    Assert.isTrue(addContactPage.getErrorCount() == 4, "Ожидалось 4 ошибки");
  }

  @SneakyThrows
  @Test
  public void shouldBeSorted() {
    NewestPage newestPage = new NewestPage(driver);
    newestPage.clickOnSortOptions();

    Thread.sleep(5000);

    List<Product> products = newestPage.getProducts();
    for (int i = 0; i < products.size() - 2; i++) {
      Assert.isTrue(products.get(i).getPrice() <= products.get(i + 1).getPrice(), "Несоотвествие");
    }
  }

  @Test
  public void shouldBeAddedToFavorite() {
    AuthPage authPage = new AuthPage(driver);
    authPage.signIn();

    ProductPage productPage = new ProductPage(driver, "https://superlama.by/svitshot-sverhyestestvennoe-supernatural");
    productPage.addToFavorite();
    String name = productPage.getProductName();

    WishListPage wishListPage = new WishListPage(driver);
    Assert.isTrue(wishListPage.isThereProduct(name), "Несоотвествие");
  }

  @Test
  public void shouldAddressBeAdded() {
    AuthPage authPage = new AuthPage(driver);
    authPage.signIn();

    AddressPage addressPage = new AddressPage(driver);
    addressPage.addAddress("AndreyKoren", "Minsk", " ", "Minks");
    addressPage.submit();

    Assert.isTrue(addressPage.isThereError(), "Должна быть ошибка по пустому полю");
  }

  @Test
  public void shouldBeErrorInChangingOfPassword() {
    AuthPage authPage = new AuthPage(driver);
    authPage.signIn();

    ChangePasswordPage changePasswordPage = new ChangePasswordPage(driver);
    changePasswordPage.changePassword("        ");

    Assert.isTrue(changePasswordPage.isThereError(), "Должна быть ошибка по пустому полю");
  }
}

