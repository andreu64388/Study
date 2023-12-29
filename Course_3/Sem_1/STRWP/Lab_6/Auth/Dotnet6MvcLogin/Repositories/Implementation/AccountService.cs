using Dotnet6MvcLogin.Models;
using Dotnet6MvcLogin.Models.Domain;
using Dotnet6MvcLogin.Models.DTO;
using Dotnet6MvcLogin.Repositories.Abstract;
using Microsoft.AspNetCore.Identity;
using Microsoft.EntityFrameworkCore;
using System.Security.Claims;
using System.Text;

namespace Dotnet6MvcLogin.Repositories.Implementation
{
    public class AccountService: IUserAuthenticationService
    {
        public readonly UserManager<ApplicationUser> userManager;
        public readonly RoleManager<IdentityRole> roleManager;
        public readonly SignInManager<ApplicationUser> signInManager;
        public AccountService(UserManager<ApplicationUser> userManager, 
            SignInManager<ApplicationUser> signInManager, RoleManager<IdentityRole> roleManager)
        {
            this.userManager = userManager;
            this.roleManager = roleManager;
            this.signInManager = signInManager; 

        }

        public async Task<Status> RegisterAsync(RegisterModel model)
        {
            var status = new Status();
            var userExists = await userManager.FindByEmailAsync(model.Email);
            if (userExists != null)
            {
                status.StatusCode = 0;
                status.Message = "User already exists";
                return status;
            }

            var user = new ApplicationUser { UserName = model.Email, Email = model.Email };

            var result = await userManager.CreateAsync(user, model.Password);
            if (!result.Succeeded)
            {
                status.StatusCode = 0;
                status.Message = "User creation failed";
                return status;
            }

            if (!await roleManager.RoleExistsAsync(model.Role))
                await roleManager.CreateAsync(new IdentityRole(model.Role));

            if (await roleManager.RoleExistsAsync(model.Role))
            {
                await userManager.AddToRoleAsync(user, model.Role);
            }

            await signInManager.SignInAsync(user, isPersistent: true);

            status.StatusCode = 1;
            status.Message = "You have registered successfully";
            return status;
        }

        public async Task<Status> LoginAsync(LoginModel model)
        {
            var status = new Status();
            var user = await userManager.FindByEmailAsync(model.Email);
            if (user == null)
            {
                status.StatusCode = 0;
                status.Message = "Invalid Email";
                return status;
            }

            if (!await userManager.CheckPasswordAsync(user, model.Password))
            {
                status.StatusCode = 0;
                status.Message = "Invalid Password";
                return status;
            }

            var signInResult = await signInManager.PasswordSignInAsync(user, model.Password, false, true);
            if (signInResult.Succeeded)
            {
                var userRoles = await userManager.GetRolesAsync(user);
                var authClaims = new List<Claim>
                {
                    new Claim(ClaimTypes.Name, user.UserName),
                };

                foreach (var userRole in userRoles)
                {
                    authClaims.Add(new Claim(ClaimTypes.Role, userRole));
                }
                status.StatusCode = 1;
                status.Message = "Logged in successfully";
            }
            else if (signInResult.IsLockedOut)
            {
                status.StatusCode = 0;
                status.Message = "User is locked out";
            }
            else
            {
                status.StatusCode = 0;
                status.Message = "Error on logging in";
            }
           
            return status;
        }

        public async Task LogoutAsync()
        {
           await signInManager.SignOutAsync();
           
        }

        public async Task<object> GetById(string id)
        {
            var user = await userManager.FindByIdAsync(id);
            return user;
        }

        public async Task<object>  GetAllUsersAsync()
        {
            var users = await userManager.Users.ToListAsync();

        
            return users;
           
        }

        public async Task UpdateUserAsync(ApplicationUser editedUser)
        {

            ApplicationUser user = (ApplicationUser)await this.GetById(editedUser.Id);

         
                user.Email = editedUser.Email;
                user.UserName = editedUser.UserName;
           

            await userManager.UpdateAsync(user);



        }

        public async Task DeleteAsync (string id)
        {
            ApplicationUser user = (ApplicationUser)await this.GetById(id);
            if (user != null)
            {
                await userManager.DeleteAsync(user);
            }
        }

        public async Task CreateUserAsync(ApplicationUser newUser)
        {
            await userManager.CreateAsync(newUser);
        }

        public async Task<object> GetAllRoles()
        {
            var roles = await roleManager.Roles.ToListAsync();
            return roles;
        }

        public async Task UpdateRoleAsync(IdentityRole editedRole)
        {
            IdentityRole role = await roleManager.FindByIdAsync(editedRole.Id);
            if (role != null)
            {
                role.Name = editedRole.Name;
                await roleManager.UpdateAsync(role);
            }
        }   

        public async Task DeleteRoleAsync(string id)
        {
            IdentityRole role = await roleManager.FindByIdAsync(id);
            if (role != null)
            {
                await roleManager.DeleteAsync(role);
            }
        }

        public async Task<object> GetRoleById(string id)
        {
            IdentityRole role = await roleManager.FindByIdAsync(id);

            return role;
        }
    }

}


