using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using System.Data;

namespace Dotnet6MvcLogin.Controllers
{
    public class FIT : Controller
    {
        [Authorize(Roles = "Guest,Employer")]
        public ActionResult Index()
        {

            return View();
        }

        [Authorize(Roles = "Employer")]
        public ActionResult FIT_IS()
        {
            return View();
        }

        [Authorize(Roles = "Employer")]
        public ActionResult FIT_PI()
        {
            return View();
        }

        [Authorize(Roles = "Employer")]
        public ActionResult FIT_ID()
        {
            return View();
        }
    }
}
