<<<<<<< HEAD
﻿
using Newtonsoft.Json;
using System;
using System.Text.Json;
=======
﻿using System;

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
namespace Lab_4_5.Class
{
	/*Каждый товар/услуга должен иметь название краткое и полное,
описание, изображение (можно несколько), категория, рейтинг, цену,
количество и другие параметры (цвет, размер, страна доставки, скидки,
нет в наличии, связанные товары/услуги, количество купленных*/

	public class Product
	{
<<<<<<< HEAD
		#region Fields 
		 
=======
		#region Fields

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		private string _id;
		private string _name;
		private string _description;
		private string _img;
		private float _price;
		private int _count;
		private int _rating;

<<<<<<< HEAD
		#endregion

		#region Properties



		public Category Category { get; set; }
		
=======
		#endregion Fields

		#region Properties

		public Category Category { get; set; }

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		public string Id
		{
			get
			{
				return _id;
<<<<<<< HEAD


			}
			 set
			{
				_id = value;
					
			}

=======
			}
			set
			{
				_id = value;
			}
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		}

		public string Name
		{
			get
			{
				return _name;
			}
			set
			{
				_name = value;
			}
		}

<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		public string Description
		{
			get
			{
				return _description;
			}
			set { _description = value; }
		}

		public string Img
		{
			get
			{
				return _img;
			}
			set
			{
				_img = value;
			}
		}

		public float Price
		{
			get { return _price; }
			set { _price = value; }
		}
<<<<<<< HEAD
		
=======

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		public int Count
		{
			get
			{
				return _count;
			}
			set
			{
				_count = value;
			}
		}
<<<<<<< HEAD
		
=======

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		public int Rating
		{
			get
			{
				return _rating;
			}
			set
			{
				_rating = value;
			}
		}

<<<<<<< HEAD

		#endregion

		#region Constructor


		public Product(string name, string description, string img, float price, int count, int rating, Category category)
		{

=======
		#endregion Properties

		#region Constructor

		public Product(string name, string description, string img, float price, int count, int rating, Category category)
		{
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
			Name = name;
			Description = description;
			Img = img;
			Price = price;
			Count = count;
			Rating = rating;
			Category = category;
<<<<<<< HEAD



=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		}

		public Product()
		{
<<<<<<< HEAD
			Id =  Guid.NewGuid().ToString();
=======
			Id = Guid.NewGuid().ToString();
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
			Name = "No name";
			Description = "No description";
			Img = "No img";
			Price = 0;
			Count = 0;
			Rating = 0;
			Category = Category.Toys;
<<<<<<< HEAD

		}




		#endregion
=======
		}

		#endregion Constructor
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced

		#region Methods

		public override string ToString()
		{
			return $"Id: {Id} \n" +
					$"Name: {Name} \n" +
					$"Description: {Description} \n" +
					$"Img: {Img} \n" +
					$"Price: {Price} \n" +
					$"Count: {Count} \n" +
					$"Category {Category}\n" +
					$"Rating: {Rating} \n";
<<<<<<< HEAD

		}
		#endregion
=======
		}

		#endregion Methods
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
	}

	public enum Category
	{
		Clothes,
		Phone,
		Toys
<<<<<<< HEAD

=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
	}
}