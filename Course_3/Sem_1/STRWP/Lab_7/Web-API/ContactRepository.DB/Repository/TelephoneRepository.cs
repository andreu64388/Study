
using ContactRepository.Model;
using Microsoft.EntityFrameworkCore;
using Newtonsoft.Json;
using TelephoneDirectory.Entity;

namespace ContactRepository.Repository;

public class TelephoneRepository:ITelephoneRepository<ContactEntity>
{
    private readonly AppDbContext _appDbContext;

    public TelephoneRepository(AppDbContext appDbContext)
    {
        _appDbContext = appDbContext;
    }

    public async Task<List<ContactEntity>> GetAll()
    {
        var contacts = await _appDbContext.Contacts.OrderBy(n => n.Name).ToListAsync();
        return contacts;
    }
     
    public async Task<ContactEntity> GetId(Guid id)
    {
        var contact = await _appDbContext.Contacts.FirstOrDefaultAsync(c => c.Id == id);

        if (contact == null) return null;
         
        return contact;
    }

     
    public async Task Create(ContactEntity data)
    { 
        await _appDbContext.Contacts.AddAsync(data);
        await _appDbContext.SaveChangesAsync();
    }

    public async Task Update(ContactEntity data)
    {
        _appDbContext.Contacts.Update(data);
        await _appDbContext.SaveChangesAsync();
    }


    public async Task Remove(ContactEntity data)
    {
        _appDbContext.Contacts.Remove(data);
        await _appDbContext.SaveChangesAsync();
    }
}
