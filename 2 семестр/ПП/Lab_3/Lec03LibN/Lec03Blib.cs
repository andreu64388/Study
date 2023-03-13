// Интерфейс для вычисления вознаграждения
using Lec03LibN.Factory;

namespace Lec03LibN
{



	// Уровни вознаграждения
	// Реализация методов фабрик уровней вознаграждения
	static public partial class Lec03BLib
	{
		static public IFactory getL1()
		{
			return new FactoryL1();
		}
		static public IFactory getL2(float a)
		{
			return new FactoryL2(a);
		}
		static public IFactory getL3(float a, float b)
		{
			return new FactoryL3(a, b);
		}
	}

}