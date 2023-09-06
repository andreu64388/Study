using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_1;

/*6.	Разработайте класс C2(наименование может быть любым) имена членов  которого, совпадают с классом C1 и реализующим интерфейс I1. */

class C2 : C1, I1
{
	public int Id { get; set; }
	public void Method()
	{
		Console.WriteLine("Method");
	}
	public event EventHandler Event;
	public int this[int index]
	{
		get { return index; }
		set { index = value; }
	}

	public void PrintI()
	{
		this.PrintInfos();
	}
}