using System.Windows.Controls;

namespace Lab_4_5.UserControls
{
	/// <summary>
	/// Логика взаимодействия для MyButton.xaml
	/// </summary>
	public partial class MyButton : UserControl
	{
		public string Button { get; set; } = "Нажми меня!";

		public MyButton()
		{
			InitializeComponent();
		}
	}
}