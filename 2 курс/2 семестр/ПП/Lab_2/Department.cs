using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_2
{
	public class Department
	{

		public string NameDepartament { get; set; }


		public string ShortNameDepartament { get; set; }


		public string AddressDepartament { get; set; }

		public Department(string nameDepartament, string shortNameDepartament, string addressDepartament)
		{
			NameDepartament = nameDepartament;
			ShortNameDepartament = shortNameDepartament;
			AddressDepartament = addressDepartament;
		}

		public Department()
		{
			NameDepartament = " ";
			ShortNameDepartament = " ";
			AddressDepartament = " ";
		}

		public string GetInfo()
		{
			return $"NameDepartament: {NameDepartament}, ShortNameDepartament: {ShortNameDepartament}, AddressDepartament: {AddressDepartament}";
		}








	}

}
