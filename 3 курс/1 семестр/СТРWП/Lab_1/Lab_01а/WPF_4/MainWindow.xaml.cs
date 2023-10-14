using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Http;
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

namespace Client_4
{
	/// <summary>
	/// Логика взаимодействия для MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			InitializeComponent();
		}

		private async void Button_Click(object sender, RoutedEventArgs e)
		{
			result.Content = "";
			if (int.TryParse(X.Text, out int x) && int.TryParse(Y.Text, out int y))
			{
				try
				{
					int sum = await GetSum(x, y);
					result.Content = $"X + Y = {sum}";
				}
				catch (Exception ex)
				{
					result.Content = $"Ошибка: {ex.Message}";
				}
			}
			else
			{
				result.Content = "Пожалуйста, введите корректные числа.";
			}
		}

		private async Task<int> GetSum(int x, int y)
		{
			int sum;

			string url = $"https://localhost:44370/KAVS?ParmX={x}&ParmY={y}";

			using (HttpClient client = new HttpClient())
			{
				HttpResponseMessage response = await client.PostAsync(url, null);
				response.EnsureSuccessStatusCode();

				string responseText = await response.Content.ReadAsStringAsync();
				sum = int.Parse(responseText);
			}

			return sum;
		}
	}
}

