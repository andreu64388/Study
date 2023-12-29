using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System.Data;

namespace Dotnet6MvcLogin.Controllers
{
    public class FIEController : Controller
    {

        [Authorize(Roles = "Guest,Employer")]
        public ActionResult Index()
        {
            return View();
        }

        [Authorize(Roles = "Employer")]
        public ActionResult FIE_TM()
        {
            return View();
        }

        [Authorize(Roles = "Employer")]
        public ActionResult FIE_UR()
        {
            return View();
        }

        [Authorize(Roles = "Employer")]
        public ActionResult FIE_UP()
        {
            return View();
        }
    }
}
