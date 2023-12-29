using Dotnet6MvcLogin.Models.Domain;
using Dotnet6MvcLogin.Repositories.Implementation;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using System.Threading.Tasks;

namespace Dotnet6MvcLogin.Controllers
{
    public class BSTUController : Controller
    {
        private readonly AccountService _authService;

        public BSTUController(AccountService authService)
        {
            this._authService = authService;
        }

        [Authorize]
        public IActionResult Index()
        {
            return View();
        }

        [Authorize(Roles = "Administrator")]
        public async Task<IActionResult> User()
        {
            List<ApplicationUser> users = (List<ApplicationUser>)await _authService.GetAllUsersAsync();
            return View(users);
        }

        [Authorize(Roles = "Administrator")]
        public async Task<IActionResult> DeleteUser(string id)
        {


            var user = await _authService.GetById(id);

            await _authService.DeleteAsync(id);
            return RedirectToAction(nameof(User));

        }

        [HttpGet]
        public async Task<IActionResult> UpdateUser(string id)
        {
            ApplicationUser user = (ApplicationUser)await _authService.GetById(id);


            return View(user);
        }



        [HttpPost]
        public async Task<IActionResult> UpdateUser(ApplicationUser updatedUser)
        {

            await _authService.UpdateUserAsync(updatedUser);
            return RedirectToAction(nameof(User));



        }

        [HttpGet]
        public IActionResult CreateUser()
        {
            return View();
        }

   
        [HttpPost]
        public async Task<IActionResult> CreateUser(ApplicationUser newUser)
        {

            await _authService.CreateUserAsync(newUser);
            return RedirectToAction(nameof(User));
        }

        [Authorize(Roles = "Administrator")]
        [HttpGet]
        public async Task<IActionResult> Role()
        {
            List<IdentityRole> users = (List<IdentityRole>)await _authService.GetAllRoles();
            return View(users);
        }

        [Authorize(Roles = "Administrator")]
        public async Task<IActionResult> DeleteRole(string id)
        {


 

            await _authService.DeleteRoleAsync(id);
            return RedirectToAction(nameof(Role));

        }

        [HttpGet]
        public async Task<IActionResult> UpdateRole(string id)
        {
            var user = await _authService.GetRoleById(id);

            return View(user);
        }



        [HttpPost]
        public async Task<IActionResult> UpdateRole(IdentityRole updatedUser)
        {

            await _authService.UpdateRoleAsync(updatedUser);
            return RedirectToAction(nameof(User));



        }

       

    }

}
