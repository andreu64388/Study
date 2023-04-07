using Lab_4_5.Class;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Windows;
using System.Windows.Controls;

namespace Lab_4_5.Windows
{
	/// <summary>
	/// Логика взаимодействия для AllProducts.xaml
	/// </summary>
	public partial class AllProducts : Window
	{
		private Dictionary<string, Class.Category> dictCategories = new Dictionary<string, Class.Category>()
		{
			{ "Toys", Class.Category.Toys },
			{ "0", Class.Category.Toys },
			{ "Clothes", Class.Category.Clothes },
			{ "1", Class.Category.Clothes },
			{ "Phone", Class.Category.Phone },
			{ "2", Class.Category.Phone },
		};

		public static ObservableCollection<Product> StateOld { get; set; }
		public bool isSort { get; set; }
		public static ObservableCollection<Product> Products { get; set; }
		public ObservableCollection<Category> MyCollections { get; set; }
<<<<<<< HEAD
		public AllProducts()
		{


=======

		public AllProducts()
		{
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
			InitializeComponent();
			MyCollections = new ObservableCollection<Category>();
			MyCollections.Add(new Category() { Name = "Toys" });
			MyCollections.Add(new Category() { Name = "Clothes" });
			MyCollections.Add(new Category() { Name = "Phone" });
<<<<<<< HEAD
			
			Products = Class.DataFile.JsonDeseriazeProducts();
			StateOld = Products;
			DataContext = this;

=======

			Products = Class.DataFile.JsonDeseriazeProducts();
			StateOld = Products;
			DataContext = this;
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
<<<<<<< HEAD

			MainWindow mainWindow = new MainWindow();
			mainWindow.Show();
			this.Close();

=======
			MainWindow mainWindow = new MainWindow();
			mainWindow.Show();
			this.Close();
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		}

		private void Button_Click_1(object sender, RoutedEventArgs e)
		{
			AddProduct addProduct = new AddProduct();
			addProduct.Closing += Edit_Closing;
			addProduct.Show();
<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		}

		private void Button_Click_2(object sender, RoutedEventArgs e)
		{
			if (Choise.SelectedItem == null)
			{
				MessageBox.Show("Выберете продукт");
			}
			else
			{
				Products.Remove((Product)Choise.SelectedItem);
				DataFile.JsonSerializeProductsCollection(Products);
				MessageBox.Show("Продукт удален", "Успешно!", MessageBoxButton.OK);
			}
<<<<<<< HEAD



=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		}

		private void Button_Click_3(object sender, RoutedEventArgs e)
		{
			if (Choise.SelectedItem == null)
			{
				MessageBox.Show("Выберете продукт");
			}
			else
			{
				Product product = (Product)Choise.SelectedItem;
				Edit edit = new Edit(product);
				edit.Closing += Edit_Closing;
				edit.Show();
			}
		}

		private void Edit_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
<<<<<<< HEAD
	
			Products = Class.DataFile.JsonDeseriazeProducts();
			Choise.ItemsSource= Products;

		}


		private void Button_Click_4(object sender, RoutedEventArgs e)
		{

=======
			Products = Class.DataFile.JsonDeseriazeProducts();
			Choise.ItemsSource = Products;
		}

		private void Button_Click_4(object sender, RoutedEventArgs e)
		{
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
			Raiting.Content = "По рейтингу";
			Name.Content = "По имени";
			if (isSort)
			{
<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
				Price.Content = "По цене ↑";
				isSort = false;
				Choise.ItemsSource = Products.OrderBy(x => x.Price).ToList();
				StateOld = Products;
<<<<<<< HEAD

			}
			else
			{

=======
			}
			else
			{
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
				Price.Content = "По цене ↓";
				isSort = true;

				Choise.ItemsSource = Products.OrderByDescending(x => x.Price).ToList();
				StateOld = Products;
<<<<<<< HEAD

			}



=======
			}
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		}

		private void Button_Click_5(object sender, RoutedEventArgs e)
		{
<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
			Raiting.Content = "По рейтингу";
			Price.Content = "По цене";
			if (isSort)
			{
<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
				Name.Content = "По имени ↑";
				isSort = false;
				Choise.ItemsSource = Products.OrderBy(x => x.Name).ToList();
				StateOld = Products;
			}
			else
			{
<<<<<<< HEAD

				Name.Content = "По имени ↓";
				isSort = true;
				Choise.ItemsSource = Products.OrderByDescending(x => x.Name).ToList();
				StateOld = Products;	

=======
				Name.Content = "По имени ↓";
				isSort = true;
				Choise.ItemsSource = Products.OrderByDescending(x => x.Name).ToList();
				StateOld = Products;
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
			}
		}

		private void Category_product_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (Category_product.SelectedItem != null)
			{
<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
				string selectedItem = Category_product.SelectedIndex.ToString();
				Raiting.Content = "По рейтингу";
				Price.Content = "По цене";
				Name.Content = "По имени";
				var type = dictCategories[selectedItem];
				Choise.ItemsSource = Products.Where(x => x.Category == type);
				StateOld = Products;
<<<<<<< HEAD


			}
		}



=======
			}
		}

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		private void Button_Click_6(object sender, RoutedEventArgs e)
		{
			Price.Content = "По цене";
			Name.Content = "По имени";
			if (isSort)
			{
<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
				Raiting.Content = "По рейтингу ↑";
				isSort = false;
				Choise.ItemsSource = Products.OrderBy(x => x.Rating).ToList();
				StateOld = Products;
			}
			else
			{
<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
				Raiting.Content = "По рейтингу ↓";
				isSort = true;
				Choise.ItemsSource = Products.OrderByDescending(x => x.Rating).ToList();
				StateOld = Products;
<<<<<<< HEAD

			}

=======
			}
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		}

		private void SearchTextBox_TextChanged(object sender, TextChangedEventArgs e)
		{
			ObservableCollection<Product> testProduct = new ObservableCollection<Product>();
			string searchText = SearchTextBox.Text;

			foreach (Product el in Products)
			{
<<<<<<< HEAD

				if (el.Name.ToLower() == searchText.ToLower())
				{
					testProduct.Add(el);

=======
				if (el.Name.ToLower() == searchText.ToLower())
				{
					testProduct.Add(el);
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
				}
				else if (el.Name.ToLower().Contains(searchText.ToLower()))
				{
					testProduct.Add(el);
				}
<<<<<<< HEAD

			}
			Choise.ItemsSource = testProduct;


		}
		private void Button_Click_7(object sender, RoutedEventArgs e)
		{

=======
			}
			Choise.ItemsSource = testProduct;
		}

		private void Button_Click_7(object sender, RoutedEventArgs e)
		{
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
			Category_product.Text = "";
			Raiting.Content = "По рейтингу";
			Price.Content = "По цене";
			Name.Content = "По имени";
			Choise.ItemsSource = Products;
			SearchTextBox.Text = "";
<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		}

		private void Button_Click_8(object sender, RoutedEventArgs e)
		{
			Choise.ItemsSource = StateOld;
<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		}

		private void Button_Click_9(object sender, RoutedEventArgs e)
		{
			Products = Class.DataFile.JsonDeseriazeProducts();
			Choise.ItemsSource = Products;
		}
	}
<<<<<<< HEAD

}
=======
}
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
