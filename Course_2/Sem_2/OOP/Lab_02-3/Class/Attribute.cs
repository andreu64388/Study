using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_2_5.Class
{
	class Attribute : ValidationAttribute
	{
		//Пользовательский атрибут для валидации процессора

		public override bool IsValid(object value)
		{
			Prossecor prossecor = value as Prossecor;
			if (prossecor != null)
			{
				if (prossecor.MaxRate > 0 && prossecor.MaxRate < 10)
				{
					return true;
				}
			}
			return false;
		}
	}
}
