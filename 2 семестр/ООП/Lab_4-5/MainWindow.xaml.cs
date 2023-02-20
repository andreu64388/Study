
using Lab_4_5.Windows;
using System;
using System.Collections.Generic;
using System.Globalization;
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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Lab_4_5
{
	/// <summary>
	/// Логика взаимодействия для MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			InitializeComponent();
			
			App.LanguageChanged += languageChanged;
			CultureInfo currLang = App.Language;
		}
		private void languageChanged(Object sender, EventArgs e)
		{
			CultureInfo currLang = App.Language;
		}

		private void Button_ClickRus(object sender, RoutedEventArgs e)
		{

			CultureInfo lang = new CultureInfo("ru-RU");
			App.Language = lang;
			
		}
		private void Button_ClickEng(object sender, RoutedEventArgs e)
		{
			CultureInfo lang = new CultureInfo("en-US");
			App.Language = lang;

		}
		private void Button_Click(object sender, RoutedEventArgs e)
		{
			AddProduct addProduct = new AddProduct();
			addProduct.Show();

        }

		private void Button_Click_1(object sender, RoutedEventArgs e)
		{

			AllProducts allProducts = new AllProducts();
			allProducts.Show();
			this.Close();
		}
	}
}
