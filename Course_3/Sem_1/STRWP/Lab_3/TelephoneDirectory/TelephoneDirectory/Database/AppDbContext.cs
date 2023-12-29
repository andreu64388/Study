using Microsoft.EntityFrameworkCore;
using TelephoneDirectory.Domain.Entity;

namespace TelephoneDirectory.Domain;


    public class AppDbContext : DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options)
        {
            Database.EnsureCreated();
        }
        public DbSet<ContactEntity> Contacts { get; set; }
    }
