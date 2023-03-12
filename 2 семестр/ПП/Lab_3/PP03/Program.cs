using Lec03LibN;


class Program
{
	private static void Main()
	{
		// Создаем фабрики для каждого уровня вознаграждения
		IFactory level1Factory = Lec03Blib.GetL1();
		IFactory level2Factory = Lec03Blib.GetL2(2.0f);
		IFactory level3Factory = Lec03Blib.GetL3(1.5f, 10.0f);

		// Создаем сотрудников с разными уровнями вознаграждения
		Employee employee1 = new Employee(level1Factory.GetA(10.0f));
		Employee employee2 = new Employee(level2Factory.GetB(20.0f, 3.0f));
		Employee employee3 = new Employee(level3Factory.GetC(15.0f, 5.0f, 50.0f));

		// Вычисляем вознаграждение для каждого сотрудника
		float bonus1 = employee1.CalculateBonus(8.0f);
		float bonus2 = employee2.CalculateBonus(6.0f);
		float bonus3 = employee3.CalculateBonus(7.0f);

		// Выводим результаты в консоль
		Console.WriteLine($"Employee 1 bonus: {bonus1}");
		Console.WriteLine($"Employee 2 bonus: {bonus2}");
		Console.WriteLine($"Employee 3 bonus: {bonus3}");
	}
}