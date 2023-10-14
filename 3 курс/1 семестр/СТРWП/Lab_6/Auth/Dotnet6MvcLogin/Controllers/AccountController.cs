using Auth.Models.DTO;
using Dotnet6MvcLogin.Models.Domain;
using Dotnet6MvcLogin.Models.DTO;
using Dotnet6MvcLogin.Repositories.Abstract;
using Dotnet6MvcLogin.Repositories.Implementation;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using System.Security.Claims;

namespace Dotnet6MvcLogin.Controllers
{
    public class AccountController : Controller
    {
        private readonly AccountService _authService;
        public AccountController(AccountService authService)
        {
            this._authService = authService;
        }

        
        public IActionResult Login()
        {
            return View();
        }

       
        [HttpPost]
        public async Task<IActionResult> Login(LoginModel model)
        {
            if (!ModelState.IsValid) return View(model);
            var result = await _authService.LoginAsync(model);
            if(result.StatusCode==1)
            {
                return RedirectToAction("Display", "Dashboard");
            }
            else
            {
                TempData["msg"] = result.Message;
                return View();
            }
        }


        [HttpGet]
        public IActionResult Register()
        {
            return View();
        }

    

        [HttpPost]
        public async Task<IActionResult> Register(RegisterModel model)
        {
            if (!ModelState.IsValid) return View(model);
            model.Role = "Guest";
            var result = await _authService.RegisterAsync(model);
            TempData["msg"] = result.Message;

            if (result.StatusCode == 1)
            {
                var signInResult = await _authService.LoginAsync(new LoginModel { Email = model.Email, Password = model.Password });
                if (signInResult.StatusCode == 1)
                {
                    return RedirectToAction("Display", "Dashboard"); 
                }
            }

            return View();
        }


        [HttpPost]
        [AllowAnonymous]

        public IActionResult ExternalLogin(string provider, string returnUrl = null)
            {
            var redirectUrl = Url.Action("ExternalLoginCallback", "Account", new { returnUrl });
            var properties = _authService.signInManager.ConfigureExternalAuthenticationProperties(provider, redirectUrl);
            return Challenge(properties, provider);
       
        }


        [HttpPost]
        [AllowAnonymous]
        public async Task<IActionResult> ExternalLoginConfirmation(ExternalLoginViewModel model, string returnUrl = null)
        {
            model.Role = "Guest";
            returnUrl = returnUrl ?? Url.Content("~/");
            if (ModelState.IsValid)
            {
              
                var info = await _authService.signInManager.GetExternalLoginInfoAsync();
                if (info == null)
                {
                    return RedirectToAction("Login");
                }

                
                var user = new ApplicationUser { UserName = model.Email, Email = model.Email };


                var result = await _authService.userManager.CreateAsync(user);
                if (result.Succeeded)
                {
                    result = await _authService.userManager.AddLoginAsync(user, info);
                    if (result.Succeeded)
                    {
                        await _authService.userManager.AddToRoleAsync(user, model.Role);
                     
                        await _authService.signInManager.SignInAsync(user, isPersistent: false);

                       
                        return RedirectToAction("Display", "Dashboard");
                    }
                }

                foreach (var error in result.Errors)
                {
                    ModelState.AddModelError(string.Empty, error.Description);
                }
            }

       
            return View(model);
        }

        [HttpGet]
        [AllowAnonymous]
        public async Task<IActionResult> ExternalLoginCallback(string returnUrl = null, string remoteError = null)
        {
            try
            {
                if (remoteError != null)
                {
                    return RedirectToAction("Login");
                }
                var info = await _authService.signInManager.GetExternalLoginInfoAsync();
                if (info == null)
                {

                    return RedirectToAction("Login");
                }
                var result = await _authService.signInManager.ExternalLoginSignInAsync(info.LoginProvider, info.ProviderKey, isPersistent: false);
                if (result.Succeeded)
                {
        
                    if (Url.IsLocalUrl(returnUrl))
                    {
                      
                        return LocalRedirect(returnUrl);
                    }
                    else
                    {
                        return RedirectToAction("Display", "Dashboard");
                    }
                }

               

                if (result.IsLockedOut)
                {
                    return RedirectToAction("Login");
                }
                else
                {
                   
                    ViewData["ReturnUrl"] = returnUrl;
                    ViewData["LoginProvider"] = info.LoginProvider;
                    var email = info.Principal.FindFirstValue(ClaimTypes.Email);
                    return View("ExternalLogin", new ExternalLoginViewModel { Email = email,Role="Guest" });
                }
            }
            catch(Exception ex)
            {
                return View();
            }
        }


        [Authorize] 
        public async Task<IActionResult> Logout()
        {
            await _authService.LogoutAsync();  
            return RedirectToAction("Login", "Account");
        }
        


    }
}
