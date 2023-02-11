using System;
using System.Windows.Forms;

namespace Lab_1
{
	public partial class Form1 : Form
	{

		public Form1()
		{
			InitializeComponent();
		}

		private void label5_Click(object sender, EventArgs e)
		{

		}

		private void button1_Click(object sender, EventArgs e)
		{


			try
			{
				string weight = textBox1.Text;
				string height = textBox2.Text;
				string age = textBox3.Text;
				string sex = "";
				string activity = comboBox1.Text;
				string weightWant = textBox4.Text;
				string day = textBox5.Text;



				if (radioButton1.Checked)
				{
					sex = radioButton1.Text;
				}
				else if (radioButton2.Checked)
				{
					sex = radioButton2.Text;
				}
				else
				{
					throw new Exception("Выберите пол");
				}

				double w = Convert.ToDouble(weight);
				double h = Convert.ToDouble(height);
				double wantWidth = Convert.ToDouble(weightWant);

			
				double result;
				if (w is double && h is double)
				{
					result = w / (h * h) * 1000;
					result = Math.Round(result, 2);
					double diff = w - wantWidth;




					if (activity == "Поддержание веса")
					{
						

						if (result < 18.5)
						{
							result = 2500;
						}
						else if (result >= 18.5 && result <= 24.9)
						{
							result = 2000;
						}
						else if (result >= 25 && result <= 29.9)
						{
							result = 1500;
						}
						else if (result >= 30)
						{
							result = 1000;
						}

						MessageBox.Show("Ваш индекс массы тела: " + result + " ккал" + "\n" + "Вам необходимо сбросить " + diff + " кг за " + day + " дней, чтобы это сделать вам необходимо съесть " + (diff * 7700) / Convert.ToDouble(day) + " ккал в день");



					}
					else if (activity == "Снижение веса")
					{

						if (result < 18.5)
						{
							result = 2000;
						}
						else if (result >= 18.5 && result <= 24.9)
						{
							result = 1500;
						}
						else if (result >= 25 && result <= 29.9)
						{
							result = 1000;
						}
						else if (result >= 30)
						{
							result = 500;
						}

						MessageBox.Show("Ваш индекс массы тела: " + result + " ккал" + "\n" + "Вам необходимо сбросить " + diff + " кг за " + day + " дней, чтобы это сделать вам необходимо съесть " + (diff * 7700) / Convert.ToDouble(day) + " ккал в день");

					}
					else if (activity == "Увеличение веса")
					{
						if (result < 18.5)
						{
							result = 3000;
						}
						else if (result >= 18.5 && result <= 24.9)
						{
							result = 2500;
						}
						else if (result >= 25 && result <= 29.9)
						{
							result = 2000;
						}
						else if (result >= 30)
						{
							result = 1500;
						}

						MessageBox.Show("Ваш индекс массы тела: " + result + " ккал" + "\n" + "Вам необходимо набрать " + diff + " кг за " + day + " дней, чтобы это сделать вам необходимо съесть " + (diff * 7700) / Convert.ToDouble(day) + " ккал в день");

					}
					

					else
					{
						throw new Exception("Выберите тип активности");
					}
	

				}

				else
				{
					throw new Exception("Error");
				}

			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
			finally
			{

				

			}
		}

		private void label8_Click(object sender, EventArgs e)
		{

		}

		private void textBox4_TextChanged(object sender, EventArgs e)
		{

		}

		private void textBox5_TextChanged(object sender, EventArgs e)
		{

		}
	}
}
