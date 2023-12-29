var builder = WebApplication.CreateBuilder(args);


builder.Services.AddControllersWithViews();

var app = builder.Build();



app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();

app.UseAuthorization();

app.MapControllerRoute(
	name: "default",
	pattern: "{controller=Calc}/{action=Index}/{id?}");

app.Run();
