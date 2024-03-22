package exceptions;

import exceptions.Faculty;

import java.util.List;

public class University {
    private String name;
    private List<Faculty> facultyList;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<Faculty> getFacultyList() {
        return facultyList;
    }

    public void setFacultyList(List<Faculty> facultyList) {
        this.facultyList = facultyList;
    }

    public University(String name, List<Faculty> facultyList)
    {
        try
        {
            if(facultyList.size() < 1)
                throw new RuntimeException("emtpy faculty list exeption");
            else
            {
                setName(name);
                setFacultyList(facultyList);
            }
        }
        catch (RuntimeException ex)
        {
            System.out.println(ex.getMessage());
        }
    }

    public float GetStudAverage(String fio, String facultyName, int groupNum)
    {
        float Avg = 0;
        int count = 0;
        for(var fac : this.facultyList)
        {
            if(fac.getFacultyName().equals(facultyName))
            {
               for(var group : fac.getGroupList())
               {
                   if(group.getGroupNumber() == groupNum)
                   {
                       for(var stud : group.getStudents())
                       {
                           if(stud.getFio().equals(fio))
                           {
                               for(var subj : stud.getSubjects())
                               {
                                   Avg += subj.getSubjectMark();
                                   count++;
                               }
                               Avg /= count;
                               return Avg;

                           }
                           else
                               return 0;
                       }
                   }
                   else
                       return 0;
               }
            }
            else
                return 0;
        }
        return 0;
    }

    public float GetAvgFaculty(String facultyName, String subjectName, int groupNum)
    {
        float avg = 0;
        int count = 0;
        for(var fac : this.facultyList)
        {
            if(fac.getFacultyName().equals(facultyName))
            {
                for(var group : fac.getGroupList()) {
                    if (group.getGroupNumber() == groupNum) {
                        for (var stud : group.getStudents()) {
                            for (var subj : stud.getSubjects()) {
                                if (subj.getSubjectName().equals(subjectName)) {
                                    count++;
                                    avg += subj.getSubjectMark();
                                }
                            }
                        }
                    }
                }
            }
        }
        return avg/count;
    }

    public float GetUniversityAvg(String subjName)
    {
        float avg = 0;
        int count = 0;
        for(var fac : this.getFacultyList())
        {
            for(var group : fac.getGroupList())
            {
                for (var stud : group.getStudents())
                {
                    for (var subj : stud.getSubjects())
                    {
                        if(subj.getSubjectName().equals(subjName))
                        {
                            avg += subj.getSubjectMark();
                            count++;
                        }
                    }
                }
            }
        }
        return avg/ count;
    }

}
