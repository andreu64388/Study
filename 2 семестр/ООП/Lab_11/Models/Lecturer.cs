using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_11.Models
{
	public class Lecturer
	{
		public Guid Id { get; set; }

		[Required]
		[MaxLength(100)]
		public string Name { get; set; }

		[Required]
		[MaxLength(100)]
		public string ContactInfo { get; set; }

		public virtual ICollection<Course> Courses { get; set; }
	}
}
