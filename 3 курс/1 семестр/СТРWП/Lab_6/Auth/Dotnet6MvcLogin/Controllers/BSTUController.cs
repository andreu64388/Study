using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using System.Data;

namespace Dotnet6MvcLogin.Controllers
{
    public class BSTUController : Controller
    {

        [Authorize]
        public IActionResult Index()
        {
            return View();
        }

      
        [Authorize(Roles = "Administrator")]
        public IActionResult Config()
        {
            return View();
        }
    }
}
