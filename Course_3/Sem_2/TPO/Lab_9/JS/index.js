import { assert } from "chai";
import { Builder, By, Key, until } from 'selenium-webdriver';
import {SL_Edge} from "chai/sauce.browsers.js";

const searchTest = async () => {
  const driver = new Builder().forBrowser(SL_Edge.browserName).build();
  try {
    await driver.get('https://superlama.by');
    
    const searchInputSelector = By.xpath('//*[@id="top"]/ul/li[2]/div/input');
    const searchButtonSelector = By.xpath('//*[@id="top"]/ul/li[2]/div/div');
    
    const searchInput = await driver.findElement(searchInputSelector);
    const searchButton = await driver.findElement(searchButtonSelector);
    
    const productName = "Мини-фигурки Genshin Impact (8 см)";
    
    await searchInput.sendKeys(productName);
    await searchButton.click();
    
    return true;
  } catch (err) {
    console.log(err)
    return false;
  } finally {
    await driver.quit();
  }
}

describe('Test search', () => {
  it('should be founded', async () => {
    assert.isTrue(await searchTest());
  })
})