   
    using TelephoneDirectory.Domain.Entity;
    using TelephoneDirectory.Models;

    namespace TelephoneDirectory.Service;


public class ContactService : IServiceContact
{
    private readonly IRepository<ContactEntity> _contactRepository;

    public ContactService(IRepository<ContactEntity> contactRepository)
    {
        _contactRepository = contactRepository;
    }

    public async Task<List<ContactEntity>> GetAll()
    {
        var contactEntities = await _contactRepository.GetAll();
        return contactEntities;
    }

    public async Task<ContactEntity> GetById(Guid id)
    {
        var contactEntity = await _contactRepository.GetId(id);
        return contactEntity;
    }

    public async Task Add(Contact data)
    {
        var contactEntity = new ContactEntity
        {
            Id = Guid.NewGuid(),
            Name = data.Name,
            PhoneNumber = data.PhoneNumber
        };

        await _contactRepository.Create(contactEntity);
    }
    

    public async Task Update(Contact data)
    {
        var contactEntity = new ContactEntity
        {
            Id = data.Id,
            Name = data.Name,
            PhoneNumber = data.PhoneNumber
        };

        await _contactRepository.Update(contactEntity);
    }

    public async Task Delete(Guid id)
    {
        var contactEntity = await _contactRepository.GetId(id);
        await _contactRepository.Remove(contactEntity);
        
    }
}
