using AResearch.Filter;
using Microsoft.AspNetCore.Mvc;

namespace AResearch.Controllers;

public class AResearch : Controller
{
    // GET  
    [ActionFilterAA]
    public IActionResult AA() => Content("AA");
    
    [ResultFilterAR]
    public IActionResult AR() => Content("AR");
    
    [ExceptionFilterAE]
    public IActionResult AE() => throw new Exception("An exception occurred in Action AE.");

}