using ContactRepository;
using ContactRepository.Interface;
using ContactRepository.Model;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;


var builder = WebApplication.CreateBuilder(args);

builder.Services.AddControllersWithViews().AddRazorRuntimeCompilation();

builder.Services.AddSingleton<ITelephoneRepository<Contact>,TelephoneRepository>();

var app = builder.Build();

if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Dict/Error");
    app.UseHsts();
}
app.UseCors(builder =>
{
	builder
		.AllowAnyOrigin() 
		.AllowAnyMethod()
		.AllowAnyHeader(); 
}); 
;
app.Use(async (context, next) =>
{
    await next();
    if (context.Response.StatusCode == 404)
    {
        var method = context.Request.Method;
        var uri = context.Request.Path;
        
        context.Response.ContentType = "text/plain";
        context.Response.StatusCode = 404;
        await context.Response.WriteAsync($"{method}: {uri} dont support");
        
    }
});

app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();

app.UseAuthorization();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Dict}/{action=Index}/{id?}");

app.Run();