using Lab_8.Class;
using System;
using System.Data.SqlClient;
using System.Windows;

namespace Lab_8.DB
{
	public static class TestBD
	{
		private static string connectionString = @"Data Source=ANDREY;Initial Catalog=Shop;Integrated Security=True";
		private static SqlConnection connect;

		public static void OpenConnection()
		{
			if (connect == null)
			{
				connect = new SqlConnection(connectionString);
			}
			if (connect.State != System.Data.ConnectionState.Open)
			{
				connect.Open();
			}
		}

		public static void CloseConnection()
		{
			if (connect != null && connect.State == System.Data.ConnectionState.Open)
			{
				connect.Close();
			}
		}

		public static void AddUser(User user)
		{
			try
			{
				OpenConnection();
				string query = "INSERT INTO USERS (FirstName, LastName, Email, Phone, Address,UserID) VALUES (@FirstName, @LastName, @Email, @Phone, @Address,@UserID)";

				using (SqlCommand sqlCommand = new SqlCommand(query, connect))
				{
					sqlCommand.Parameters.AddWithValue("@FirstName", user.FirstName);
					sqlCommand.Parameters.AddWithValue("@LastName", user.LastName);
					sqlCommand.Parameters.AddWithValue("@Email", user.Email);
					sqlCommand.Parameters.AddWithValue("@Phone", user.Phone);
					sqlCommand.Parameters.AddWithValue("@Address", user.Address);
					sqlCommand.Parameters.AddWithValue("@UserID", user.UserID);

					int query_result = sqlCommand.ExecuteNonQuery();

					MessageBox.Show(query_result.ToString());
				}
				CloseConnection();
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
		}

		public static User GetUser(string ID)
		{
			try
			{
				User user = null;
				OpenConnection();
				string query = "SELECT * FROM USERS WHERE UserID = @ID";

				using (SqlCommand command = new SqlCommand(query, connect))
				{
					command.Parameters.AddWithValue("@ID", ID);

					SqlDataReader reader = command.ExecuteReader();
					while (reader.Read())
					{
						int id = Convert.ToInt32(reader["UserID"]);
						string FirstName = reader["FirsName"].ToString();
						string LastName = reader["LastName"].ToString();
						string email = reader["Email"].ToString();
						string phone = reader["Phone"].ToString();
						string address = reader["Address"].ToString();

						user = new User()
						{
							FirstName = FirstName,
							LastName = LastName,
							Email = email,
							Phone = phone,
							Address = address
						};

						return user;
					};

					reader.Close();
				}
				CloseConnection();
				return null;
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
				return null;
			}
		}
	}
}