using Lab_2_5.Class;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_2_5.FORM
{
	public partial class Search : Form
	{
		List<Computer> computers_ = new List<Computer>();

		public Search()
		{
			InitializeComponent();
		

			using (var fs = new StreamReader("data.json"))
			{

				while (!fs.EndOfStream)
				{
					var json = fs.ReadLine();

					var computer_ = JsonConvert.DeserializeObject<Computer>(json);

					computers_.Add(computer_);
				}
				

			}
		}

		private void button1_Click(object sender, EventArgs e)
		{
			string manufacturer = textBox1.Text;
			string model = textBox2.Text;

			//регурялное выражение для ввода букв и цифп
			Regex regex = new Regex(@"^[a-zA-Z0-9]+$");
				

			//провверить или вели ли ввод

			if (manufacturer!="" && regex.IsMatch(manufacturer) && model=="")
			{
			
			
				var query = from el in computers_
							where el.Prossecor.Manufacturer== manufacturer
							select el;
				foreach (var el in query)
				{

					listBox1.Items.Add(el.ToString());
				}
			}
			else if (manufacturer == "" && model != "" && regex.IsMatch(model))
			{
				var query = from el in computers_
							where el.Prossecor.Model == model
							select el;

				foreach (var el in query)
				{
					listBox1.Items.Add(el.ToString());
				}
				

			}
			else if (manufacturer != "" && model != "" && regex.IsMatch(manufacturer) && regex.IsMatch(model))
			{
				var query = from el in computers_
							where el.Prossecor.Manufacturer == manufacturer && el.Prossecor.Model == model
							select el;
				foreach (var el in query)
				{
					listBox1.Items.Add(el.ToString());
				}

			}
			else
			{
				MessageBox.Show("Неверный ввод");


			}

		}

		private void button3_Click(object sender, EventArgs e)
		{
			listBox1.Items.Clear();
		}

		private void button2_Click(object sender, EventArgs e)
		{
			
			using (var fs = new StreamWriter("search.json", true))
			{
				foreach (var el in listBox1.Items)
				{
					fs.WriteLine(el.ToString());
					
				}
				

			}
		}
	}
}
