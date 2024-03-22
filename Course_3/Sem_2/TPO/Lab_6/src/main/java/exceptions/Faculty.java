package exceptions;

import exceptions.*;

import java.util.List;

public class Faculty {
    private String facultyName;
    private List<Group> groupList;

    public String getFacultyName() {
        return facultyName;
    }

    public void setFacultyName(String facultyName) {
        this.facultyName = facultyName;
    }

    public List<Group> getGroupList() {
        return groupList;
    }

    public void setGroupList(List<Group> groupList) {
        this.groupList = groupList;
    }

    public Faculty(String name, List<Group> groupList)
    {
        try
        {
            if(groupList.size() < 1)
                throw new RuntimeException("empty group list exeption");
            else {
                setFacultyName(name);
                setGroupList(groupList);
            }
        }
        catch (RuntimeException ex)
        {
            System.out.println(ex.getMessage());
        }
    }

    public Faculty(String facultyName)
    {
        setFacultyName(facultyName);
    }

    @Override
    public String toString()
    {
        String bufer = "\n";
        for(var group : groupList)
        {
           bufer += "-- " + group.toString() + "\n";
        }
        return "Faculty name: " + getFacultyName() + bufer;
    }
}
