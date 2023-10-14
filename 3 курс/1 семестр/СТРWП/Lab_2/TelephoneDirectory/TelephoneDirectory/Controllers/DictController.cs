using System;
using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using TelephoneDirectory.Models;
using TelephoneDirectory.Service;

namespace TelephoneDirectory.Controllers;


public class DictController : Controller
{
    private readonly ContactService _contactService;

    public DictController(ContactService contactService)
    {
        _contactService = contactService;
    }
    
    [HttpGet]
   public IActionResult Index()
    {
        var contacts = _contactService.GetAllContacts();
        return View(contacts);
    }
   
   [HttpGet]
   public IActionResult Add()
   {
       return View();
   }
   
   [HttpPost]
   public IActionResult AddSave(Contact contact)
   {
       _contactService.AddContact(contact);
       return  RedirectToAction("Index");
   }
   
   [HttpGet]
   public IActionResult Update(Guid id)
   { 
       Contact contact= _contactService.GetContactById(id);
       return View(contact);
   }
   
    [HttpPost]
   public IActionResult UpdateSave(Contact contact)
   {
         _contactService.UpdateContact(contact);
       return RedirectToAction("Index");
   }

   [HttpGet]
   public IActionResult Delete(Guid id)
   {
       Contact contact = _contactService.GetContactById(id);
       return View(contact);
   }
   
   [HttpPost]
   public IActionResult DeleteSave(Guid id)
   {
         _contactService.DeleteContact(id);
       return RedirectToAction("Index");
   }
   
   [HttpGet]
    public ActionResult Error()
    {
        return View();
    }
}