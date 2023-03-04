using Lab_9.Class;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Threading.Tasks;

namespace Lab_9.DB
{
	public class DB : DbContext
	{
		public DB() : base("name=Test")
		{
		}

		public DbSet<User> Users { get; set; }
		public DbSet<Orders> Orders { get; set; }

		public User GetUserById(int id)
		{
			return Users.FirstOrDefault(u => u.UserID == id);
		}

		public async Task<List<User>> SortByAsync(string param)
		{
			using (var context = new DB())
			{
				IQueryable<User> query = context.Users.AsQueryable();

				switch (param)
				{
					case "firstname":
						query = query.OrderBy(u => u.FirstName);
						break;

					case "phone":
						query = query.OrderBy(u => u.Phone);
						break;

					case "id":
						query = query.OrderBy(u => u.UserID);
						break;

					case "lastname":
						query = query.OrderBy(u => u.LastName);
						break;

					case "address":
						query = query.OrderBy(u => u.Address);
						break;

					case "email":
						query = query.OrderBy(u => u.Email);
						break;

					default:
						throw new ArgumentException($"Unknown parameter '{param}'");
				}

				return await query.ToListAsync();
			}
		}
	}
}