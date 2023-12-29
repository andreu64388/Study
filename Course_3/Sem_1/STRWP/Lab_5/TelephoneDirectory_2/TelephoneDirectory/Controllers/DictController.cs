using System;
using System.Diagnostics;
using System.Threading.Tasks;
using ContactRepository;
using Microsoft.AspNetCore.Mvc;
using TelephoneDirectory.Entity;
using TelephoneDirectory.Models;
using Contact = ContactRepository.Model.Contact;

namespace TelephoneDirectory.Controllers;


public class DictController : Controller
{
    private readonly ITelephoneRepository<ContactEntity> _contactService;

    public DictController(ITelephoneRepository<ContactEntity> contactService)
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
    public async Task<IActionResult> AddSave(ContactEntity data)
    {
        await _contactService.Create(data);
        return RedirectToAction("Index");
    }

    [HttpGet]
    public async Task<IActionResult> Update(Guid id)
    {
        var contact = await _contactService.GetId(id);
            
        if (contact == null) return View("Error");
            
        return View(contact);
            
    }

    [HttpPost]
    public async Task<IActionResult> UpdateSave(ContactEntity data)
    {
        await _contactService.Update(data);
        return RedirectToAction("Index");
    }

    [HttpGet]
    public async Task<IActionResult> Delete(Guid id)
    {
        var contact = await _contactService.GetId(id);
            
        if (contact == null) return View("Error");
            
        return View(contact);
    }

    [HttpPost]
    public async Task<IActionResult> DeleteSave(Guid id)
    {
        var contact = await _contactService.GetId(id);
        await _contactService.Remove(contact);
        return RedirectToAction("Index");
    }

    [HttpGet]
    public ActionResult Error()
    {
        return View();
    }
}