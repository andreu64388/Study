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
			courses = new ObservableCollection<Course>(context.Courses.Include(c => c.Lecturer).Include(c => c.Students));
			students = new ObservableCollection<Student>(context.Students);
			enrollStudentCommand = new RelayCommand(EnrollStudent);
			disenrollStudentCommand = new RelayCommand(DisenrollStudent);
		}

		public ObservableCollection<Course> Courses
		{
			get { return courses; }
			set
			{
				courses = value;
				OnPropertyChanged("Courses");
			}
		}

		public ObservableCollection<Student> Students
		{
			get { return students; }
			set
			{
				students = value;
				OnPropertyChanged("Students");
			}
		}

		public Course SelectedCourse
		{
			get { return selectedCourse; }
			set
			{
				selectedCourse = value;
				OnPropertyChanged("SelectedCourse");
				OnPropertyChanged("CanEnrollStudent");
				OnPropertyChanged("CanDisenrollStudent");
			}
		}

		public Student SelectedStudent
		{
			get { return selectedStudent; }
			set
			{
				selectedStudent = value;
				OnPropertyChanged("SelectedStudent");
				OnPropertyChanged("CanEnrollStudent");
				OnPropertyChanged("CanDisenrollStudent");
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



		private void EnrollStudent()
		{
			try
			{
				if (selectedCourse != null && selectedStudent != null)
				{

					context.EnrollStudent(selectedCourse.Id, selectedStudent.Id);
					selectedCourse.Students.Add(selectedStudent);
				}
			}
			catch(Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
			
			}

		

		private void DisenrollStudent()
		{
			try
			{
				if (selectedCourse != null && selectedStudent != null)
			{
				context.WithdrawStudent(selectedCourse.Id, selectedStudent.Id);
				selectedCourse.Students.Remove(selectedStudent);
			}
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
		}

		
		public event PropertyChangedEventHandler PropertyChanged;

		protected virtual void OnPropertyChanged(string propertyName)
		{
			PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
		}
	}


}