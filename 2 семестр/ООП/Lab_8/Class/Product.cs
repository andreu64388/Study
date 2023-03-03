namespace Lab_8.Class
{
	public class Product
	{
		public int ProductID { get; set; }
		public string ProductName { get; set; }
		public string Category { get; set; }
		public decimal Price { get; set; }
		public string Description { get; set; }
		public byte[] Image { get; set; }

		public Product()
		{
		}

		public Product(int productID, string productName, string category, decimal price, string description, byte[] image)
		{
			ProductID = productID;
			ProductName = productName;
			Category = category;
			Price = price;
			Description = description;
			Image = image;
		}

		public override string ToString()
		{
			return $"ProductID: {ProductID}, ProductName: {ProductName}, Category: {Category}, Price: {Price}, Description: {Description}, Image: {Image}";
		}
	}
}