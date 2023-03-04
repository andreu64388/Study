using Lab_9.Class;
using System;
using System.Windows;

namespace Lab_9.WIndows
{
	/// <summary>
	/// Логика взаимодействия для EditUser.xaml
	/// </summary>
	public partial class EditUser : Window
	{
		private int Id { get; set; }

		public EditUser(int id)
		{
			Id = id;
			InitializeComponent();

			try
			{
				using (var context = new Lab_9.DB.DB())
				{
					User user = context.GetUserById(id);
					FirsName.Text = user.FirstName;
					LastName.Text = user.LastName;
					Phone.Text = user.Phone;
					Email.Text = user.Email;
					Address.Text = user.Address;
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
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
					address.Length == 0 || phone.Length == 0
					|| email.Length == 0)
				{
					throw new Exception("Error");
				}
				try
				{
					using (var context = new Lab_9.DB.DB())
					{
						User user = context.GetUserById(Id);
						if (user != null)
						{
							user.FirstName = firstname;
							user.LastName = lastname;
							user.Phone = phone;
							user.Email = email;
							user.Address = address;
							context.SaveChanges();
						}
					}
				}
				catch (Exception ex)
				{
					MessageBox.Show(ex.Message);
				}
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

		private void Button_Click_2(object sender, RoutedEventArgs e)
		{
			AddOrder addOrder = new AddOrder(Id);
			addOrder.Show();
		}
	}
}