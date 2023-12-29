﻿
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

			App.LanguageChanged += languageChanged;
			CultureInfo currLang = App.Language;
			isToggle = GetState();
			toggle.IsChecked = isToggle;
		


			DataContext = new BooleanToHorizontalAlignmentConverter();

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
	
			


		
	}
	
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

