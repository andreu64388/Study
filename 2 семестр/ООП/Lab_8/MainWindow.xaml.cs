using Lab_8.Class;
using Lab_8.Pages;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace Lab_8
{
	/// <summary>
	/// Логика взаимодействия для MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			InitializeComponent();

			try
			{
				/*User user = new User() { FirstName = "Stas", LastName = "Gaykow", Address = "12.2112", UserID = 1, Email = "fds", Phone = "+3753032" };
				Lab_8.DB.DB.AddUserWithProcedure(user);*/
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
			finally
			{
			}
		}

		private void Button_Delete(object sender, RoutedEventArgs e)
		{
			var myValue = ((Button)sender).Tag;

			Lab_8.DB.DB.DeleteUser((int)myValue);
			List<User> users = (List<User>)Lab_8.DB.DB.GetAllUsers();

			productDataGrid.ItemsSource = users;
		}

		private void Button_Edit(object sender, RoutedEventArgs e)
		{
			int myValue = (int)((Button)sender).Tag;

			EditUser edit = new EditUser(myValue);

			edit.Show();
		}

		private async void LoadDataButton_Click(object sender, RoutedEventArgs e)
		{
			LoadingGrid.Visibility = Visibility.Visible;
			productDataGrid.Visibility = Visibility.Collapsed;

			List<User> data = await LoadDataAsync();

			LoadingGrid.Visibility = Visibility.Collapsed;
			productDataGrid.Visibility = Visibility.Visible;

			productDataGrid.ItemsSource = data;
		}

		private async Task<List<User>> LoadDataAsync()
		{
			await Task.Delay(2000);
			List<User> users = (List<User>)Lab_8.DB.DB.GetAllUsers();

			return users;
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			List<User> users = (List<User>)Lab_8.DB.DB.GetAllUsers();

			productDataGrid.ItemsSource = users;
		}

		private void Button_Click_1(object sender, RoutedEventArgs e)
		{
			AddUser userWindow = new AddUser();
			userWindow.Show();
		}
		private void Button_Image(object sender, RoutedEventArgs e)
		{
			AddUser userWindow = new AddUser();
			userWindow.Show();
		}

		private void Button_Click_2(object sender, RoutedEventArgs e)
		{
			List<User> users = (List<User>)Lab_8.DB.DB.GetAllUsers();

			productDataGrid.ItemsSource = users;
		}

		private void Button_Click_3(object sender, RoutedEventArgs e)
		{
			var myValue = ((Button)sender).Tag;
			List<User> result = (List<User>)DB.DB.Sort((string)myValue);

			productDataGrid.ItemsSource = result;
		}
	}
}