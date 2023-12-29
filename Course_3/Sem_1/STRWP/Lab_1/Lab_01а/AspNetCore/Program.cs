
var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

app.MapGet("/", () => "Hello");


app.MapGet("/KAV", (HttpContext context) => {
    string parmA = context.Request.Query["ParmA"];
    string parmB = context.Request.Query["ParmB"];
    string responseText = $"GET-Http-KAV:ParmA = {parmA},ParmB = {parmB}";
    context.Response.ContentType = "text/plain";
    return context.Response.WriteAsync(responseText);
});

app.MapPost("/KAV", (HttpContext context) => {
    string parmA = context.Request.Form["ParmA"];
    string parmB = context.Request.Form["ParmB"];
    string responseText = $"POST-Http-KAV:ParmA = {parmA},ParmB = {parmB}";
    context.Response.ContentType = "text/plain";
    return context.Response.WriteAsync(responseText);
});

app.MapPut("/KAV", (HttpContext context) => {
    string parmA = context.Request.Query["ParmA"];
    string parmB = context.Request.Query["ParmB"];
    string responseText = $"PUT-Http-KAV:ParmA = {parmA},ParmB = {parmB}";
    context.Response.ContentType = "text/plain";
    return context.Response.WriteAsync(responseText);
});

app.MapPost("/add", (HttpContext context) => {
    int x = int.Parse(context.Request.Form["X"]);
    int y = int.Parse(context.Request.Form["Y"]);
    int sum = x + y;
    context.Response.ContentType = "text/plain";
    return context.Response.WriteAsync(sum.ToString());
});

    app.MapGet("/calculator", (HttpContext context) => {
    string html = "<html><body><form method='post' action='/multiply'>" +
                  "X: <input type='number' name='X'><br>" +
                  "Y: <input type='number' name='Y'><br>" +
                  "<input type='submit' value='multu'></form></body></html>";
    context.Response.ContentType = "text/html";
    return context.Response.WriteAsync(html);
});

app.MapPost("/multiply", (HttpContext context) => {
    int x = int.Parse(context.Request.Form["X"]);
    int y = int.Parse(context.Request.Form["Y"]);
    int product = x * y;
    context.Response.ContentType = "text/plain";
    return context.Response.WriteAsync(product.ToString());
});

app.Run();
