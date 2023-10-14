using System;
using System.Diagnostics;
using ContactRepository;
using ContactRepository.Interface;
using Microsoft.AspNetCore.Mvc;
using TelephoneDirectory.Models;
using Contact = ContactRepository.Model.Contact;

namespace TelephoneDirectory.Controllers;


public class DictController : Controller
{
    private readonly ITelephoneRepository<Contact> _contactService;

    public DictController(ITelephoneRepository<Contact> contactService)
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
   public IActionResult AddSave(ContactRepository.Model.Contact contact)
   {
       _contactService.AddContact(contact);
       return  RedirectToAction("Index");
   }
   
   [HttpGet]
   public IActionResult Update(Guid id)
   { 
       ContactRepository.Model.Contact contact= _contactService.GetContactById(id);
       return View(contact);
   }
   
    [HttpPost]
   public IActionResult UpdateSave(ContactRepository.Model.Contact contact)
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