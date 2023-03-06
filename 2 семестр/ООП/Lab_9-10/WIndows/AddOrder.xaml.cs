using Lab_9.Class;
using System;
using System.Windows;

namespace Lab_9.WIndows
{
	/// <summary>
	/// Логика взаимодействия для AddOrder.xaml
	/// </summary>
	public partial class AddOrder : Window
	{
		private int Id { get; set; }

		public AddOrder(int id)
		{
			InitializeComponent();

			Id = id;
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			string name = val.Text;
			if (name.Trim().Length > 0)
			{
				try
				{
					using (var context = new DB.DB())
					{
						MessageBox.Show(Id.ToString());
						var user = context.GetUserById(Id);
						Orders orders = new Orders()
						{
							Name = name,
							User = user
						};

						context.Orders.Add(orders);
						context.SaveChanges();
					}
				}
				catch (Exception ex)
				{
					MessageBox.Show(ex.Message);
				}
				finally
				{
					this.Close();
				}
			}
		}
	}
}