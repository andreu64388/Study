package pages.hardcore;

import org.openqa.selenium.Keys;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindAll;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;
import org.openqa.selenium.support.pagefactory.AjaxElementLocatorFactory;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;

import java.awt.*;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.UnsupportedFlavorException;
import java.io.IOException;
import java.security.Key;
import java.time.Duration;
import java.util.List;


public class CalculatorPage extends  AbstractPage {
    private static final String PAGE_URL = "https://cloud.google.com/products/calculator";

    @FindBy(xpath = "//section[@id='']")
    private WebElement section;

    @FindBy(xpath = "//article[@id='cloud-site']/devsite-iframe/iframe")
    private WebElement parentFrame;

    @FindBy(xpath = "//iframe[@id='myFrame']")
    private WebElement frame;

    @FindBy(xpath = "//md-tab-item/div[@title='Compute Engine']/div")
    private WebElement computeEngineFormTab;

    @FindBy(xpath = "//input[@ng-model='listingCtrl.computeServer.quantity']")
    private WebElement numberOfInstances;
    @FindBy(xpath = "//md-select[@ng-model='listingCtrl.computeServer.os']")
    private WebElement selectOS;

    @FindBy(xpath = "//md-select[@ng-model='listingCtrl.computeServer.class']")
    private WebElement selectVMClass;

    @FindBy(xpath = "//md-select[@ng-model='listingCtrl.computeServer.series']")
    private WebElement selectSeries;


    @FindBy(xpath = "//md-select[@ng-model='listingCtrl.computeServer.instance']")
    private WebElement selectMachineType;

    @FindAll
            ({
                    @FindBy(xpath = "//div[contains(@class, 'md-select-menu-container') and contains(@class,'md-active')]/md-select-menu/md-content/md-option/div[contains(@class,'md-text')]")
            })
    private List<WebElement> activeSelectOptions;

    @FindAll
            ({
                    @FindBy(xpath = "//div[contains(@class, 'md-select-menu-container') and contains(@class,'md-active')]/md-select-menu/md-content/md-optgroup/md-option/div[contains(@class,'md-text')]")
            })
    private List<WebElement> activeSelectWithOptionGroupOptions;


    @FindBy(xpath = "//md-checkbox[@ng-model='listingCtrl.computeServer.addGPUs']")
    private WebElement addGPUCheckbox;

    @FindBy(xpath = "//md-select[@ng-model='listingCtrl.computeServer.gpuType']")
    private WebElement selectGPUType;

    @FindBy(xpath = "//md-select[@ng-model='listingCtrl.computeServer.gpuCount']")
    private WebElement selectGPUCount;

    @FindBy(xpath = "//md-select[@ng-model='listingCtrl.computeServer.ssd']")
    private WebElement selectLocalSSD;

    @FindBy(xpath = "//md-select[@ng-model='listingCtrl.computeServer.location']")
    private WebElement selectDatacenterLocation;

    @FindBy(xpath = "//md-select[@ng-model='listingCtrl.computeServer.cud']")
    private WebElement selectCommittedUsage;

    @FindBy(xpath = "//button[not(@disabled) and contains(text(),'Add to Estimate')]")
    private WebElement buttonAddToEstimte;

    @FindBy(xpath = "//div[contains(text(), 'Provisioning model:')]")
    private WebElement resultVM;

    @FindBy(xpath = "//div[contains(text(), 'Operating System / Software:')]")
    private WebElement resultOS;

    @FindBy(xpath = "//div[contains(text(), 'Instance type:')]")
    private WebElement resultInstanceType;

    @FindBy(xpath = "//div[contains(text(), 'Region:')]")
    private WebElement resultRegion;

    @FindBy(xpath = "//div[contains(text(), 'Local SSD:')]")
    private WebElement resultLocalSSD;

    @FindBy(xpath = "//div[contains(text(), 'Commitment term:')]")
    private WebElement resultCommitmentTerm;

    @FindBy(xpath = "//*[@id=\"Email Estimate\"]")
    WebElement sendEstimateToEmailButton;

