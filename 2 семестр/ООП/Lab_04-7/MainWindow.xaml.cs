
using Lab_4_5.Windows;
using System;
using System.Globalization;
using System.IO;
using System.Windows;
using System.Windows.Data;

namespace Lab_4_5
{
	/// <summary>
	/// Логика взаимодействия для MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{

		private string path = "state.txt";
		private bool isToggle { get; set; }
		public MainWindow()
		{
			InitializeComponent();

<<<<<<< HEAD
			App.LanguageChanged += languageChanged;
			CultureInfo currLang = App.Language;
=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
			isToggle = GetState();
			toggle.IsChecked = isToggle;
		


			DataContext = new BooleanToHorizontalAlignmentConverter();

		}

<<<<<<< HEAD
		private void languageChanged(Object sender, EventArgs e)
		{
			CultureInfo currLang = App.Language;
		}
=======

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced

		private void Button_ClickRus(object sender, RoutedEventArgs e)
		{

<<<<<<< HEAD
			CultureInfo lang = new CultureInfo("ru-RU");
			App.Language = lang;
=======
			var uri = new Uri("Diactionary/Rus.xaml", UriKind.Relative);
			ResourceDictionary resourceDict = Application.LoadComponent(uri) as ResourceDictionary;
			Application.Current.Resources.Clear();
			Application.Current.Resources.MergedDictionaries.Add(resourceDict);
			
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced

		}
		private void Button_ClickEng(object sender, RoutedEventArgs e)
		{
<<<<<<< HEAD
			CultureInfo lang = new CultureInfo("en-US");
			App.Language = lang;

=======

			var uri = new Uri("Diactionary/Eng.xaml", UriKind.Relative);
			ResourceDictionary resourceDict = Application.LoadComponent(uri) as ResourceDictionary;
			Application.Current.Resources.Clear();
			Application.Current.Resources.MergedDictionaries.Add(resourceDict);
	
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		}
		private void Button_Click(object sender, RoutedEventArgs e)
		{
			AddProduct addProduct = new AddProduct();
			addProduct.Show();
			

		}
		private void ToggleButton_Checked(object sender, RoutedEventArgs e)
		{

			isToggle = true;
			var uri = new Uri("DarkTheme.xaml", UriKind.Relative);
			ResourceDictionary resourceDict = Application.LoadComponent(uri) as ResourceDictionary;
			Application.Current.Resources.Clear();
			Application.Current.Resources.MergedDictionaries.Add(resourceDict);
			SaveState(isToggle);
		}

		private void ToggleButton_Unchecked(object sender, RoutedEventArgs e)
		{

			isToggle = false;
			var uri = new Uri("WhiteTheme.xaml", UriKind.Relative);
			ResourceDictionary resourceDict = Application.LoadComponent(uri) as ResourceDictionary;
			Application.Current.Resources.Clear();
			Application.Current.Resources.MergedDictionaries.Add(resourceDict);
			SaveState(isToggle);
		}
		private bool GetState()
		{
			using (StreamReader sr = new StreamReader(path))
			{
				string line = sr.ReadLine();

				if (line.Trim() == "True")
				{
					return true;
				}
				else
				{
					return false;
				}

			}
		}



		private void Button_Click_1(object sender, RoutedEventArgs e)
		{

			AllProducts allProducts = new AllProducts();
			allProducts.Show();
			this.Close();
		}
		private void SaveState(bool state)
		{
			using (StreamWriter sw = new StreamWriter(path))
			{
				sw.WriteLine(state);
			}

		}
<<<<<<< HEAD
	
			


		
	}
	
=======

		private void Button_Click_2(object sender, RoutedEventArgs e)
		{
			Evemt evemt = new Evemt();
			evemt.Show();
			this.Close();
		}

		private void SearchButton_Loaded(object sender, RoutedEventArgs e)
		{

		}
	}

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
	public class BooleanToHorizontalAlignmentConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if ((bool)value)
			{
				return HorizontalAlignment.Right;
			}
			else
			{
				return HorizontalAlignment.Left;
			}
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
}


