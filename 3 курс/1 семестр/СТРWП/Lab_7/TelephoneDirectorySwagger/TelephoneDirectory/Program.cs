using Microsoft.EntityFrameworkCore;
using TelephoneDirectory.Domain;
using TelephoneDirectory.Domain.Entity;
using TelephoneDirectory.Domain.Repository;
using TelephoneDirectory.Service;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddControllersWithViews().AddRazorRuntimeCompilation();
builder.Services.AddScoped<IRepository<ContactEntity>, ContactRepository>();
builder.Services.AddScoped<IServiceContact, ContactService>();

var connectionString = builder.Configuration.GetConnectionString("MSSQL");
builder.Services.AddDbContext<AppDbContext>(options =>
{
    options.UseSqlServer(connectionString);
});

var app = builder.Build();

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