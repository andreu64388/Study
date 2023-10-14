using System.Text.RegularExpressions;
using Microsoft.AspNetCore.Mvc;

namespace MResearch.Controllers;


[Route("it")]
public class MResearch : Controller
{ 
    
    
   [HttpGet("n/{n:int}/{text}")]
public string M01B(int n, string text)
{
    return  $"GET:M01:{n}/{text}";
}

[AcceptVerbs("GET", "POST")]
[Route("b/{b}/{letters}")]
public string M02(bool b, string letters) => $"{HttpContext.Request.Method}:M02:{b}/{letters}";

[AcceptVerbs("GET", "DELETE")]
[Route("{f:float}/{text:length(2,5)}")]
    public string M03(float f, string text) => $"{HttpContext.Request.Method}:M03:{f}/{text}";
    
    [HttpPut("p/{letters:length(3,4)}/{n:range(100, 200)}")]
    public string M04(int n, string letters) =>  $"PUT:M04:/letters/{n}/{letters}";
    
    [HttpPost("mail/{mail}")]
    public IActionResult M04(string mail) => IsGmailAddress(mail) ? Ok($"POST:{mail}") : BadRequest("Недействительный адрес Gmail");
    private static bool IsGmailAddress(string mail)
    {
        var gmailPattern = @"^[a-zA-Z0-9._%+-]+@gmail.com$";
        return Regex.IsMatch(mail, gmailPattern);
    }
}
