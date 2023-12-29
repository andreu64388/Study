using ASPCMVC07.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;

namespace ASPCMVC07.Controllers
{
    public class CalcController : Controller
    {
        public IActionResult Index()
        {
            return View("Index");
        }

        [HttpPost]
        public IActionResult Sum(float x, float y)
        {
            float result = x + y;
            ViewBag.Result = result;
            return View("Index");
        }

        [HttpPost]
        public IActionResult Sub(float x, float y)
        {
            float result = x - y;
            ViewBag.Result = result;
            return View("Index");
        }

        [HttpPost]
        public IActionResult Mul(float x, float y)
        {
            float result = x * y;
            ViewBag.Result = result;
            return View("Index");
        }

        [HttpPost]
        public IActionResult Div(float x, float y)
        {
            if (y != 0)
            {
                float result = x / y;
                ViewBag.Result = result;
            }
            else
            {
                ViewBag.Error = "Division by zero is not allowed.";
            }
            return View("Index");
        }
    }

}