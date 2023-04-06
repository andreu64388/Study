using Lab_8.Class;
using System;
using System.Windows;

namespace Lab_8.Pages
{
	/// <summary>
	/// Логика взаимодействия для EditUser.xaml
	/// </summary>
	public partial class EditUser : Window
	{
		private int Id { get; set; }

		public EditUser(int val)
		{
			User user = DB.DB.GetUserById(val);
			InitializeComponent();
			FirsName.Text = user.FirstName;
			LastName.Text = user.LastName;
			Address.Text = user.Address;
			Phone.Text = user.Phone;
			Email.Text = user.Email;
			Id = val;
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			try
			{
				string firstname = FirsName.Text.Trim();
				string lastname = LastName.Text.Trim();
				string address = Address.Text.Trim();
				string phone = Phone.Text.Trim();
				string email = Email.Text.Trim();

				if (firstname.Length == 0 || lastname.Length == 0 ||
					address.Length == 0 || phone.Length == 0 || email.Length == 0)
				{
					throw new Exception("Error");
				}

				User user = new User()
				{
					UserID = Id,
					FirstName = firstname,
					LastName = lastname,
					Address = address,
					Phone = phone,
					Email = email
				};

				DB.DB.UpdateUser(Id, user);

				this.Close();
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
		}

		private void Button_Click_1(object sender, RoutedEventArgs e)
		{
			this.Close();
		}
	}
}