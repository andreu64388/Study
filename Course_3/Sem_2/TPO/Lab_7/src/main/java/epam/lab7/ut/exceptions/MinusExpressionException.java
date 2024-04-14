package epam.lab7.ut.exceptions;

public class MinusExpressionException extends ExpressionException {
    public MinusExpressionException() {
        super("Ошибка в разности");
    }

    public MinusExpressionException(String message) {
        super("Ошибка в разности | " + message);
    }
}

