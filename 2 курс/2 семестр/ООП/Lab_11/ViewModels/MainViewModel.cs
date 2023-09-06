using Lab_11.Commands;
using Lab_11.Models;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using System.Windows;
using Lab_11.Database;
using System.Data.Entity;

namespace Lab_11.ViewModels
{
	public class MainViewModel : INotifyPropertyChanged
	{
		private CourseContext context;
		private ObservableCollection<Course> courses;
		private ObservableCollection<Student> students;
		private Course selectedCourse;
		private Student selectedStudent;
		private ICommand enrollStudentCommand;
		private ICommand disenrollStudentCommand;

		public MainViewModel()
		{
			context = new CourseContext();
			LoadData();
			enrollStudentCommand = new RelayCommand(EnrollStudent, CanEnrollStudent);
			disenrollStudentCommand = new RelayCommand(DisenrollStudent, CanDisenrollStudent);
		}

		public ObservableCollection<Course> Courses
		{
			get { return courses; }
			set
			{
				courses = value;
				OnPropertyChanged(nameof(Courses));
			}
		}

		public ObservableCollection<Student> Students
		{
			get { return students; }
			set
			{
				students = value;
				OnPropertyChanged(nameof(Students));
			}
		}

		public Course SelectedCourse
		{
			get { return selectedCourse; }
			set
			{
				selectedCourse = value;
				OnPropertyChanged(nameof(SelectedCourse));
			}
		}

		public Student SelectedStudent
		{
			get { return selectedStudent; }
			set
			{
				selectedStudent = value;
				OnPropertyChanged(nameof(SelectedStudent));
			}
		}

		public ICommand EnrollStudentCommand
		{
			get { return enrollStudentCommand; }
		}

		public ICommand DisenrollStudentCommand
		{
			get { return disenrollStudentCommand; }
		}

		private void LoadData()
		{
			Courses = new ObservableCollection<Course>(context.Courses.Include(c => c.Lecturer).Include(c => c.Students));
			Students = new ObservableCollection<Student>(context.Students.Include(s => s.Courses));
		}

		private bool CanEnrollStudent(object parameter)
		{
			return SelectedCourse != null && SelectedStudent != null && !SelectedCourse.Students.Contains(SelectedStudent);
		}

		private bool CanDisenrollStudent(object parameter)
		{
			return SelectedCourse != null && SelectedStudent != null && SelectedCourse.Students.Contains(SelectedStudent);
		}

		private void EnrollStudent()
		{
			if (SelectedCourse != null && SelectedStudent != null)
			{
				OnPropertyChanged(nameof(SelectedStudent));
				SelectedCourse.Students.Add(SelectedStudent);
				context.SaveChanges();
				OnPropertyChanged(nameof(SelectedCourse)); // добавляем вызов OnPropertyChanged
				OnPropertyChanged(nameof(SelectedStudent));
			}
		}

		private void DisenrollStudent()
		{
			if (SelectedCourse != null && SelectedStudent != null)
			{
				SelectedCourse.Students.Remove(SelectedStudent);
				context.SaveChanges();
				OnPropertyChanged(nameof(SelectedCourse));
				OnPropertyChanged(nameof(SelectedStudent));
			}
		}


		public event PropertyChangedEventHandler PropertyChanged;

		protected virtual void OnPropertyChanged(string propertyName)
		{
			PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
		}
	}


}