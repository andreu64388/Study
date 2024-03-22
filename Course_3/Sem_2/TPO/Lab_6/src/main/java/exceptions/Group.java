package exceptions;

import java.util.List;

public class Group {

    private int groupNumber;
    private List<Student> students;

    public List<Student> getStudents() {
        return students;
    }

    public void setStudents(List<Student> students) {
        this.students = students;
    }

    public int getGroupNumber() {
        return groupNumber;
    }

    public void setGroupNumber(int groupNumber) {
        this.groupNumber = groupNumber;
    }

    public Group(int number, List<Student> students) {
        try {
            if (students.size() < 1)
                throw new RuntimeException("empty students list exeption");
            else
            {
                setGroupNumber(number);
                setStudents(students);
            }
        } catch (RuntimeException ex) {
            System.out.println(ex.getMessage());
        }
    }

    @Override
    public String toString()
    {
        String bufer = "\n";
        for(var stud : students)
        {
            bufer += "-- " + stud.toString() + "\n";
        }
        return "Group number: " + getGroupNumber() + "\n" + bufer;
    }
}
