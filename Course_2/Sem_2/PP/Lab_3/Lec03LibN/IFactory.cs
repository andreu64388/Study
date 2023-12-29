using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lec03LibN
{
    public interface IFactory
    {

		IBonus getA(float cost1hour);// Метод создания экземпляра вознаграждения типа A
		IBonus getB(float cost1hour, float x);// Повышающий / понижающий
		IBonus getC(float cost1hour, float x, float y);// Повышающий / понижающий, величина снижения / повышения
    }
}
