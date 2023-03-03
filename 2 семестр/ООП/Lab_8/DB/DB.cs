using Lab_8.Class;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Windows;

namespace Lab_8.DB
{
	public static class DB
	{
		private static SqlConnection connection;
		private static readonly string connectionString = ConfigurationManager.AppSettings["ConnectionString"];

		private static void OpenConnection()
		{
			if (connection == null)
			{
				connection = new SqlConnection(connectionString);
			}
			if (connection.State != System.Data.ConnectionState.Open)
			{
				connection.Open();
			}
		}

		private static void CloseConnection()
		{
			if (connection != null && connection.State == System.Data.ConnectionState.Open)
			{
				connection.Close();
			}
		}

		public static void AddUser(User user)
		{
			OpenConnection();

			string query = "INSERT INTO Users (FirstName, LastName, Email, Phone, Address,UserID,Image) VALUES (@FirstName, @LastName, @Email, @Phone, @Address,@UserID,@Image)";

			using (SqlCommand command = new SqlCommand(query, connection))
			{
				command.Parameters.AddWithValue("@FirstName", user.FirstName);
				command.Parameters.AddWithValue("@LastName", user.LastName);
				command.Parameters.AddWithValue("@Email", user.Email);
				command.Parameters.AddWithValue("@Phone", user.Phone);
				command.Parameters.AddWithValue("@Address", user.Address);
				command.Parameters.AddWithValue("@UserID", user.UserID);
				command.Parameters.AddWithValue("@Image", user.Image);

				int rowsAffected = command.ExecuteNonQuery();
			}

			CloseConnection();
		}

		public static void AddUserWithProcedure(User user)
		{
			OpenConnection();

			using (SqlCommand command = new SqlCommand("AddUsers", connection))
			{
				command.CommandType = CommandType.StoredProcedure;
				command.Parameters.AddWithValue("@FirstName", user.FirstName);
				command.Parameters.AddWithValue("@LastName", user.LastName);
				command.Parameters.AddWithValue("@Email", user.Email);
				command.Parameters.AddWithValue("@Phone", user.Phone);
				command.Parameters.AddWithValue("@Address", user.Address);
				command.Parameters.AddWithValue("@UserID", user.UserID);
				command.Parameters.AddWithValue("@Image", user.Image);

				int rowsAffected = command.ExecuteNonQuery();
				MessageBox.Show(rowsAffected.ToString());
			}

			CloseConnection();
		}

		public static User GetUserById(int userId)
		{
			OpenConnection();

			string query = "SELECT * FROM Users WHERE UserID = @UserID";

			using (SqlCommand command = new SqlCommand(query, connection))
			{
				command.Parameters.AddWithValue("@UserID", userId);

				SqlDataReader reader = command.ExecuteReader();

				while (reader.Read())
				{
					int id = reader.GetInt32(0);
					string firstName = reader.GetString(1);
					string lastName = reader.GetString(2);
					string email = reader.GetString(3);
					string phone = reader.GetString(4);
					string address = reader.GetString(5);
					byte[] image = (byte[])reader["Image"];


					User userIDS = new User
					{
						FirstName = firstName,
						LastName = lastName,
						Email = email,
						Phone = phone,
						Address = address,
						UserID = id,
						Image = image
					};

					return userIDS;
				}

				reader.Close();
			}

			CloseConnection();
			return null;
		}

		public static void DeleteUser(int userId)
		{
			try
			{
				OpenConnection();
				string query = "DELETE FROM USERS WHERE USERID=@ID";
				using (SqlCommand command = new SqlCommand(query, connection))
				{
					command.Parameters.AddWithValue("@ID", userId);
					int result = command.ExecuteNonQuery();
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
			finally
			{
				CloseConnection();
			}
		}

		public static void UpdateUser(int userId, User user)
		{
			try
			{
				OpenConnection();
				string query = "UPDATE USERS SET FirstName=@FirstName, LastName=@LastName, Email=@Email, Address=@Address, Phone=@Phone WHERE UserId=@UserId";
				using (SqlCommand command = new SqlCommand(query, connection))
				{
					command.Parameters.AddWithValue("@UserId", userId);
					command.Parameters.AddWithValue("@FirstName", user.FirstName);
					command.Parameters.AddWithValue("@LastName", user.LastName);
					command.Parameters.AddWithValue("@Email", user.Email);
					command.Parameters.AddWithValue("@Address", user.Address);
					command.Parameters.AddWithValue("@Phone", user.Phone);
					int result = command.ExecuteNonQuery();
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
			finally
			{
				CloseConnection();
			}
		}

		public static IEnumerable<User> Sort(string sortBy)
		{
			var users = GetAllUsers().ToList();

			switch (sortBy.ToLower())
			{
				case "id":
					users.Sort((u1, u2) => u1.UserID.CompareTo(u2.UserID));
					break;

				case "firstname":
					users.Sort((u1, u2) => u1.FirstName.CompareTo(u2.FirstName));
					break;

				case "lastname":
					users.Sort((u1, u2) => u1.LastName.CompareTo(u2.LastName));
					break;

				case "email":
					users.Sort((u1, u2) => u1.Email.CompareTo(u2.Email));
					break;

				case "phone":
					users.Sort((u1, u2) => u1.Phone.CompareTo(u2.Phone));
					break;

				case "address":
					users.Sort((u1, u2) => u1.Address.CompareTo(u2.Address));
					break;

				default:
					throw new ArgumentException("Invalid sort parameter");
			}

			return users;
		}

		public static IEnumerable<User> GetAllUsers()
		{
			try
			{
				OpenConnection();
				string query = "SELECT * FROM USERS";
				List<User> users = new List<User>();
				using (SqlCommand command = new SqlCommand(query, connection))
				{
					using (SqlDataReader reader = command.ExecuteReader())
					{
						while (reader.Read())
						{
							int id = reader.GetInt32(0);
							string firstName = reader.GetString(1);
							string lastName = reader.GetString(2);
							string email = reader.GetString(3);
							string phone = reader.GetString(4);
							string address = reader.GetString(5);
							byte[] image = (byte[])reader["Image"];
							User user = new User
							{
								FirstName = firstName,
								LastName = lastName,
								Email = email,
								Phone = phone,
								Address = address,
								UserID = id,
								Image= image
							};

							users.Add(user);
						}
						reader.Close();
						return users;
					}
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
				return null;
			}
			finally { CloseConnection(); }
		}
	}
}