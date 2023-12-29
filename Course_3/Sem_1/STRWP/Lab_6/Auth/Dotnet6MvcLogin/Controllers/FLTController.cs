using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using System.Data;

namespace Dotnet6MvcLogin.Controllers
{
    public class FLTController : Controller
    {
        [Authorize(Roles = "Guest,Employer")]
        public ActionResult Index()
        {
            return View();
        }

        [Authorize(Roles = "Employer")]
        public ActionResult FLT_LV()
        {
            return View();
        }

        [Authorize(Roles = "Employer")]
        public ActionResult FLT_LU()
        {
            return View();
        }

        [Authorize(Roles = "Employer")]
        public ActionResult FLT_LZ()
        {
            return View();
        }
    }
}
