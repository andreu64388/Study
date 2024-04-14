using Models;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DatabaseClasses.Pattern
{
    public class DataRepository : IRepository<Data>
    {
        DBContext context;
        public DataRepository(DBContext context)
        {
            this.context = context;
        }

        public IEnumerable<Data> GetItems()
        {
            return context.Datas.AsNoTracking().Where(u => u.ItNew == true).Select(x=>x);
        }

        public void AddItem(Data item)
        {
            if (item != null)
                context.Datas.Add(item);
        }

        public void UpdateItem(Data item)
        {
            context.Entry(item).State = EntityState.Modified;
        }
    }
}
