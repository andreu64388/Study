package tests;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.edge.EdgeDriver;
import org.testng.Assert;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;
import pages.CalculatorPage;
import pages.HurtMePlentyPage;

public class HurtMePlentyTest {
    class TestValue {
        final private String input;
        final private String result;

        public TestValue(String input, String result) {
            this.input = input;
            this.result = result;
        }
    }

    private WebDriver driver;
    TestValue numberOfInstances;
    TestValue vmClass;
    TestValue os;
    TestValue instanceType;
    TestValue region;
    TestValue localSSD;
    TestValue committedUsage;
    TestValue series;
    TestValue gpuType;
    TestValue gpuCount;
    CalculatorPage calculatorPage;

    @BeforeMethod
    public void driverSetup() {
        System.setProperty("webdriver.edge.driver", "E:\\Rubish\\Drivers\\msedgedriver.exe");
        driver = new EdgeDriver();
        HurtMePlentyPage hurtMePlentyPage = new HurtMePlentyPage(driver);
        hurtMePlentyPage.openPage();
        calculatorPage = hurtMePlentyPage.startSearch("Google Cloud Pricing Calculator").goToResult("Google Cloud Pricing Calculator");
        calculatorPage.clickComputeEngineTab();

        numberOfInstances = new TestValue("4", "4");
        vmClass = new TestValue("Regular", "Provisioning model: Regular");
        os = new TestValue("Free: Debian, CentOS, CoreOS, Ubuntu or BYOL (Bring Your Own License)", "Operating System / Software: Free");
        instanceType = new TestValue("n1-standard-8 (vCPUs: 8, RAM: 30GB)", "Instance type: n1-standard-8\nCommitted Use Discount applied");
        region = new TestValue("Frankfurt (europe-west3)", "Region: Frankfurt");
        localSSD = new TestValue("2x375 GB", "Local SSD: 2x375 GiB\nCommitted Use Discount applied");
        committedUsage = new TestValue("1 Year", "Commitment term: 1 Year");
        series = new TestValue("N1", "N1");
        gpuType = new TestValue("NVIDIA Tesla V100", "NVIDIA Tesla V100");
        gpuCount = new TestValue("1", "1");

        calculatorPage.enterNumberOfInstances(numberOfInstances.input);
        calculatorPage.enterOS(os.input);
        calculatorPage.enterVMClass(vmClass.input);
        calculatorPage.enterSeries(series.input);
        calculatorPage.enterMachineType(instanceType.input);
        calculatorPage.setCheckedAddGPUCheckbox();
        calculatorPage.enterGPUType(gpuType.input);
        calculatorPage.enterGPUCount(gpuCount.input);
        calculatorPage.enterLocalSSD(localSSD.input);
        calculatorPage.enterDatacenterLocation(region.input);
        calculatorPage.enterCommittedUsage(committedUsage.input);
        calculatorPage.clickButtonAddToEstimte();
    }

    @Test
    public void compareVmClass() {
        Assert.assertEquals(calculatorPage.getResultVM(), vmClass.result);
    }

    @Test
    public void compareOs() {
        Assert.assertEquals(calculatorPage.getResultOS(), os.result);
    }

    @Test
    public void compareInstanceType() {
        Assert.assertEquals(calculatorPage.getResultInstanceType(), instanceType.result);
    }

    @Test
    public void compareRegion() {
        Assert.assertEquals(calculatorPage.getResultRegion(), region.result);
    }

    @Test
    public void compareLocalSSD() {
        Assert.assertEquals(calculatorPage.getResultLocalSSD(), localSSD.result);
    }

    @Test
    public void compareCommittedUsage() {
        Assert.assertEquals(calculatorPage.getResultCommitmentTerm(), committedUsage.result);
    }

    @AfterMethod(alwaysRun = true)
    public void browserTearDown() {
        driver.quit();
        driver = null;
    }
}
