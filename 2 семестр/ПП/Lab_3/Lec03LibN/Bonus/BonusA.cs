using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lec03LibN.Bonus
{
    public class BonusA : IBonus
	{
		public float cost1hour { get; set; }
		public float A { get; set; }

		public float calc(float number_hours)
		{
			return (number_hours + A) * cost1hour;
		}
		public BonusA(float cost1hour, float a = 0.0f)
		{
			this.cost1hour = cost1hour;
			A = a;
		}
	}
}
