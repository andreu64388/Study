using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_11.Models
{
	public class Course
	{
		public Guid Id { get; set; }

		[Required]
		[MaxLength(100)]
		public string Title { get; set; }

		public int Hours { get; set; }

		[ForeignKey("Lecturer")]
		public Guid LecturerId { get; set; }

		public virtual Lecturer Lecturer { get; set; }

		public virtual ICollection<Student> Students { get; set; }
	}
}
