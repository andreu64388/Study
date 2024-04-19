package epam.testing.models.auth_info;

import lombok.Data;

@Data
public class AuthInfo implements IAuthInfo {
  private String password;
  private String email;

  public AuthInfo(IAuthInfo authInfo) {
    this.password = authInfo.getPassword();
    this.email = authInfo.getEmail();
  }
}