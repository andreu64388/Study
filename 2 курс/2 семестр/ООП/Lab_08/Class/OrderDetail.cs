namespace Lab_8.Class
{
	public class OrderDetail
	{
		public int OrderDetailID { get; set; }
		public int OrderID { get; set; }
		public int ProductID { get; set; }
		public int Quantity { get; set; }

		public OrderDetail()
		{
		}

		public OrderDetail(int orderDetailID, int orderID, int productID, int quantity)
		{
			OrderDetailID = orderDetailID;
			OrderID = orderID;
			ProductID = productID;
			Quantity = quantity;
		}

		public override string ToString()
		{
			return $"OrderDetailID: {OrderDetailID}, OrderID: {OrderID}, ProductID: {ProductID}, Quantity: {Quantity}";
		}
	}
}