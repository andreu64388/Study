package exceptions;

import java.util.List;

public class Student {
    private String fio;
    private List<Subject> subjects;

    public String getFio() {
        return fio;
    }
    public void setFio(String fio) {
        this.fio = fio;
    }
    public List<Subject> getSubjects() {
        return subjects;
    }

    public void setSubjects(List<Subject> subjects) {
        this.subjects = subjects;
    }

    public Student(String fio, List<Subject> subjects)
    {
        try {
            setFio(fio);
            if (subjects.size() < 1)
                throw new RuntimeException("empty subject list exeption");
            setSubjects(subjects);
        }
        catch (RuntimeException ex)
        {
            System.out.println(ex.getMessage());
        }
    }

    @Override
    public String toString()
    {
        String subjList = "\n";
        for (var subj : subjects)
        {
            subjList += "-- "+ subj.toString() + "\n";
        }
        return "Name: " + getFio() + "\n" + subjList;
    }


}
