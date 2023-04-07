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
	/// Логика взаимодействия для AddProduct.xaml
	/// </summary>
<<<<<<< HEAD
	/// 
=======
	///
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
	public partial class AddProduct : Window
	{
		private OpenFileDialog openFileDialog;
		public ObservableCollection<Category> MyCollections { get; set; }

		public Dictionary<string, Class.Category> dictCategories = new Dictionary<string, Class.Category>()
		{
			{ "Toys", Class.Category.Toys },
			{ "Clothes", Class.Category.Clothes },
			{ "Phone", Class.Category.Phone }
		};
<<<<<<< HEAD
=======

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		public AddProduct()
		{
			InitializeComponent();

<<<<<<< HEAD
			MyCollections= new ObservableCollection<Category>();
			MyCollections.Add(new Category() {Name = "Toys" });
			MyCollections.Add(new Category() { Name = "Clothes" });
			MyCollections.Add(new Category() { Name = "Phone" });
			
			DataContext = this;

=======
			MyCollections = new ObservableCollection<Category>();
			MyCollections.Add(new Category() { Name = "Toys" });
			MyCollections.Add(new Category() { Name = "Clothes" });
			MyCollections.Add(new Category() { Name = "Phone" });

			DataContext = this;
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
				

				if(name.Length== 0)
				{
					throw new Exception("Введите имя");

				}
				else if(description.Length== 0) 
				{
					throw new Exception("Введите описание");

				}
				else  if ( raiting ==0 || raiting>10)
				{
					throw new Exception("Введите диапазон значений от 1 до 10");
				}

				else if(img ==null)
=======

				if (name.Length == 0)
				{
					throw new Exception("Введите имя");
				}
				else if (description.Length == 0)
				{
					throw new Exception("Введите описание");
				}
				else if (raiting == 0 || raiting > 10)
				{
					throw new Exception("Введите диапазон значений от 1 до 10");
				}
				else if (img == null)
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
				{
					throw new Exception("Загрузите фотографию");
				}
				else
				{
					Product product = new Product();
					product.Name = name;
					product.Description = description;
					product.Price = price;
					product.Img = img;
					product.Rating = raiting;
					product.Count = 1;
					product.Category = dictCategories[Category_product.Text];

					DataFile.JsonSerializeProducts(product);

					MessageBox.Show(product.ToString());

					this.Close();
				}
<<<<<<< HEAD


			}
			catch(Exception ex)
			{
				MessageBox.Show(ex.Message);

			}

		}
	}
=======
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
		}

		private void Button_image()
		{

		}
	}

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
	public class Category

	{
		public string Name { get; set; }
<<<<<<< HEAD

	}

}
=======
	}
}
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
