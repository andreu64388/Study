using ASPCMVC04.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;

namespace ASPCMVC04.Controllers
{
	public class StatusController : Controller
	{



		public IActionResult S200()
		{
			return Ok();
		}

		public IActionResult S300()
		{
			return Redirect("https://www.belstu.by/");
		}
		public IActionResult S500()
		{
			int a = 1;
			int b = 2;
			int result = a / (b - 2);
			return View();
		}

		public IActionResult S404()
		{
			return NotFound(); 
		}


	}
}