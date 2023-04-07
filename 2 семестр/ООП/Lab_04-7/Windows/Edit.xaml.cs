using Lab_4_5.Class;
using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
<<<<<<< HEAD
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
=======
using System.Windows;
using System.Windows.Media.Imaging;
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced

namespace Lab_4_5.Windows
{
	/// <summary>
	/// Логика взаимодействия для Edit.xaml
	/// </summary>
	public partial class Edit : Window
	{
		private OpenFileDialog openFileDialog;
		public ObservableCollection<Category> MyCollections { get; set; }
		public ObservableCollection<Product> Products { get; set; }

		private string ID { get; set; }
<<<<<<< HEAD
=======

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		private Dictionary<string, Class.Category> dictCategories = new Dictionary<string, Class.Category>()
		{
			{ "Toys", Class.Category.Toys },
			{ "Clothes", Class.Category.Clothes },
			{ "Phone", Class.Category.Phone }
		};
<<<<<<< HEAD
=======

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		public Edit(Product product)
		{
			InitializeComponent();

<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
			Name_product.Text = product.Name;
			Description_product.Text = product.Description;
			Price_product.Text = product.Price.ToString();
			Rating_product.Text = product.Rating.ToString();
			preview.Source = new BitmapImage(new Uri(product.Img));
			product.Category = dictCategories[product.Category.ToString()];
			ID = product.Id;
			MyCollections = new ObservableCollection<Category>();
			MyCollections.Add(new Category() { Name = "Toys" });
			MyCollections.Add(new Category() { Name = "Clothes" });
			MyCollections.Add(new Category() { Name = "Phone" });

			DataContext = this;
<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			openFileDialog = new OpenFileDialog();
			openFileDialog.Filter = "Image|*.jpg;*.jpeg;*.png;";
			if (openFileDialog.ShowDialog() == true)
			{
				try
				{
					preview.Source = new BitmapImage(new Uri(openFileDialog.FileName, UriKind.Absolute));
<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
				}
				catch
				{
					MessageBox.Show("Выберите файл подходящего формата.", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
				}
			}
		}

		private void Button_Click_1(object sender, RoutedEventArgs e)
		{
			Name_product.Text = "";
			Description_product.Text = "";
			Price_product.Text = "";
			Rating_product.Text = "";
			preview.Source = null;
<<<<<<< HEAD


=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		}

		private void Button_Click_2(object sender, RoutedEventArgs e)
		{
			try
			{
				string name = Name_product.Text;
				string description = Description_product.Text;

				float price = (float)Convert.ToDecimal(Price_product.Text);

				int raiting = Convert.ToInt32(Rating_product.Text);

				string img = preview.Source.ToString();

<<<<<<< HEAD

				if (name.Length == 0)
				{
					throw new Exception("Введите имя");

=======
				if (name.Length == 0)
				{
					throw new Exception("Введите имя");
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
				}
				else if (description.Length == 0)
				{
					throw new Exception("Введите описание");
<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
				}
				else if (raiting == 0 || raiting > 10)
				{
					throw new Exception("Введите диапазон значений от 1 до 10");
				}
<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
				else if (img == null)
				{
					throw new Exception("Загрузите фотографию");
				}
				else
				{
					Products = Class.DataFile.JsonDeseriazeProducts();

					foreach (Product p in Products)
					{
<<<<<<< HEAD
						if(ID==p.Id)
						{
							p.Name= name;
							p.Description= description;
							p.Price= price;
							p.Rating = raiting;
							p.Category=dictCategories[Category_product.Text];
							p.Img = img;

						}

=======
						if (ID == p.Id)
						{
							p.Name = name;
							p.Description = description;
							p.Price = price;
							p.Rating = raiting;
							p.Category = dictCategories[Category_product.Text];
							p.Img = img;
						}
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
					}

					Class.DataFile.JsonSerializeProductsCollection(Products);

					MessageBox.Show("Данные были изменены");

<<<<<<< HEAD

					this.Close();

				}


=======
					this.Close();
				}
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
<<<<<<< HEAD

			}

		}
	}
	
}
=======
			}
		}
	}
}
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
