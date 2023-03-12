// Интерфейс для вычисления вознаграждения
namespace Lec03LibN
{

	public interface IBonus
	{
		float Cost1Hour { get; set; } // Стоимость одного часа

		float Calc(float numberHours); // Вычисление вознаграждения
	}

	// Реализация вознаграждения типа A
	public class BonusA : IBonus
	{
		public float Cost1Hour { get; set; }

		public BonusA(float cost1Hour)
		{
			Cost1Hour = cost1Hour;
		}

		public float Calc(float numberHours)
		{
			return numberHours * Cost1Hour * 1;
		}
	}

	// Реализация вознаграждения типа B
	public class BonusB : IBonus
	{
		public float Cost1Hour { get; set; }
		public float X { get; set; }

		public BonusB(float cost1Hour, float x)
		{
			Cost1Hour = cost1Hour;
			X = x;
		}

		public float Calc(float numberHours)
		{
			return (numberHours * Cost1Hour * X) + (numberHours * 1);
		}
	}

	// Реализация вознаграждения типа C
	public class BonusC : IBonus
	{
		public float Cost1Hour { get; set; }
		public float X { get; set; }
		public float Y { get; set; }

		public BonusC(float cost1Hour, float x, float y)
		{
			Cost1Hour = cost1Hour;
			X = x;
			Y = y;
		}

		public float Calc(float numberHours)
		{
			return (numberHours * Cost1Hour * X) + Y;
		}
	}

	// Интерфейс абстрактной фабрики
	public interface IFactory
	{
		IBonus GetA(float cost1Hour); // Метод создания экземпляра вознаграждения типа A

		IBonus GetB(float cost1Hour, float x); // Повышающий / понижающий

		IBonus GetC(float c, float x, float y); // Повышающий / понижающий, величина снижения / повышения
	}

	// Фабрика уровня 1
	public class FactoryL1 : IFactory
	{
		public IBonus GetA(float cost1Hour)
		{
			return new BonusA(cost1Hour);
		}

		public IBonus GetB(float cost1Hour, float x)
		{
			return new BonusB(cost1Hour, x);
		}

		public IBonus GetC(float c, float x, float y)
		{
			return new BonusC(c, x, y);
		}
	}

	// Фабрика уровня 2
	public class FactoryL2 : IFactory
	{
		private float _a;

		public FactoryL2(float a)
		{
			_a = a;
		}

		public IBonus GetA(float cost1Hour)
		{
			return new BonusA(cost1Hour);
		}

		public IBonus GetB(float cost1Hour, float x)
		{
			float newX = x + _a;
			return new BonusB(cost1Hour, newX);
		}

		public IBonus GetC(float c, float x, float y)
		{
			float newY = y - _a;
			return new BonusC(c, x, newY);
		}
	}

	// Фабрика уровня 3
	public class FactoryL3 : IFactory
	{
		private float _a;
		private float _b;

		public FactoryL3(float a, float b)
		{
			_a = a;
			_b = b;
		}

		public IBonus GetA(float cost1Hour)
		{
			float newCost1Hour = cost1Hour + _b;
			return new BonusA(newCost1Hour);
		}

		public IBonus GetB(float cost1Hour, float x)
		{
			float newX = x + _a;
			float newCost1Hour = cost1Hour + _b;
			return new BonusB(newCost1Hour, newX);
		}

		public IBonus GetC(float c, float x, float y)
		{
			float newY = y - _a;
			float newCost1Hour = c + _b;
			return new BonusC(newCost1Hour, x, newY);
		}
	}

	public class Employee
	{
		public IBonus Bonus { get; private set; }

		public Employee(IBonus bonus)
		{
			Bonus = bonus;
		}

		public float CalculateBonus(float numberHours)
		{
			return Bonus.Calc(numberHours);
		}
	}

	// Уровни вознаграждения
	// Реализация методов фабрик уровней вознаграждения
	public static partial class Lec03Blib
	{
		// Фабрика уровня 1
		public static IFactory GetL1()
		{
			return new FactoryL1();
		}

		// Фабрика уровня 2
		public static IFactory GetL2(float a)
		{
			return new FactoryL2(a);
		}

		// Фабрика уровня 3
		public static IFactory GetL3(float a, float b)
		{
			return new FactoryL3(a, b);
		}
	}

}