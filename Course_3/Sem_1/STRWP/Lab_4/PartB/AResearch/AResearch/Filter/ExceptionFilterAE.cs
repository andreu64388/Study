using Microsoft.AspNetCore.Mvc.Filters;
// Код, выполняемый при возникновении исключения в методе AE
namespace AResearch.Filter;

public class ExceptionFilterAE :Attribute, IExceptionFilter
{
    public void OnException(ExceptionContext context)
    {

        Console.WriteLine($"An exception occurred in Action AE: {context.Exception.Message}");
    }
}