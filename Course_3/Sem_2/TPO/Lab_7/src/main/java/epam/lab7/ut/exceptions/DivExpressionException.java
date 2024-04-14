package epam.lab7.ut.exceptions;

public class DivExpressionException extends ExpressionException {
    public DivExpressionException() {
        super("Ошибка в деление");
    }

    public DivExpressionException(String message) {
        super("Ошибка в деление | " + message);
    }
}

