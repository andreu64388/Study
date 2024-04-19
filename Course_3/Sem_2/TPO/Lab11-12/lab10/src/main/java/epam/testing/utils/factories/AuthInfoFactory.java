package epam.testing.utils.factories;

import epam.testing.models.auth_info.AuthInfo;
import epam.testing.models.auth_info.IAuthInfo;
import epam.testing.utils.PropsReader;

public class AuthInfoFactory {
  public static IAuthInfo createInstance() {
    IAuthInfo propsReader = new PropsReader("auth.properties");
    return new AuthInfo(propsReader);
  }
}
