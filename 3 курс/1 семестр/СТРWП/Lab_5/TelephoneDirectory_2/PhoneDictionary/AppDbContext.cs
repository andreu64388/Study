using Microsoft.EntityFrameworkCore;
using PhoneDictionary.Entity;

namespace PhoneDictionary;


    public class AppDbContext : DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options)
        {
            Database.EnsureCreated();
        }
        public DbSet<ContactEntity> Contacts { get; set; }
    }
