using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace Dotnet6MvcLogin.Controllers
{
    [Authorize]
    public class DashboardController : Controller
    {
        [Authorize]
        public IActionResult Display()
        {
            return View();
        }
    }
}
