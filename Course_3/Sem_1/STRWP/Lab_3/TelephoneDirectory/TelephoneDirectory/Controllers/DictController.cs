using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using TelephoneDirectory.Models;
using TelephoneDirectory.Service;

namespace TelephoneDirectory.Controllers;


public class DictController : Controller
{

        private readonly IServiceContact _contactService;

        public DictController(IServiceContact contactService)
        {
            _contactService = contactService;
        }

        [HttpGet]
        public async Task<IActionResult> Index()
        { 
            var contacts = await _contactService.GetAll();
            return View(contacts);
        }

        [HttpGet]
        public IActionResult Add()
        {
            return View();
        }

        [HttpPost]
        public async Task<IActionResult> AddSave(Contact data)
        {
            await _contactService.Add(data);
            return RedirectToAction("Index");
        }

        [HttpGet]
        public async Task<IActionResult> Update(Guid id)
        {
            var contact = await _contactService.GetById(id);
            
            if (contact == null) return View("Error");
            
            return View(contact);
            
        }

        [HttpPost]
        public async Task<IActionResult> UpdateSave(Contact data)
        {
            await _contactService.Update(data);
            return RedirectToAction("Index");
        }

        [HttpGet]
        public async Task<IActionResult> Delete(Guid id)
        {
            var contact = await _contactService.GetById(id);
            
            if (contact == null) return View("Error");
            
            return View(contact);
        }

        [HttpPost]
        public async Task<IActionResult> DeleteSave(Guid id)
        {
            await _contactService.Delete(id);
            return RedirectToAction("Index");
        }

        [HttpGet]
        public ActionResult Error()
        {
            return View();
        }
}