

using TelephoneDirectory.Domain.Entity;
using TelephoneDirectory.Models;
using TelephoneDirectory.Service;

public interface IServiceContact
{
    Task<List<ContactEntity>> GetAll();
    Task<ContactEntity> GetById(Guid id);
    Task Add(Contact data);
    Task Update(Contact data);
    Task Delete(Guid id);
}