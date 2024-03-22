package exceptions;

public class Subject {
    private String subjectName;
    private int subjectMark;

    public String getSubjectName() {
        return subjectName;
    }

    public void setSubjectName(String subjectName) {
        this.subjectName = subjectName;
    }

    public int getSubjectMark() {
        return subjectMark;
    }

    public void setSubjectMark(int subjectMark) {

        this.subjectMark = subjectMark;
    }


    public Subject(String name, int mark)
    {
        try {
            if(mark < 0 || mark > 10)
                throw new RuntimeException("Not valid mark");
            setSubjectMark(mark);
            setSubjectName(name);
        }
        catch (RuntimeException ex)
        {
            System.out.println(ex.getMessage());
        }

    }

    @Override
    public String toString()
    {
        return subjectName + ": " + subjectMark;
    }
}
