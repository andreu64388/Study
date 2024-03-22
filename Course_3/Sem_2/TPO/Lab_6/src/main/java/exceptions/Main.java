package org.example;

import exceptions.*;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {

        // test non-valid mark
        Subject subject = new Subject("math", 12);

        // test empty list
        List<Subject> subjects = new ArrayList<Subject>();
        Student student = new Student("student1", subjects);

        //test empty studs in group
        List<Student> students = new ArrayList<>();
        Group group = new Group(5, students);

        //test emtpy group in faculty
        List<Group> groupList = new ArrayList<>();
        Faculty faculty =new Faculty("fit", groupList);

        // test empty faculty ltst in university
        List<Faculty> facultyList = new ArrayList<>();
        University university = new University("BSU", facultyList);



        // normal cases
        List<Student> studentList1 = new ArrayList<>();
        studentList1.add(new Student("student 1", new ArrayList<Subject>
                (Arrays.asList(new Subject("Math", 9), new Subject("TPO", 10)))));
        studentList1.add(new Student("student 2", new ArrayList<Subject>
                (Arrays.asList(new Subject("Math", 3), new Subject("TPO", 9)))));

        List<Student> studentList2 = new ArrayList<>();
        studentList2.add(new Student("student 3", new ArrayList<Subject>
                (Arrays.asList(new Subject("Math", 9), new Subject("TPO", 9)))));
        studentList2.add(new Student("student 4", new ArrayList<Subject>
                (Arrays.asList(new Subject("Math", 8), new Subject("TPO", 7)))));

        List<Student> studentList3 = new ArrayList<>();
        studentList3.add(new Student("student 5", new ArrayList<Subject>
                (Arrays.asList(new Subject("Math", 3), new Subject("Chemistry", 9)))));
        studentList3.add(new Student("student 6", new ArrayList<Subject>
                (Arrays.asList(new Subject("Math", 3), new Subject("Chemistry", 7)))));



        List<Group> groupList1 = new ArrayList<>();
        groupList1.add(new Group(3, studentList1));
        groupList1.add(new Group(4, studentList2));

        List<Group> groupList2 = new ArrayList<>();
        groupList2.add(new Group(1, studentList3));


        Faculty faculty1 = new Faculty("fit", groupList1);
        Faculty faculty2 = new Faculty("LH", groupList2);

        List<Faculty> facultyList1 = new ArrayList<>();
        facultyList1.add(faculty1);
        facultyList1.add(faculty2);

        University university1 = new University("BSTU", facultyList1);


        // find stud average mark
        System.out.println("\n ------ \n");
        System.out.println("Student1 AVG: " + university1.GetStudAverage("student 1", "fit", 3));
        System.out.println("Fit 3 Math AVG: " + university1.GetAvgFaculty("fit", "Math", 3));
        System.out.println("University Math AVG: " + university1.GetUniversityAvg("Math"));
    }
}