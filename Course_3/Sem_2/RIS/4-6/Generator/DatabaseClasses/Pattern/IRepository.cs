using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DatabaseClasses.Pattern
{
    public interface IRepository<TEntity> where TEntity : class
    {
        //Получить всю коллекцию
        IEnumerable<TEntity> GetItems();

        //Добавление элемента в таблицу
        void AddItem(TEntity item);

        //Обновить элемент
        void UpdateItem(TEntity item);
    }
}
