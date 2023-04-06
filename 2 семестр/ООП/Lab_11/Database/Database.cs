using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Data.Entity;
using System.Linq.Expressions;
using System.Threading.Tasks;

using Lab_11.Models;


namespace Lab_11.Database
{
	public class CourseContext : DbContext
	{
		public DbSet<Course> Courses { get; set; }
		public DbSet<Student> Students { get; set; }
		public DbSet<Lecturer> Lecturers { get; set; }

		protected override void OnModelCreating(DbModelBuilder modelBuilder)
		{
			modelBuilder.Entity<Course>()
				.HasMany(c => c.Students)
				.WithMany(s => s.Courses)
				.Map(cs =>
				{
					cs.MapLeftKey("CourseId");
					cs.MapRightKey("StudentId");
					cs.ToTable("CourseStudents");
				});
		}

		public CourseContext() : base("name=Test")
		{
		}
		public void EnrollStudent(Guid courseId, Guid studentId)
		{
			var course = Courses.Find(courseId);
			if (course == null)
			{
				throw new ArgumentException("Invalid course ID.");
			}

			var student = Students.Find(studentId);
			if (student == null)
			{
				throw new ArgumentException("Invalid student ID.");
			}

			if (course.Students.Contains(student))
			{
				throw new ArgumentException("Student is already enrolled in this course.");
			}

			course.Students.Add(student);
			SaveChanges();
		}

		public void WithdrawStudent(Guid courseId, Guid studentId)
		{
			var course = Courses.Find(courseId);
			if (course == null)
			{
				throw new ArgumentException("Invalid course ID.");
			}

			var student = Students.Find(studentId);
			if (student == null)
			{
				throw new ArgumentException("Invalid student ID.");
			}

			if (!course.Students.Contains(student))
			{
				throw new ArgumentException("Student is not enrolled in this course.");
			}

			course.Students.Remove(student);
			SaveChanges();
		}

	}

}