    @FindBy(xpath = "//article[@id='cloud-site']/devsite-iframe/iframe")
    private WebElement emailPopupFrame;
    @FindBy(xpath = "//input[@ng-model='emailQuote.user.email']")
    WebElement emailInputInSendEstimateToEmailForm;
    @FindBy(xpath = "//button[contains(text(),'Send Email')]")
    WebElement getSendEstimateToEmailPopupButton;
    @FindBy(xpath = "//md-card-content[@id='resultBlock']/descendant::h2[contains(@class,'md-title')]/b")
    WebElement calculatorEstimateCost;
    @Override
    protected CalculatorPage openPage() {
        driver.navigate().to(PAGE_URL);
        return this;
    }
    public CalculatorPage(WebDriver driver) {
        super(driver);
        PageFactory.initElements(new AjaxElementLocatorFactory(driver, WAIT_TIME_IN_SECONDS), this);
        driver.switchTo().frame(parentFrame);
        driver.switchTo().frame(frame);
    }
    public void clickComputeEngineTab() {
        computeEngineFormTab.click();
    }
    public void enterNumberOfInstances(String numberOfInstancesValue) {
        numberOfInstances.sendKeys(numberOfInstancesValue);
    }
    public void setSelectOption(WebElement select, List<WebElement> selectOptions, String optionValue) {
        select.click();
        for (WebElement selectOption : selectOptions) {
            new WebDriverWait(driver, Duration.ofSeconds(WAIT_TIME_IN_SECONDS)).until(ExpectedConditions.elementToBeClickable(selectOption));
            if (selectOption.getText().trim().equals(optionValue.trim())) {
                selectOption.click();
                new WebDriverWait(driver, Duration.ofSeconds(WAIT_TIME_IN_SECONDS)).until(ExpectedConditions.invisibilityOf(selectOption));
                break;
            }
        }
    }
    public void enterOS(String optionValue) {
        setSelectOption(selectOS, activeSelectOptions, optionValue);
    }
    public void enterVMClass(String optionValue) {
        setSelectOption(selectVMClass, activeSelectOptions, optionValue);
    }
    public void enterSeries(String optionValue) {
        setSelectOption(selectSeries, activeSelectOptions, optionValue);
    }
    public void enterMachineType(String optionValue) {
        setSelectOption(selectMachineType, activeSelectWithOptionGroupOptions, optionValue);
    }
    public void setCheckedAddGPUCheckbox() {
        addGPUCheckbox.click();
    }
    public void enterGPUType(String optionValue) {
        setSelectOption(selectGPUType, activeSelectOptions, optionValue);
    }
    public void enterGPUCount(String optionValue) {
        setSelectOption(selectGPUCount, activeSelectOptions, optionValue);
    }
    public void enterLocalSSD(String optionValue) {
        setSelectOption(selectLocalSSD, activeSelectOptions, optionValue);
    }
    public void enterDatacenterLocation(String optionValue) {
        setSelectOption(selectDatacenterLocation, activeSelectWithOptionGroupOptions, optionValue);
    }
    public void enterCommittedUsage(String optionValue) {
        setSelectOption(selectCommittedUsage, activeSelectOptions, optionValue);
    }
    public void clickButtonAddToEstimte() {
        buttonAddToEstimte.click();
    }
    public String getResultVM() {
        return resultVM.getText();
    }
    public String getResultOS() {
        return resultOS.getText();
    }
    public String getResultInstanceType() {
        return resultInstanceType.getText();
    }
    public String getResultRegion() {
        return resultRegion.getText();
    }
    public String getResultLocalSSD() {
        return resultLocalSSD.getText();
    }
    public String getResultCommitmentTerm() {
        return resultCommitmentTerm.getText();
    }
    public void sendEstimateToEmailButtonClick() {
        sendEstimateToEmailButton.click();
    }
    public void pasteEmailToSendEstimateToEmailForm() {
        driver.switchTo().frame(emailPopupFrame).switchTo().frame(frame);
        Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
        try {
            emailInputInSendEstimateToEmailForm.sendKeys((CharSequence) clipboard.getData(DataFlavor.stringFlavor));
        } catch (UnsupportedFlavorException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    public void setSendEstimateToEmailPopupButtonClick() {
        getSendEstimateToEmailPopupButton.click();
    }
    public String getResulltCalculatorEstimateCost() {
        return calculatorEstimateCost.getText();
    }
}
