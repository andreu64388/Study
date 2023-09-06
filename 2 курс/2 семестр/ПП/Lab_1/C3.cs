using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_1;

/*9.	Разработайте 2 класса C3  и С4 (наименования могут быть любыми) демонстрирующих:
	наследование C4 (производный) от C3 (базовый);
	наследование членов с модификаторами доступа;
	связь «наследование»;
	все члены класса и интерфейса;
	все необходимые стереотипы.
*/

class C3 : C2
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


class C4 : C3
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


