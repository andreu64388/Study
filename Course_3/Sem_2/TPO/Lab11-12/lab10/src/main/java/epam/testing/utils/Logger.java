package epam.testing.utils;

public class Logger {
  private static final java.util.logging.Logger LOGGER = java.util.logging.Logger.getLogger("app-logger");

  public static void log(String message) {
    LOGGER.info(message);
  }

  public static void warn(String message) {
    LOGGER.warning(message);
  }
}
