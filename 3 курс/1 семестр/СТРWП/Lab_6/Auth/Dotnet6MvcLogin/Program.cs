using Dotnet6MvcLogin.Models.Domain;
using Dotnet6MvcLogin.Models.DTO;
using Dotnet6MvcLogin.Repositories.Abstract;
using Dotnet6MvcLogin.Repositories.Implementation;
using Microsoft.AspNetCore.Identity;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddControllersWithViews();
builder.Services.AddDbContext<DatabaseContext>(options => options.UseSqlServer(builder.Configuration.GetConnectionString("conn")));

builder.Services.Configure<IdentityOptions>(options =>
{
    options.Password.RequireUppercase = false;
});

builder.Services.AddRazorPages()
    .AddRazorRuntimeCompilation();
builder.Services.AddIdentity<ApplicationUser, IdentityRole>()
    .AddEntityFrameworkStores<DatabaseContext>()
    .AddDefaultTokenProviders();

builder.Services.ConfigureApplicationCookie(options => options.LoginPath = "/Account/Login");


builder.Services.AddScoped<AccountService>();
builder.Services.AddAuthentication().AddGoogle(googleOptions =>
{
    googleOptions.ClientId = "690079639289-prm3jg0ctt8m338spmorbe8s1ldo34cs.apps.googleusercontent.com";
    googleOptions.ClientSecret = "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";


});

var app = builder.Build();
using (var scope = app.Services.CreateScope())
{
    var serviceProvider = scope.ServiceProvider;

    
    var userManager = serviceProvider.GetRequiredService<UserManager<ApplicationUser>>();
    var roleManager = serviceProvider.GetRequiredService<RoleManager<IdentityRole>>();


    var users = new List<(string Email, string Password, string[] Roles)>
    {
        ("admin@belstu.by", "Admin123$", new string[] { "Administrator" }),
        ("emp@belstu.by", "Emp123$", new string[] { "Employer" }),
        ("guest@belstu.by", "Guest123$", new string[] { "Guest" }),
        ("super@belstu.by", "Super123$", new string[] { "Administrator", "Employer", "Guest" }),
    };

    foreach (var roleName in users.SelectMany(u => u.Roles).Distinct())
    {
        if (!await roleManager.RoleExistsAsync(roleName))
        {
            await roleManager.CreateAsync(new IdentityRole(roleName));
        }
    }

  
    foreach (var user in users)
    {
        var existingUser = await userManager.FindByEmailAsync(user.Email);
        if (existingUser == null)
        {
            var newUser = new ApplicationUser { UserName = user.Email, Email = user.Email };
            var result = await userManager.CreateAsync(newUser, user.Password);

            if (result.Succeeded)
            {
                foreach (var roleName in user.Roles)
                {
                    await userManager.AddToRoleAsync(newUser, roleName);
                }
            }
        }
    }
}

if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    app.UseHsts();
}

app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();
app.UseAuthentication();
app.UseAuthorization();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Account}/{action=Login}/{id?}");

app.MapControllerRoute(
    name: "BSTU",
    pattern: "{controller=BSTU}/{action=Index}/{id?}");

app.MapControllerRoute( 
    name: "FIT",
    pattern: "{controller=FIT}/{action=Index}/{id?}");

app.MapControllerRoute(
    name: "FIE",
    pattern: "{controller=FIE}/{action=Index}/{id?}");

app.MapControllerRoute(
    name: "FLT",
    pattern: "{controller=FLT}/{action=Index}/{id?}");
app.Run();
