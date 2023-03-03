using System;

namespace Lab_8.Class
{
	public class Order
	{
		public int OrderID { get; set; }
		public int UserID { get; set; }
		public DateTime OrderDate { get; set; }
		public decimal TotalAmount { get; set; }

		public Order()
		{ }

		public Order(int orderId, int userId, DateTime orderDate, decimal totalAmount)
		{
			OrderID = orderId;
			UserID = userId;
			OrderDate = orderDate;
			TotalAmount = totalAmount;
		}

		public override string ToString()
		{
			return $"Order ID: {OrderID}, User ID: {UserID}, Order Date: {OrderDate}, Total Amount: {TotalAmount}";
		}
	}
}