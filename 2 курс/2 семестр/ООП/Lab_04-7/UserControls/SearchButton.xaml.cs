using System.Windows;
using System.Windows.Controls;

namespace Lab_4_5.UserControls
{
	/// <summary>
	/// Логика взаимодействия для SearchButton.xaml
	/// </summary>
	public partial class SearchButton : UserControl
	{
		public SearchButton()
		{
			InitializeComponent();
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			text.Text = "";
		}

		private void text_TextChanged(object sender, TextChangedEventArgs e)
		{
		}
	}
}