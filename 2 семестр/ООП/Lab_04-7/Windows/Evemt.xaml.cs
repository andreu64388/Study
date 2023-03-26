using Microsoft.Win32;
using System.Windows;
using System.Windows.Input;

namespace Lab_4_5.Windows
{
	/// <summary>
	/// Логика взаимодействия для Evemt.xaml
	/// </summary>
	public partial class Evemt : Window
	{
		public Evemt()
		{
			InitializeComponent();

			WindowState = WindowState.Maximized;
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			this.Close();
		}

		private void Button_Click_1(object sender, RoutedEventArgs e)
		{
			MainWindow main = new MainWindow();
			main.Show();
			this.Close();
		}

		private void WindowHeader_MouseDown(object sender, MouseButtonEventArgs e)
		{
			if (e.ChangedButton == MouseButton.Left)
			{
				DragMove();
			}
		}

		private void Button_Click_2(object sender, RoutedEventArgs e)
		{
			if (WindowState == WindowState.Normal)
			{
				WindowState = WindowState.Maximized;
			}
			else
			{
				WindowState = WindowState.Normal;
			}
		}

		// Direct Routing (Прямая маршрутизация)
		private void btnDirect_Click(object sender, RoutedEventArgs e)
		{
			MessageBox.Show("Button Direct Clicked!" + e.Source.ToString() + "\n" + sender.ToString());
		}

		private void btnStackDirect_Click(object sender, RoutedEventArgs e)
		{
			MessageBox.Show("Button Direct Clicked!" + e.Source.ToString() + "\n" + sender.ToString());
		}

		private void btnBubble_Click(object sender, RoutedEventArgs e)
		{
			MessageBox.Show("Button Direct Clicked!" + e.Source.ToString() + "\n" + sender.ToString());
		}

		private void btnStackBubble_Click(object sender, RoutedEventArgs e)
		{
			MessageBox.Show("Button Direct Clicked!" + e.Source.ToString() + "\n" + sender.ToString());
		}

		private void btnTunnel_Click(object sender, RoutedEventArgs e)
		{
			MessageBox.Show("Button Direct Clicked!" + e.Source.ToString() + "\n" + sender.ToString());
		}

		private void btnStackTunnel_Click(object sender, RoutedEventArgs e)
		{
		}

		// Tunneling Routing (Туннельная маршрутизация)

		private void OpenFileExecuted(object sender, ExecutedRoutedEventArgs e)
		{
			MessageBox.Show("Open file command executed!");
			OpenFileDialog openFileDialog = new OpenFileDialog();
			if (openFileDialog.ShowDialog() == true)
			{
				// обработка открытого файла
			}
		}
	}
}