var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddControllersWithViews();
builder.Services.AddOutputCache();
builder.Services.AddResponseCaching();
var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}



app.UseHttpsRedirection();
app.UseStaticFiles();
app.UseResponseCaching();
app.UseRouting();
app.UseOutputCache();
app.UseAuthorization();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=CHResearch}/{action=AD}/{id?}");

app.Run();