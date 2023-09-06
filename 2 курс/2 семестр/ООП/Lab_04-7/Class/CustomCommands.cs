using System.Windows.Input;

namespace Lab_4_5.Class
{
	public static class CustomCommands
	{
		public static RoutedUICommand OpenFile = new RoutedUICommand(
			"Open",
			"OpenFile",
			typeof(CustomCommands),
			new InputGestureCollection() { new KeyGesture(Key.O, ModifierKeys.Control) }
		);
	}
}