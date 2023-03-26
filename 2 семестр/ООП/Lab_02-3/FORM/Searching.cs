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
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_2_5.FORM
{
	public partial class Searching : Form
	{
		List<Computer> computers_ = new List<Computer>();
		public Searching(string sort)
		{
			InitializeComponent();
			label1.Text += sort;
			using (var fs = new StreamReader("data.json"))
			{

				while (!fs.EndOfStream)
				{
					var json = fs.ReadLine();

					var computer_ = JsonConvert.DeserializeObject<Computer>(json);

					computers_.Add(computer_);
				}


			}
			
			if (sort=="Частота")
			{
				var query = from el in computers_
							orderby el.Prossecor.MaxRate
							select el;

				foreach(var el in query)
				{
					listBox1.Items.Add(el.ToString());
				}
						
			}
			else if (sort=="ОЗУ")
			{
				var query = from el in computers_
							orderby el.Ram
							select el;
				foreach (var el in query)
				{
					listBox1.Items.Add(el.ToString());
				}
			}
			else
			{
				MessageBox.Show("Error");
			}
			
		

		}

		private void button1_Click(object sender, EventArgs e)
		{
			//сохранить

			using (var fs = new StreamWriter("sort.json"))
			{
				foreach (var el in listBox1.Items)
				{
					var json = JsonConvert.SerializeObject(el);
					fs.WriteLine(json);
				}
			}

		}

		private void button2_Click(object sender, EventArgs e)
		{
			listBox1.Items.Clear();

		}
	}
}
