using ASPCMVC03.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;

namespace ASPCMVC03.Controllers
{
    public class StartController : Controller
    {
   
        public IActionResult Index()
        {
            return View();
        }

        public IActionResult One()
        {
            return View();
        }
        public IActionResult Two()
        {
            return View();
        }

        public IActionResult Three()
        {
            return View();
        }
        

        public IActionResult BSTU()
        {
            return Redirect("https://www.belstu.by/");
        }

    }
}