package epam.lab7.ut.exceptions;

public class ExpressionException extends Exception {
    public ExpressionException() {
        super("Ошибка в выражении");
    }

    public ExpressionException(String message) {
        super("Ошибка в варажении | " + message);
    }
}

