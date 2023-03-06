using Lab_9.Class;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Linq.Expressions;
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

	/*	public class DB : DbContext
		{
			private readonly IRepository<User> _userRepository;
			private readonly IRepository<Orders> _orderRepository;

			public DB() : base("name=Test")
			{
				_userRepository = new Repository<User>(this);
				_orderRepository = new Repository<Orders>(this);
			}

			public IRepository<User> Users => _userRepository;
			public IRepository<Orders> Orders => _orderRepository;
		}

	*/

	public interface IRepository<T> where T : class
	{
		T GetById(int id);

		Task<T> GetByIdAsync(int id);

		IEnumerable<T> GetAll();

		Task<IEnumerable<T>> GetAllAsync();

		void Add(T entity);

		void Update(T entity);

		void Remove(T entity);

		IEnumerable<T> ToList();

		T Find(object val);

		IEnumerable<T> GetAllWithNavigationProperties(params Expression<Func<T, object>>[] includeProperties);
	}

	public class Repository<T> : IRepository<T> where T : class
	{
		private readonly DbContext _context;
		private readonly DbSet<T> _set;

		public Repository(DbContext context)
		{
			_context = context;
			_set = context.Set<T>();
		}

		public T GetById(int id)
		{
			return _set.Find(id);
		}

		public IEnumerable<T> ToList()
		{
			return _set.ToList();
		}

		public async Task<T> GetByIdAsync(int id)
		{
			return await _set.FindAsync(id);
		}

		public IEnumerable<T> GetAll()
		{
			return _set.ToList();
		}

		public T Find(object val)
		{
			return _set.Find(val);
		}

		public async Task<IEnumerable<T>> GetAllAsync()
		{
			return await _set.ToListAsync();
		}

		public void Add(T entity)
		{
			_set.Add(entity);
		}

		public void Update(T entity)
		{
			_set.Attach(entity);
			_context.Entry(entity).State = EntityState.Modified;
		}

		public void Remove(T entity)
		{
			if (_context.Entry(entity).State == EntityState.Detached)
			{
				_set.Attach(entity);
			}

			_set.Remove(entity);
		}

		public IEnumerable<T> GetAllWithNavigationProperties(params Expression<Func<T, object>>[] includeProperties)
		{
			IQueryable<T> query = _set;
			foreach (var includeProperty in includeProperties)
			{
				query = query.Include(includeProperty);
			}
			return query.ToList();
		}
	}

	public interface IUnitOfWork : IDisposable
	{
		IRepository<User> Users { get; }
		IRepository<Orders> Orders { get; }

		void BeginTransaction();

		void Commit();

		void Rollback();

		Task SaveChangesAsync();
	}

	public class UnitOfWork : IUnitOfWork
	{
		private readonly DbContext _context;
		private readonly IRepository<User> _userRepository;
		private readonly IRepository<Orders> _orderRepository;
		private DbContextTransaction _transaction;

		public UnitOfWork(DbContext context)
		{
			_context = context;
			_userRepository = new Repository<User>(context);
			_orderRepository = new Repository<Orders>(context);
		}

		public IRepository<User> Users => _userRepository;
		public IRepository<Orders> Orders => _orderRepository;

		public void BeginTransaction()
		{
			_transaction = _context.Database.BeginTransaction();
		}

		public void Commit()
		{
			try
			{
				_context.SaveChanges();
				_transaction?.Commit();
			}
			catch
			{
				Rollback();
				throw;
			}
		}

		public void Rollback()
		{
			_transaction?.Rollback();
			_transaction = null;
		}

		public async Task SaveChangesAsync()
		{
			await _context.SaveChangesAsync();
		}

		public void Dispose()
		{
			_transaction?.Dispose();
			_context.Dispose();
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