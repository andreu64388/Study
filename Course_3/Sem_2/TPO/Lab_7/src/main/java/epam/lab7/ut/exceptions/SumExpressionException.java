package epam.lab7.ut.exceptions;

public class SumExpressionException extends ExpressionException {
    public SumExpressionException() {
        super("Ошибка в сумме");
    }

    public SumExpressionException(String message) {
        super("Ошибка в сумме | " + message);
    }
}

