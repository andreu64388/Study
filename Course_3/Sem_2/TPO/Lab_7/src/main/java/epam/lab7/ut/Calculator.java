package epam.lab7.ut;

import epam.lab7.ut.exceptions.DivExpressionException;
import epam.lab7.ut.exceptions.MinusExpressionException;
import epam.lab7.ut.exceptions.MultExpressionException;
import epam.lab7.ut.exceptions.SumExpressionException;

public class Calculator {
    public int sum(int a, int b) throws SumExpressionException {
        if(b > 0 && Integer.MAX_VALUE - b < a) {
            throw new SumExpressionException("Выход за верхние пределы");
        } else if (b < 0 && Integer.MIN_VALUE - b > a) {
            throw new SumExpressionException("Выход за нижнии пределы");
        }
        return a + b;
    }

    public int minus(int a, int b) throws MinusExpressionException {
        if(b > 0 && Integer.MIN_VALUE + b > a) {
            throw new MinusExpressionException("Выход за пределы");
        } else if (b < 0 && Integer.MAX_VALUE + b < a) {
            throw new MinusExpressionException("Выход за верхнии пределы");
        }
        return a - b;
    }

    public double div(double a, double b) throws DivExpressionException {
        if(b == 0) {
            throw new DivExpressionException("Деление на ноль");
        }
        return a / b;
    }

    public int mult(int a, int b) throws MultExpressionException {
        if (Integer.MAX_VALUE / b < a) {
            throw new MultExpressionException("Выход за верхние пределы");
        }
        return a * b;
    }

    public int pow(int a, int b) throws MultExpressionException {
        int result = 1;
        for(int i = 0; i < b; i++) {
            result = this.mult(result, a);
        }
        return result;
    }
}
