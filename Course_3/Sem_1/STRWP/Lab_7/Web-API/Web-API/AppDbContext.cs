

using Microsoft.EntityFrameworkCore;
using TelephoneDirectory.Entity;

namespace ContactRepository;


    public class AppDbContext : DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options)
        {
            Database.EnsureCreated();
        }
        public DbSet<ContactEntity> Contacts { get; set; }
    }
