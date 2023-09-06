using System.ComponentModel.DataAnnotations.Schema;

namespace Lab_9.Class
{
	public class Orders
	{
		public int Id { get; set; }
		public int UserId { get; set; }
		public string Name { get; set; }

		[ForeignKey("UserId")]
		[InverseProperty("Orders")]
		public virtual User User { get; set; }
	}
}