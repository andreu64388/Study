using Lab_9.Class;
using Microsoft.Win32;
using System;
using System.IO;
using System.Windows;
using System.Windows.Media.Imaging;

namespace Lab_9.WIndows
{
	/// <summary>
	/// Логика взаимодействия для AddUser.xaml
	/// </summary>
	public partial class AddUser : Window
	{
		public AddUser()
		{
			InitializeComponent();
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

				byte[] imageData = null;
				if (preview.Source != null)
				{
					BitmapImage bitmapImage = (BitmapImage)preview.Source;
					using (MemoryStream stream = new MemoryStream())
					{
						PngBitmapEncoder encoder = new PngBitmapEncoder();
						encoder.Frames.Add(BitmapFrame.Create(bitmapImage));
						encoder.Save(stream);
						imageData = stream.ToArray();
					}
				}
				User user = new User()
				{
					FirstName = firstname,
					LastName = lastname,
					Address = address,
					Phone = phone,
					Email = email,
					Image = imageData,
				};

				try
				{
					using (Lab_9.DB.DB context = new Lab_9.DB.DB())
					{
						context.Users.Add(user);
						context.SaveChanges();
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

		private void Button_Image(object sender, RoutedEventArgs e)
		{
			OpenFileDialog openFileDialog = new OpenFileDialog();
			openFileDialog.Filter = "Image|*.jpg;*.jpeg;*.png;";
			if (openFileDialog.ShowDialog() == true)
			{
				try
				{
					preview.Source = new BitmapImage(new Uri(openFileDialog.FileName, UriKind.Absolute));
					preview.Width = 100;
					preview.Height = 100;
				}
				catch
				{
					MessageBox.Show("Выберите файл подходящего формата.", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
				}
			}
		}
	}
}