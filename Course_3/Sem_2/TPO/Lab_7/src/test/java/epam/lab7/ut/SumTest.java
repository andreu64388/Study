package epam.lab7.ut;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;

import java.util.Arrays;
import java.util.Collection;

import static org.junit.Assert.*;

@RunWith(Parameterized.class)
public class SumTest {
  @Parameterized.Parameters
  public static Collection<Object[]> data() {
    return Arrays.asList(new Object[][]{
            {1, 2, 3},
            {0, 0, 0},
            {-1, -2, -3},
            {Integer.MAX_VALUE, Integer.MIN_VALUE, -1},
    });
  }

  private final int a;
  private final int b;
  private final int expected;

  public SumTest(int a, int b, int expected) {
    this.a = a;
    this.b = b;
    this.expected = expected;
  }

  @Test
  public void shouldBeFoundSum() {
    try {
      Calculator calc = new Calculator();
      assertNotNull(calc);
      assertEquals(expected, calc.sum(a, b));
    } catch (Exception e) {
      assertNull(e);
    }
  }
}
