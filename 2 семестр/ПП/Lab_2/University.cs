using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_2
{
	public class University : Organization
	{
		protected List<Faculty> faculties;
		public University()
		{

			faculties = new List<Faculty>();
		}

		public University(University university)
		{


		}

		public University(string name, string shortname, string address)
		{

		}


		public int addFaculty(Faculty faculty)
		{
			faculties.Add(faculty);
			return 0;

		}
		public bool delFaculty(int faculty)
		{


			return true;

		}

	}



}
