using Microsoft.EntityFrameworkCore;
using System.Linq;
using DATABASE.Entity;

namespace DATABASE;


    public class AppDbContext : DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options)
        {
            Database.EnsureCreated();
        }
        public DbSet<ContactEntity> Contacts { get; set; }
    }
