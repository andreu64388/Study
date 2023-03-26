using Lab_4_5.Class;
using System.Windows;
using System.Windows.Controls;

namespace Lab_4_5.UserControls
{
	/// <summary>
	/// Логика взаимодействия для Input.xaml
	/// </summary>
	public partial class Input : UserControl
	{
		public Input()
		{
			InitializeComponent();
		}

		public static readonly DependencyProperty ValueProperty =
			DependencyProperty.Register(
				"Value",
				typeof(int),
				typeof(Input),
				new FrameworkPropertyMetadata(
					0,
					FrameworkPropertyMetadataOptions.BindsTwoWayByDefault,
					ValuePropertyChanged,
					ValueCoerce));

		public int Value
		{
			get { return (int)GetValue(ValueProperty); }
			set { SetValue(ValueProperty, value); }
		}

		private static void ValuePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			// Handle property changed event
		}

		private static object ValueCoerce(DependencyObject d, object baseValue)
		{
			// Handle property coercion
			return baseValue;
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			NumericTextBox numericText = new NumericTextBox();

			MessageBox.Show(numericText.Name.ToString());
		}
	}
}