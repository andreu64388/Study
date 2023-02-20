using Lab_2_5.Class;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.Json;
using Newtonsoft.Json;
using Lab_2_5.FORM;

namespace Lab_2_5
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
			toolStripStatustoolStripStatustoolStripStatusLabel2.Text = "Test";			
		}

		int cost = 2000;
		Computer computer = new Computer();
		private void label4_Click(object sender, EventArgs e)
		{

		}

		private void button2_Click(object sender, EventArgs e)
		{

			try
			{
				Prossecor prossecor = new Prossecor();

				string manufacturer = textBox1.Text;
				string seria = textBox2.Text;
				string model = textBox3.Text;
				int count = Convert.ToInt32(textBox4.Text);
				int frequency = Convert.ToInt32(textBox5.Text);
				int max_frequency = Convert.ToInt32(textBox6.Text);
				bool l1 = CheckOne.Checked;
				bool l2 = CheckTwo.Checked;
				bool l3 = CheckThree.Checked;

				if(l1)
				{
					cost += 1000;
				}
				if (l2)
				{
					cost += 1200;
				}
				if (l3)
				{
					cost += 1500;
				}

				cost += count * 100;


				if (manufacturer != "")
				{
					prossecor.Manufacturer = manufacturer;
				}
				else
				{
					throw new Exception("Введите производителя");
				}
				if (seria != "")
				{
					prossecor.Series = seria;
				}
				else
				{
					throw new Exception("Введите серию");
				}
				if (model != "")
				{
					prossecor.Model = model;
				}
				else
				{
					throw new Exception("Введите модель");
				}
				prossecor.Cores = count;
				prossecor.MaxRate = max_frequency;
				prossecor.L1 = l1;
				prossecor.L1 = l2;
				prossecor.L3 = l3;
				 


				computer.Prossecor = prossecor;

			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}

		}

		private void button1_Click(object sender, EventArgs e)
		{

			try
			{
				string type_of_computer = comboBox1.Text;
				string videocards = videocard.Text;
				int ozu = Convert.ToInt32(OZU.Value);
				string hard_drive = "";
				string date = maskedTextBoxYear.Text;
				cost += ozu * 100;
				if (type_of_computer != "")
				{
					computer.Type = type_of_computer;
				}
				else
				{
					throw new Exception("Введите тип компьютера");
				}

				if (radioButton1.Checked)
				{
					hard_drive = radioButton1.Text;
					cost += 1000;

				}
				else if (radioButton2.Checked)
				{
					hard_drive = radioButton2.Text;
					cost += 2000;
				}
				else
				{
					throw new Exception("Выберите тип жесткого диска");
				}
				computer.Hdd = hard_drive;
				if (videocards != "")
				{
					computer.Videocard = videocards;
				}
				else
				{
					throw new Exception("Введите видеокарту");
				}
				if (ozu != 0)
				{
					computer.Ram = ozu;
				}
				else
				{
					throw new Exception("Введите ОЗУ");
				}
				if (date !="")
				{
					int dates = Convert.ToInt32(date);
					computer.Date = dates;
				}
				else
				{
					throw new Exception("Введите дату");
				}
				var results = new List<ValidationResult>();
				var context = new ValidationContext(computer);

				if (!Validator.TryValidateObject(computer, context, results, true))
				{
					foreach (var error in results)
					{
						MessageBox.Show(error.ErrorMessage);
					}
				}
				else
				{
					MessageBox.Show("Все данные введены верно.");
				}

			}
			catch(Exception ex)
			{
				MessageBox.Show(ex.Message);
			}			
			
		}

		private void Hf_Click(object sender, EventArgs e)
		{
			MessageBox.Show(cost.ToString()+"$");
			DateTime date = DateTime.Now;
			toolStripStatustoolStripStatustoolStripStatusLabel2.Text = "Подсчет данных " + date.ToString();
		}

		private void button3_Click(object sender, EventArgs e)
		{
			List<Computer> computers_ = new List<Computer>();


			using (var fs = new StreamReader("data.json"))
			{

				while (!fs.EndOfStream)
				{
					var json = fs.ReadLine();

					var computer_ = JsonConvert.DeserializeObject<Computer>(json);

					computers_.Add(computer_);
				}
				MessageBox.Show(computers_.Count.ToString());


				foreach (var el in computers_)
				{
					MessageBox.Show(el.ToString());
				}
				DateTime date = DateTime.Now;
				toolStripStatustoolStripStatustoolStripStatusLabel2.Text = "Получить данные " + date;

			}
		}
		private void button4_Click(object sender, EventArgs e)
		{
		using (var fs = new StreamWriter("data.json", true))
			{
				var json = JsonConvert.SerializeObject(computer);
				fs.WriteLine(json);
			}
			computer = new Computer();
			DateTime date = DateTime.Now;
			toolStripStatustoolStripStatustoolStripStatusLabel2.Text = "Запись в файл" + date.ToString();
		}

		private void оПрогрмаммеToolStripMenuItem_Click(object sender, EventArgs e)
		{
			MessageBox.Show($"V.2\n\nРазработчик: Коренчук Андрей Васильевич", "Информация", MessageBoxButtons.OK, MessageBoxIcon.Information);
			DateTime date = DateTime.Now;
			toolStripStatustoolStripStatustoolStripStatusLabel2.Text = "О программе " + date.ToString();

		}

		private void оПрогрмаммеToolStripMenuItem_Click_1(object sender, EventArgs e)
		{
			MessageBox.Show($"V.2\n\nРазработчик: Коренчук Андрей Васильевич", "Информация", MessageBoxButtons.OK, MessageBoxIcon.Information);
			DateTime date = DateTime.Now;
			toolStripStatustoolStripStatustoolStripStatusLabel2.Text = "О программе " + date.ToString();
		}

		private void mToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Search search = new Search();
			search.Show();
			DateTime date = DateTime.Now;
			toolStripStatustoolStripStatustoolStripStatusLabel2.Text = "Поиск " + date.ToString();


		}

		private void частотеToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Searching searching = new Searching("Частота");
			searching.Show();
			DateTime date = DateTime.Now;
			toolStripStatustoolStripStatustoolStripStatusLabel2.Text = "Поиск по частоте " + date.ToString();

		}

		private void оЗУToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Searching searching = new Searching("ОЗУ");
			searching.Show();
			DateTime date = DateTime.Now;
			toolStripStatustoolStripStatustoolStripStatusLabel2.Text = "Поиск по ОЗУ " + date.ToString();
		}

		private void toolStripMenuItem1_Click(object sender, EventArgs e)
		{
			//вперед назада сделать функуионал
			
			
			

		}

		private void скрытьToolStripMenuItem_Click(object sender, EventArgs e)
		{

		}

		private void button5_Click(object sender, EventArgs e)
		{
			Button button = sender as Button;
			if (menuStrip2.Visible == true)
			{
				menuStrip2.Visible = false;
				button.Text = "Показать меню";

			}
			else
			{
				menuStrip2.Visible = true;
				button.Text = "Скрыть меню";
			}
			DateTime date = DateTime.Now;
			toolStripStatustoolStripStatustoolStripStatusLabel2.Text = "Скрыть/Показать меню " + date.ToString();

		}

		private void toolStripStatusLabel1_Click(object sender, EventArgs e)
		{

		}

		private void toolStripStatustoolStripStatustoolStripStatusLabel2_Click(object sender, EventArgs e)
		{

		}
	}
}
