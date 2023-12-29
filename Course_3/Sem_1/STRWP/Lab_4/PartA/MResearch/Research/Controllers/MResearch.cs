using Microsoft.AspNetCore.Mvc;

namespace Research.Controllers;

public class MResearch : Controller
{
    
    
    [HttpGet("MResearch/M01/{id}")]
    [HttpGet("MResearch/M01")]
    [HttpGet("MResearch")]
    [HttpGet("")]
    [HttpGet("V2/MResearch/M01")]
    [HttpGet("V3/MResearch/X/M01")]
    public IActionResult MO1(int? id)
    {
        return Content("GET:M01");
    }
  
    [HttpGet("V2")]
    [HttpGet("V2/MResearch")]
    [HttpGet("V2/MResearch/M02")]
    [HttpGet("MResearch/M02")]
    [HttpGet("V3/MResearch/X/M02")]
    public IActionResult M02()
    {
        return Content("GET:M02");
    }

    [HttpGet("V3")]
    [HttpGet("V3/MResearch/X")]
    [HttpGet("V3/MResearch/X/M03")]
    public IActionResult M03()
    {
        return Content("GET:M03");
    }

    [HttpGet("{*any}")]
    public IActionResult MXX()
    {
        return Content("MXX1");
    } 

}






