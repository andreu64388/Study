using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace Lab_4_5.Class
{
	public class NumericTextBox : TextBox
	{
		public static readonly DependencyProperty ValueProperty =
			DependencyProperty.Register("Value", typeof(int), typeof(NumericTextBox),
			new FrameworkPropertyMetadata(default(int), FrameworkPropertyMetadataOptions.BindsTwoWayByDefault, OnValueChanged, CoerceValue));

		public int Value
		{
			get { return (int)GetValue(ValueProperty); }
			set { SetValue(ValueProperty, value); }
		}

		private static void OnValueChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			NumericTextBox textBox = (NumericTextBox)d;
			textBox.Text = e.NewValue.ToString();
		}

		private static object CoerceValue(DependencyObject d, object value)
		{
			NumericTextBox textBox = (NumericTextBox)d;
			if (value == null)
				return textBox.Value;

			if (int.TryParse(value.ToString(), out int result))
				return result;
			else
				return textBox.Value;
		}

		protected override void OnPreviewTextInput(TextCompositionEventArgs e)
		{
			int result;
			bool isNumeric = int.TryParse(e.Text, out result);
			e.Handled = !isNumeric;
			base.OnPreviewTextInput(e);
		}
	}
}