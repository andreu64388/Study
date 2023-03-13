using Lab_9.Class;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Linq.Expressions;
using System.Threading.Tasks;

namespace Lab_9.DB
{
	/*	public class DB : DbContext
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
		}*/




	public class DB : DbContext
	{
		public DB() : base("name=Test")
		{
		}

		public DbSet<User> Users { get; set; }
		public DbSet<Orders> Orders { get; set; }

		public IRepository<User> UserRepository => new UserRepository(this);
		public IRepository<Orders> OrdersRepository => new OrdersRepository(this);
	}



	public interface IRepository<T> where T : class
	{
	
		IEnumerable<T> GetAll();

		Task<IEnumerable<T>> GetAllAsync();

		void Add(T entity);

		void Update(T entity);

		void Remove(T entity);

		T Find(object val);

	}

	public class UserRepository : IRepository<User>
	{
		private readonly DB _dbContext;

		public UserRepository(DB dbContext)
		{
			_dbContext = dbContext;
		}

		public IEnumerable<User> GetAll()
		{
			return _dbContext.Users.ToList();
		}

		public async Task<IEnumerable<User>> GetAllAsync()
		{
			return await _dbContext.Users.ToListAsync();
		}

		public void Add(User user)
		{
			_dbContext.Users.Add(user);
			_dbContext.SaveChanges();
		}

		public void Update(User user)
		{
			_dbContext.Entry(user).State = EntityState.Modified;
			_dbContext.SaveChanges();
		}

		public void Remove(User user)
		{
			_dbContext.Users.Remove(user);
			_dbContext.SaveChanges();
		}

		public User Find(object id)
		{
			return _dbContext.Users.Find(id);
		}
	}

	public class OrdersRepository : IRepository<Orders>
	{
		private readonly DB _dbContext;

		public OrdersRepository(DB dbContext)
		{
			_dbContext = dbContext;
		}

		public IEnumerable<Orders> GetAll()
		{
			return _dbContext.Orders.ToList();
		}

		public async Task<IEnumerable<Orders>> GetAllAsync()
		{
			return await _dbContext.Orders.ToListAsync();
		}

		public void Add(Orders orders)
		{
			_dbContext.Orders.Add(orders);
			_dbContext.SaveChanges();
		}

		public void Update(Orders orders)
		{
			_dbContext.Entry(orders).State = EntityState.Modified;
			_dbContext.SaveChanges();
		}

		public void Remove(Orders orders)
		{
			_dbContext.Orders.Remove(orders);
			_dbContext.SaveChanges();
		}

		public Orders Find(object id)
		{
			return _dbContext.Orders.Find(id);
		}
	}

	public class UnitOfWork : IDisposable
	{
		private readonly DB _dbContext;
		private bool disposed = false;

		public UnitOfWork()
		{
			_dbContext = new DB();
		}

		private IRepository<User> _userRepository;
		public IRepository<User> UserRepository
		{
			get
			{
				if (_userRepository == null)
					_userRepository = new UserRepository(_dbContext);
				return _userRepository;
			}
		}

		private IRepository<Orders> _ordersRepository;
		public IRepository<Orders> OrdersRepository
		{
			get
			{
				if (_ordersRepository == null)
					_ordersRepository = new OrdersRepository(_dbContext);
				return _ordersRepository;
			}
		}

		public void Save()
		{
			_dbContext.SaveChanges();
		}

		protected virtual void Dispose(bool disposing)
		{
			if (!disposed)
			{
				if (disposing)
				{
					_dbContext.Dispose();
				}
				disposed = true;
			}
		}

		public void Dispose()
		{
			Dispose(true);
			GC.SuppressFinalize(this);
		}
	}





	/*public class DB : DbContext
	{
		private readonly IUnitOfWork _unitOfWork;

		public DB() : base("name=Test")
		{
			_unitOfWork = new UnitOfWork(this);
		}

		public IUnitOfWork UnitOfWork => _unitOfWork;
	}
	*/
}

/*Паттерн Репозиторий используется для абстрагирования работы с базой данных,
 * предоставляя интерфейс для создания, чтения, обновления и удаления данных без необходимости знать
 * , как они хранятся в базе данных.
В данном случае, можно создать интерфейс IRepository<T>, который будет определять методы 
для работы с сущностями типа T:
 * 
 * 
 * 
 * 
 * 
 * 
 * Паттерн Unit of Work используется для группировки операций с базой данных в одну 
 * транзакцию. Он предоставляет интерфейс для работы с репозиториями, а также для 
 * начала и завершения транзакции.

В данном случае, можно создать интерфейс IUnitOfWork,
который будет определять методы для работы с репозиториями и
для управления транзакцией:*/