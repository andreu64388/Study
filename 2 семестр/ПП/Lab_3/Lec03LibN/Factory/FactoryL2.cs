using Lec03LibN.Bonus;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lec03LibN.Factory
{
    // Фабрика уровня 2
    public class FactoryL2 : IFactory
	{
		public float A { get; set; }
		public IBonus getA(float cost1hour)
		{
			return new BonusA(cost1hour, A);
		}

		public IBonus getB(float cost1hour, float x)
		{
			return new BonusB(cost1hour, x, A);
		}

		public IBonus getC(float cost1hour, float x, float y)
		{
			return new BonusC(cost1hour, x, y, A);
		}
		public FactoryL2(float a)
		{
			A = a;
		}
	}
}
