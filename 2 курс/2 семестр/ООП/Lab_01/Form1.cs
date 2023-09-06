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
					else if (activity == "Снижение веса ")
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


/*1. Какое основное назначение технологии Windows Forms, ее особенности,
преимущества и недостатки?
2. Зачем используется класс Form? Назовите основные методы, свойства и
события данного класса.
3. Поясните структуру проекта и назначение всех файлов?
4. Зачем нужен атрибут STAThreadAttribute?
5. Как в вашем проекте используются события и делегаты?
6. Объясните схему работы цепочек делегатов.
7. Объясните механизм подписки и отмены подписки на события.
8. Как создать вторую форму и передать туда данные? Есть ли другие
способы?
9. Как во время выполнения приложения добавить/удалить элемент
управления?*/

//1 Windows Forms - это технология, которая позволяет создавать приложения с графическим интерфейсом пользователя. Основные преимущества Windows Forms - это простота в использовании, быстрота разработки, возможность использования в р�

//2 Класс Form - это базовый класс для всех форм. Он содержит в себе методы, свойства и события, которые используются для создания форм. Основные методы: - Show() - показывает форму. - ShowDialog() - показывает форму как диалоговое окно. - Close() - закрывает форму. - Hide() - скрывает форму. - Dispose() - освобождает ресурсы, занятые формой. - Activate() - активирует форму. - Focus() - устанавливает фокус на форму. - Select() - устанавливает фокус на форму. - SelectNextControl() - устанавливает фокус на следующий элемент управления. - SelectNextControl() - устанавливает фокус на предыдущий элемент управления. - SelectNextControl() - устанавливает фокус на следующий элемент управления. - SelectNextControl() - устанавливает фокус на предыдущий элемент управления. - SelectNextControl() - устанавливает фокус на следующий элемент управления. - SelectNextControl() - устанавливает фокус на предыдущий элемент управления. - SelectNextControl() - устанавливает фокус на следующий элемент управления. - SelectNextControl() - устанавливает фокус на предыдущий элемент управления. - SelectNextControl() - устанавливает фокус на следующий элемент управления. - SelectNextControl() - устанавливает фокус на предыдущий элемент управления. - SelectNextControl() - устанавливает фокус на следующий элемент управления. - SelectNextControl() - устанавливает фокус на предыдущий элемент управления. - SelectNextControl() - устанавливает фокус на следующий элемент управления. - SelectNext

//3 Класс Button - это класс, который позволяет создавать кнопки. Основные свойства: - Text - текст, который отображается на кнопке. - BackColor - цвет фона кнопки. - ForeColor - цвет текста кнопки. - Font - шрифт текста кнопки. - Image - изображение, которое отображается на кнопке. - ImageAlign - выравнивание изображения на кнопке. - TextAlign - выравнивание текста на кнопке. - FlatStyle - стиль кнопки. - FlatAppearance.BorderSize - толщина границы кнопки. - FlatAppearance.BorderColor - цвет границы кнопки. - FlatAppearance.MouseDownBackColor - цвет кнопки при нажатии. - FlatAppearance.MouseOverBackColor - цвет кнопки при наведени

// 



