using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations;
namespace Lab_2_5.Class
{
	[Serializable]
	public class Prossecor
	{
		private string _manufacturer;
		private string _series;
		private string _model;
		private int _cores;
		private int _maxRate;
		private bool _l1;
		private bool _l2;
		private bool _l3;

		[Required(ErrorMessage = "Требуется поле Процессор")]
		[StringLength(30, ErrorMessage = "Вы ввели слишком короткое или длинное название страны.", MinimumLength = 2)]
		public string Manufacturer
		{
			get { return _manufacturer; }
			set { _manufacturer = value; }
		}

		[Required]
		[StringLength(30, ErrorMessage = "Вы ввели слишком короткое или длинное Series", MinimumLength = 2)]
		public string Series
		{
			get { return _series; }
			set { _series = value; }
		}
		[Required]
		[StringLength(30, ErrorMessage = "Вы ввели слишком короткое или длинное Model", MinimumLength = 2)]
		public string Model
		{
			get { return _model; }
			set { _model = value; }
		}
		[Required]
		[Attribute(ErrorMessage = "Количество ядер должно быть больше 0 и меньше 10")]
		public int Cores
		{
			get { return _cores; }
			set { _cores = value; }
		}

		public int MaxRate
		{
			get { return _maxRate; }
			set { _maxRate = value; }
		}

		public bool L1
		{
			get { return _l1; }
			set { _l1 = value; }
		}

		public bool L2
		{
			get { return _l2; }
			set { _l2 = value; }
		}

		public bool L3
		{
			get { return _l3; }
			set { _l3 = value; }
		}

		public Prossecor()
		{
			Manufacturer = "Intel";
			Series = "Core i7";
			Model = "i7-6700K";
			Cores = 4;
			MaxRate = 4;
			L1 = false;
			L2 = false;
			L3 = false;
			
		}

		public Prossecor(string manufacturer, string series, string model, int cores, int maxRate, bool l1, bool l2, bool l3)
		{
			Manufacturer = manufacturer;
			Series = series;
			Model = model;
			Cores = cores;
			MaxRate = maxRate;
			L1 = l1;
			L2 = l2;
			L3 = l3;
		}

		public override string ToString()
		{
			return $" Manufacturer: {Manufacturer}" +
				$" Series: {Series}" +
				$" Model: {Model}" +
				$" Cores: {Cores}" +
				$" MaxRate: {MaxRate}" +
				$" L1: {L1}" +
				$" L2: {L2}" +
				$" L3: {L3}";
			



		}

	}
}
