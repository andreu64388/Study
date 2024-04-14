package epam.lab7.ut.exceptions;

public class MultExpressionException extends ExpressionException {
    public MultExpressionException() {
        super("Ошибка в произведении");
    }

    public MultExpressionException(String message) {
        super("Ошибка в произведении | " + message);
    }
}
