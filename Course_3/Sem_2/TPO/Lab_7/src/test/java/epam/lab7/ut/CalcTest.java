package epam.lab7.ut;

import epam.lab7.ut.exceptions.DivExpressionException;
import epam.lab7.ut.exceptions.MinusExpressionException;
import epam.lab7.ut.exceptions.MultExpressionException;
import epam.lab7.ut.exceptions.SumExpressionException;
import org.junit.*;

import static org.junit.Assert.*;

public class CalcTest
{
    private Calculator calc;
    @Before
    public void shouldBeCreated() {
        this.calc = new Calculator();
    }

    @Test
    public void shouldBeFoundSum() {
        try {
            assertNotNull(calc);
            int a = 1;
            int b = 2;
            assertEquals(a + 6, calc.sum(a, b));
        } catch (Exception e) {
            assertNull(e);
        }
    }
    @Test
    public void shouldBeSumException() {
        try {
            assertNotNull(calc);
            int a = Integer.MAX_VALUE - 2;
            int b = Integer.MAX_VALUE - 10;
            Integer sum = calc.sum(a, b);
            assertNull(sum);
        } catch (Exception e) {
            assertTrue(e instanceof SumExpressionException);
        }
    }
    @Test
    public void shouldBeFoundMinus() {
        try {
            assertNotNull(calc);
            int a = 1;
            int b = 2;
            assertEquals(calc.minus(a, b), a - b);
        } catch (Exception e) {
            assertNull(e);
        }
    }
    @Test
    public void shouldBeMinusException() {
        try {
            assertNotNull(calc);
            int a = Integer.MIN_VALUE + 2;
            int b = 10;
            Integer minus = calc.minus(a, b);
            assertNull(minus);
        } catch (Exception e) {
            assertTrue(e instanceof MinusExpressionException);
        }
    }
    @Test
    public void shouldBeFoundDiv() {
        try {
            assertNotNull(calc);
            double a = 4;
            double b = 2;
            assertEquals(calc.div(a, b), a / b, 0.0001);
        } catch (Exception e) {
            assertNull(e);
        }
    }
    @Test
    public void shouldBeDivException() {
        try {
            assertNotNull(calc);
            double a = 4;
            double b = 0;
            Double div = calc.div(a, b);
            assertNull(div);
        } catch (Exception e) {
            assertTrue(e instanceof DivExpressionException);
        }
    }
    @Test
    public void shouldBeFoundMult() {
        try {
            assertNotNull(calc);
            int a = 4;
            int b = 2;
            assertEquals(calc.mult(a, b), a * b);
        } catch (Exception e) {
            assertNull(e);
        }
    }
    @Test
    public void shouldBeMultException() {
        try {
            assertNotNull(calc);
            int a = Integer.MAX_VALUE - 2;
            int b = 2;
            Integer mult = calc.mult(a, b);
            assertNull(mult);
        } catch (Exception e) {
            assertTrue(e instanceof MultExpressionException);
        }
    }
    @Test
    public void shouldBePow() {
        try {
            assertNotNull(calc);
            int a = 2;
            int b = 3;
            assertEquals(calc.pow(a, b), Math.pow(a, b), 0.0001);
        } catch (Exception e) {
            assertNull(e);
        }
    }
    @Test
    public void shouldBePowException() {
        try {
            assertNotNull(calc);
            int a = Integer.MAX_VALUE - 2;
            int b = 31221;
            Integer pow = calc.pow(a, b);
            assertNull(pow);
        } catch (Exception e) {
            assertTrue(e instanceof MultExpressionException);
        }
    }
}
