using ContactRepository;
using ContactRepository.Model;
using ContactRepository.Repository;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Http;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using TelephoneDirectory.Entity;


var builder = WebApplication.CreateBuilder(args);

builder.Services.AddControllersWithViews().AddRazorRuntimeCompilation();
builder.Services.AddScoped<ITelephoneRepository<ContactEntity>, TelephoneRepository>();

var connectionString = builder.Configuration.GetConnectionString("MSSQL");
builder.Services.AddDbContext<AppDbContext>(options =>
{
    options.UseSqlServer(connectionString);
});
var app = builder.Build();

if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Dict/Error");
    app.UseHsts();
}


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