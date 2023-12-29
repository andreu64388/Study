using Microsoft.AspNetCore.Mvc;

namespace CResearch.Controllers;

public class CResearch : Controller
{
    
    
    //[AcceptVerbs("GET", "POST"]
    //[Route("/CResearch/CO1")]

    [HttpGet("/CResearch/CO1")]
    [HttpPost("/CResearch/CO1")]
    public async Task<IActionResult> CO1()
    {
        HttpRequest context = HttpContext.Request;
        string method = context.Method;
        string queryParameters = context.QueryString.ToString();
        string uri = context.Path;
        string headers = string.Join("\n", HttpContext.Request.Headers.Select(h => $"{h.Key}: {h.Value}"));
        string body = string.Empty;

        if (method == "POST")
        {
            using (StreamReader reader = new StreamReader(Request.Body))
            {
                body = await reader.ReadToEndAsync();
            }
        }

        string result = $"Method: {method}\n" +
                        $"Query Parameters: " +
                        $"{queryParameters}\n" +
                        $"URI: {uri}\n" +
                        $"Headers:" +
                        $"\n{headers}\nBody:\n{body}";

        return Content(result);
    }
    
    [HttpGet("/CResearch/CO2")]
    [HttpPost("/CResearch/CO2")]
    public async Task<string> C02()
    {
        string body = string.Empty;
        string headers = string.Join("\n", HttpContext.Request.Headers.Select(h => $"{h.Key}: {h.Value}"));
        if (HttpContext.Request.Method == "POST")
        {
            using (StreamReader reader = new StreamReader(Request.Body))
            {
                body = await reader.ReadToEndAsync();
            }
        }
        
        return $"Body:{body}\n" +
               $"------------------------------------\n" +
               $"Header: {headers};\n" +
               $"------------------------------------\n" +
               $"Status: {HttpContext.Response.StatusCode.ToString()}\n";
    }
}

