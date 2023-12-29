using Microsoft.AspNetCore.Mvc.Filters;

namespace AResearch.Filter;

public class ActionFilterAA :Attribute, IActionFilter
{
    public void OnActionExecuting(ActionExecutingContext context)=> Console.WriteLine("Action AA is executing.");
    
    public void OnActionExecuted(ActionExecutedContext context)=> Console.WriteLine("Action AA has executed.");
    
}
