using ContactRepository.Interface;
using ContactRepository.Model;
using Newtonsoft.Json;

namespace ContactRepository;

public class TelephoneRepository:ITelephoneRepository<Contact>
{
    private const string DataFilePath = "contacts.json";
    private List<Contact> contacts;

    public TelephoneRepository()
    {
        LoadData();
    }

    public List<Contact> GetAllContacts()
    {
        return contacts.OrderBy(c => c.Name).ToList();
    }

    public Contact GetContactById(Guid id)
    {
        var contact = contacts.FirstOrDefault(c => c.Id == id);
        if (contact == null) throw new Exception("Contact not found");
        return contact;
    }


    public void AddContact(Contact contact)
    {
        contact.Id = Guid.NewGuid();
        contacts.Add(contact);
        SaveData();
    }

    public void UpdateContact(Contact updatedContact)
    {
        
        var existingContact = GetContactById(updatedContact.Id);
       
        existingContact.Name = updatedContact.Name;
        existingContact.PhoneNumber = updatedContact.PhoneNumber;
            
        SaveData();
        
    }

    public void DeleteContact(Guid id)
    {
        var contactToRemove = GetContactById(id);
        contacts.Remove(contactToRemove);
        SaveData();
        
    }

    private void LoadData()
    {
        if (System.IO.File.Exists(DataFilePath))
        {
            var jsonData = System.IO.File.ReadAllText(DataFilePath);
            contacts = JsonConvert.DeserializeObject<List<Contact>>(jsonData);
        }
        else
        {
            contacts = new List<Contact>();
        }
    }

    private void SaveData()
    {
        var jsonData = JsonConvert.SerializeObject(contacts);
        System.IO.File.WriteAllText(DataFilePath, jsonData);
    }
}