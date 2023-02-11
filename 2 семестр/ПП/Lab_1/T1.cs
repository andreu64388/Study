using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_1;

/*4.	Разработайте интерфейс  I1(наименование может быть любым), содержащий:
	свойство;
	метод;
	событие; 
	индексатор.
*/

interface I1
{
	int Id { get; set; }
	void Method();
	event EventHandler Event;
	int this[int index] { get; set; }
}