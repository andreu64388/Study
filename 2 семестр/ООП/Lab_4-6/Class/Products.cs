using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_4_5.Class
{
	static class Products
	{

		public static ObservableCollection<Product> products = new ObservableCollection<Product>();

		public static void AddProduct(Product product)
		{
			products.Add(product);
		}

		public static void RemoveProduct(Product product)
		{
			products.Remove(product);
		}
		public static void ShowProducts()
		{
			foreach (var product in products)
			{
				Console.WriteLine(product);
			}
		}

		
	}

		


	
}
