using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.OutputCaching;

namespace CHResearch.Controllers;

public class CHResearch : Controller
{
   
    [HttpGet]
    [ResponseCache(Location =ResponseCacheLocation.Any, Duration =5)]
    public IActionResult AD() => Content($"AD Action - {DateTime.Now} ");


    [HttpPost] 
    [OutputCache(Duration = 10)]

    public IActionResult AP(int x,int y) => Content($"AP Action - Sum: {x + y} - {DateTime.Now}");
}