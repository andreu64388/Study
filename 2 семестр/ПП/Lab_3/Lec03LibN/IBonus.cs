using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lec03LibN
{
    public interface IBonus
    {


		float cost1hour { get; set; }// Стоимость одного часа
		float calc(float number_hours); // Вычисление вознаграждения
	
    }
}
