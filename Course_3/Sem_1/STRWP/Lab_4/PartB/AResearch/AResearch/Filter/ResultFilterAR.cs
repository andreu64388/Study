using Microsoft.AspNetCore.Mvc.Filters;

namespace AResearch.Filter;

public class ResultFilterAR :Attribute, IResultFilter
{
    public void OnResultExecuting(ResultExecutingContext context) =>Console.WriteLine("Result for Action AR is being executed.");
    
    public void OnResultExecuted(ResultExecutedContext context) =>Console.WriteLine("Result for Action AR has been executed.");
    
}