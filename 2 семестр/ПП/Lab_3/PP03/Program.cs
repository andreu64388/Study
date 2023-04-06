using Lec03LibN;
using PP03;

class Program
{
	private static void Main()
	{
	
		IFactory l1 = Lec03BLib.getL1();

		Employee employee1 = new(l1.getA(25));
		Console.WriteLine($"Bonus-L1-A = {employee1.calcBonus(4)}");

		Employee employee2 = new(l1.getB(25, 1.1f));
		Console.WriteLine($"Bonus-L1-B = {employee2.calcBonus(4)}");

		Employee employee3 = new(l1.getC(25, 1.1f, 5.0f));
		Console.WriteLine($"Bonus-L1-C = {employee3.calcBonus(4)}");

		IFactory l2 = Lec03BLib.getL2(1);

		Employee employee4 = new(l2.getA(25));
		Console.WriteLine($"Bonus-L1-A = {employee4.calcBonus(4)}");

		Employee employee5 = new(l2.getB(25, 1.1f));
		Console.WriteLine($"Bonus-L1-B = {employee5.calcBonus(4)}");

		Employee employee6 = new(l2.getC(25, 1.1f, 5.0f));
		Console.WriteLine($"Bonus-L1-C = {employee6.calcBonus(4)}");

		IFactory l3 = Lec03BLib.getL3(1, 0.5f);

		Employee employee7 = new(l3.getA(25));
		Console.WriteLine($"Bonus-L3-A = {employee7.calcBonus(4)}");

		Employee employee8 = new(l3.getB(25, 1.1f));
		Console.WriteLine($"Bonus-L3-B = {employee8.calcBonus(4)}");

		Employee employee9 = new(l3.getC(25, 1.1f, 0.5f));
		Console.WriteLine($"Bonus-L3-C = {employee9.calcBonus(4)}");
	}
}