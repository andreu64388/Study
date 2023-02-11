using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_2_5.Class
{
	[Serializable]
	public class Computer
	{
	    private string _type;
		private string _videocard;
		private int _ram;
		private string _hdd;
		private int _date;
		private Prossecor _prossecor;

		[Required]
		public string Type
		{
			get { return _type; }
			set { _type = value; }
		}

		[Required]
		public string Videocard
		{
			get { return _videocard; }
			set { _videocard = value; }
		}
		[Required]
		public int Ram
		{
			get { return _ram; }
			set { _ram = value; }
		}
		[Required]
		public string Hdd
		{
			get { return _hdd; }
			set { _hdd = value; }
		}
		[Required]
		public int Date
		{
			get { return _date; }
			set { _date = value; }
		}

		public Prossecor Prossecor
		{
			get { return _prossecor; }
			set { _prossecor = value; }
		}

		public Computer()
		{
			Type = " ";
			Videocard = " ";
			Ram = 0;
			Hdd = " ";
			Date = 0;
			Prossecor = new Prossecor();
			

		}

		public Computer(string type, string videocard, int ram, string hdd, int date, Prossecor prossecor)
		{
			Type = type;
			Videocard = videocard;
			Ram = ram;
			Hdd = hdd;
			Date = date;
			Prossecor = prossecor;
		}
		
		public override string ToString()
		{
			return string.Format("Type: {0} Videocard: {1} Ram: {2} Hdd: {3} Data: {4} Prossecor: {5}", Type, Videocard, Ram, Hdd, Date, Prossecor);
		}
		
		
		



	}
}
