using System;
using System.Collections.Generic;
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
