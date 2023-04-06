using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Lab_2;

public class Organization: IStaff
{
	public int Id { get; set; }

	public string Name { get; protected set; }
	public Type ShortName { get; protected set; }

	public string Address
	{
		get; protected set;
	}
	public DateTime timeStramp { get; protected set; }

	public Organization()
	{
		Name = string.Empty;
		ShortName = null;
		Address = string.Empty;
		timeStramp = DateTime.Now;
	}

 public Organization(Organization organization)
	{
		Name = organization.Name;
		ShortName = organization.ShortName;
		Address = organization.Address;
		timeStramp = organization.timeStramp;
	}

	public Organization(string name, Type shortName, string address)
	{
		Name = name;
		ShortName = shortName;
		Address = address;
		timeStramp = DateTime.Now;
	}

	public void printinfo()
	{ 
		Console.WriteLine ($"Name: {Name}, ShortName: {ShortName}, Address: {Address}");


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



