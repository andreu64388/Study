Create database Company

use Company;


CREATE TABLE Course (
    Id UNIQUEIDENTIFIER NOT NULL PRIMARY KEY,
    Title NVARCHAR(100) NOT NULL,
    Hours INT NOT NULL,
    LecturerId UNIQUEIDENTIFIER NOT NULL,
    CONSTRAINT FK_Course_Lecturer FOREIGN KEY (LecturerId) REFERENCES Lecturer (Id)
);

CREATE TABLE Student (
    Id UNIQUEIDENTIFIER NOT NULL PRIMARY KEY,
    Name NVARCHAR(100) NOT NULL,
    ContactInfo NVARCHAR(100) NOT NULL
);

CREATE TABLE Lecturer (
    Id UNIQUEIDENTIFIER NOT NULL PRIMARY KEY,
    Name NVARCHAR(100) NOT NULL,
    ContactInfo NVARCHAR(100) NOT NULL
);
-- Insert Lecturers
INSERT INTO Lecturers (Id, Name, ContactInfo)
VALUES
(NEWID(), 'John Smith', 'john@example.com'),
(NEWID(), 'Jane Doe', 'jane@example.com');

-- Insert Courses
INSERT INTO Courses (Id, Title, Hours, LecturerId)
VALUES
(NEWID(), 'Programming Basics', 40, (SELECT Id FROM Lecturers WHERE Name = 'John Smith')),
(NEWID(), 'Web Development', 60, (SELECT Id FROM Lecturers WHERE Name = 'Jane Doe')),
(NEWID(), 'Database Management', 50, (SELECT Id FROM Lecturers WHERE Name = 'John Smith')),
(NEWID(), 'Data Structures and Algorithms', 70, (SELECT Id FROM Lecturers WHERE Name = 'Jane Doe'));

-- Insert Students
INSERT INTO Students (Id, Name, ContactInfo)
VALUES
(NEWID(), 'Alice', 'alice@example.com'),
(NEWID(), 'Bob', 'bob@example.com'),
(NEWID(), 'Charlie', 'charlie@example.com'),
(NEWID(), 'David', 'david@example.com');



-- Insert course-student relationships
delete from Students

select * from CourseStudents
INSERT INTO CourseStudents (CourseId, StudentId)
VALUES
((SELECT Id FROM Courses WHERE Title = 'Programming Basics'), (SELECT Id FROM Students WHERE Name = 'Alice')),
((SELECT Id FROM Courses WHERE Title = 'Programming Basics'), (SELECT Id FROM Students WHERE Name = 'Bob')),
((SELECT Id FROM Courses WHERE Title = 'Web Development'), (SELECT Id FROM Students WHERE Name = 'Charlie')),
((SELECT Id FROM Courses WHERE Title = 'Database Management'), (SELECT Id FROM Students WHERE Name = 'Alice')),
((SELECT Id FROM Courses WHERE Title = 'Database Management'), (SELECT Id FROM Students WHERE Name = 'Charlie')),
((SELECT Id FROM Courses WHERE Title = 'Data Structures and Algorithms'), (SELECT Id FROM Students WHERE Name = 'Bob'))
((SELECT Id FROM Courses WHERE Title = 'Data Structures and Algorithms'), (SELECT Id FROM Students WHERE Name = 'David'));