

namespace Lab_2;

	class Progrma
{
	static public void Main()
	{

		Organization organization = new Organization();


		University university = new University();


		Department department = new Department();

		Faculty faculty = new Faculty("Andre ", "ds ", " as");
		faculty.addDepartment(department);
		university.addFaculty(faculty);
		organization.printinfo();
		university.printinfo();
		faculty.printinfo();





	}
}


