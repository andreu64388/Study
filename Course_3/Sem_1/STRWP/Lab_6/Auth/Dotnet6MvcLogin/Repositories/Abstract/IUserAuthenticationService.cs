using Dotnet6MvcLogin.Models.DTO;

namespace Dotnet6MvcLogin.Repositories.Abstract
{
    public interface IUserAuthenticationService
    {
   
        Task<Status> LoginAsync(LoginModel model);
        Task LogoutAsync();
        Task<Status> RegisterAsync(RegisterModel model);

    }
}
