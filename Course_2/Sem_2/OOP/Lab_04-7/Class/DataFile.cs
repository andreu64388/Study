<<<<<<< HEAD
﻿using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Management.Instrumentation;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using Newtonsoft.Json;


namespace Lab_4_5.Class
{
public static class DataFile
	{
		
		private static string _path = "products.json";
=======
﻿using Newtonsoft.Json;
using System.Collections.ObjectModel;
using System.IO;

namespace Lab_4_5.Class
{
	public static class DataFile
	{
		private static string _path = "products.json";

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		public static void JsonSerializeProducts(Product product)
		{
			using (var sw = new StreamWriter(_path, true))
			{
				var jsonProduct = JsonConvert.SerializeObject(product);
				sw.WriteLine(jsonProduct);
			}
		}
<<<<<<< HEAD
=======

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		public static void JsonSerializeProductsCollection(ObservableCollection<Product> products)
		{
			using (var sw = new StreamWriter(_path))
			{
<<<<<<< HEAD
				foreach(var el in products)
=======
				foreach (var el in products)
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
				{
					var json = JsonConvert.SerializeObject(el);
					sw.WriteLine(json);
				}
			}
		}

		public static ObservableCollection<Product> JsonDeseriazeProducts()
		{
<<<<<<< HEAD
		var products = new ObservableCollection<Product>();
			
=======
			var products = new ObservableCollection<Product>();

>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
			using (var sr = new StreamReader(_path))
			{
				while (!sr.EndOfStream)
				{
					var jsonProduct = sr.ReadLine();
					var product = JsonConvert.DeserializeObject<Product>(jsonProduct);
					products.Add(product);
				}
			}
			return products;
<<<<<<< HEAD
				
=======
>>>>>>> 26290635e388230624d9f6ed673ae32d64783ced
		}
	}
}