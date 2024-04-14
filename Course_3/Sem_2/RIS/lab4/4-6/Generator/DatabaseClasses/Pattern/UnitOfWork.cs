using System;

namespace DatabaseClasses.Pattern
{
    public class UnitOfWork : IDisposable
    {
        private DBContext context;
        public UnitOfWork(string context)
        {
            this.context = new DBContext(context);
        }

        private DataRepository dataRepository;

        public DataRepository DataRepository
        {
            get
            {
                if (dataRepository == null)
                    dataRepository = new DataRepository(context);
                return dataRepository;
            }
        }

        public void Save()
        {
            context.SaveChanges();
        }

        private bool disposed = false;

        public virtual void Dispose(bool disposing)
        {
            if (!this.disposed)
            {
                if (disposing)
                {
                    context.Dispose();
                }
                this.disposed = true;
            }
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
    }
}
