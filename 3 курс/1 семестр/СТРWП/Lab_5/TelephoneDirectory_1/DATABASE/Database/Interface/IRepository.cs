namespace DATABASE.Interface;


public interface IRepository<T>
{
    Task<List<T>> GetAll();
    T GetById(Guid id);
    Task Create(T data);
    Task Update(T data);
    Task Remove(T data);
}