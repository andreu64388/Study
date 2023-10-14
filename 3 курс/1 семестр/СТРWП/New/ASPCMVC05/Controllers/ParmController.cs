using ASPCMVC05.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;

namespace ASPCMVC05.Controllers
{
    public class ParmController : Controller
    {


		//http://localhost:5067/Parm/Index?Id=3
		public IActionResult Index(string id)
        {
            ViewBag.Id = id;
            return View();
        }

		//http://localhost:5067/Parm/Uri01?Id=3
		public IActionResult Uri01(int Id)
        {
            ViewBag.Id = Id;
            return View();
        }
		//http://localhost:5067/Parm/Uri02?Id=3
		public IActionResult Uri02(int? Id)
        {
            ViewBag.Id = Id;
            return View();
        }
		//http://localhost:5067/Parm/Uri03?Id=3
		public IActionResult Uri03(float? Id)
        {
            ViewBag.Id = Id;
            return View();
        }
		//http://localhost:5067/Parm/Uri04?Id=2023-10-15
		public IActionResult Uri04(DateTime? Id)
        {
            ViewBag.Id = Id;
            return View();
        }
      
    }
}