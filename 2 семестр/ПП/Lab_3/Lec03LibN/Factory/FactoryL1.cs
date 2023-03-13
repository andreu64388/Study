using Lec03LibN.Bonus;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lec03LibN.Factory
{
    public class FactoryL1 : IFactory
	{
		public IBonus getA(float cost1hour)
		{
			return new BonusA(cost1hour);
		}

		public IBonus getB(float cost1hour, float x)
		{
			return new BonusB(cost1hour, x);
		}

		public IBonus getC(float cost1hour, float x, float y)
		{
			return new BonusC(cost1hour, x, y);
		}
	


	}
}
