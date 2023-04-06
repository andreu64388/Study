using Lec03LibN.Bonus;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lec03LibN.Factory
{
    public class FactoryL3 : IFactory
	{
		public float A { get; set; }
		public float B { get; set; }

		public IBonus getA(float cost1hour)
		{
			return new BonusA(cost1hour + B, A);
		}

		public IBonus getB(float cost1hour, float x)
		{
			return new BonusB(cost1hour + B, x, A);
		}

		public IBonus getC(float cost1hour, float x, float y)
		{
			return new BonusC(cost1hour + B, x, y, A);
		}
		public FactoryL3(float a, float b)
		{
			A = a;
			B = b;
		}

	}

}
