namespace Lab_2;

public class Faculty:Organization
{

	private string _name;
	private string _shortName;
	private string _address;


	protected List<Lab_2.Department> Departments;
	 public Faculty() {
		Departments = new List<Department>();
		_name = string.Empty;
		_shortName = string.Empty;
		_address = string.Empty;

	}

	Faculty(Faculty faculty)
	{
		_name = faculty.Name;
		_shortName = faculty.ShortName;
		_address = faculty.Address;
		Departments = new List<Lab_2.Department>();
	}
	public Faculty(string name, string shortName, string address)
	{
		_name = name;
		_shortName = shortName;
		_address = address;
		Departments = new List<Lab_2.Department>();
	}
	public string Name
	{
		get { return _name; }
		set { _name = value; }
	}
	public string ShortName
	{
		get { return _shortName; }
		set { _shortName = value; }
	}
	public string Address
	{
		get { return _address; }
		set { _address = value; }
	}
	public int addDepartment(Department department)
	{
		Departments.Add(department);
		return 0;

	}
	public bool delDepartment(int index)
	{
		if (index < 0 || index >= Departments.Count)
		{
			return false;
		}
		Departments.RemoveAt(index);
		return true;

	}
	public bool updDepartment(int index)
	{
		if (index < 0 || index >= Departments.Count)
		{
			return false;
		}
		Departments[index] = new Department();
		return true;
	}
	private bool verDepartment(int index)
	{
		if (index < 0 || index >= Departments.Count)
		{
			return false;
		}
		return true;
	}
	public List<Department> getDepartment()
	{ return Departments; }

	public void printinfo()
	{
		Console.WriteLine($"Name: {_name}, ShortName: {_shortName}, Address: {_address}");
		foreach (var item in Departments)
		{
			Console.WriteLine(item.GetInfo());
		}
	}

	public int getJobVacancies(JobVacancy jobVacancy)
	{
		int count = 0;
		foreach (var item in Departments)
		{
			if (item.NameDepartament == jobVacancy.NameDepartament)
			{
				count++;
			}
		}
		return count;

	}
	public int addJobTitle(Job title)
	{ 
		int count = 0;
		foreach (var item in Departments)
		{
			if (item.NameDepartament == title.NameDepartament)
			{
				count++;
			}
		}
		return count;
	}
	public int openJobVacansion(JobVacancy jobVacancy)
	{
		int count = 0;
		foreach (var item in Departments)
		{
			if (item.NameDepartament == jobVacancy.NameDepartament)
			{
				count++;
			}
		}
		return count;
	}
	public bool closeVacansion(int index)
	{
		if (index < 0 || index >= Departments.Count)
		{
			return false;
		}
		Departments.RemoveAt(index);
		return true;
	}
	public Empoloee recriut(JobVacancy jobVacancy)
	{
		Empoloee empoloee= new Empoloee();
		return empoloee;

	}
	public void Dismiss()
	{
		Departments.Clear();
		_name = string.Empty;
		_shortName = string.Empty;
		_address = string.Empty;
	}

	public int getJobVacancies()
	{
		throw new NotImplementedException();
	}

	public void getEmploee()
	{
		throw new NotImplementedException();
	}

	public void getJobTitle()
	{
		throw new NotImplementedException();
	}

	public bool openJob()
	{
		throw new NotImplementedException();
	}

	public int closeJob()
	{
		throw new NotImplementedException();
	}
}










