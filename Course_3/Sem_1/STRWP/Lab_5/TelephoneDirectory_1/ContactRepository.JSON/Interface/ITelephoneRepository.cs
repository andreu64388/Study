namespace ContactRepository.Interface;

public interface ITelephoneRepository<T>
{
    public List<T> GetAllContacts();
    public T GetContactById(Guid id);
    public void AddContact(T contact);
    public void UpdateContact(T updatedContact);
    public void DeleteContact(Guid id);


}