
CREATE DATABASE UNIVERSITY;
--������� ���������� � ��������� UNIVERSITY
GO

USE UNIVERSITY;
--���������� ���� ���� ������
--Yearp <YEAR(GETDATE()) +2)

CREATE TABLE PROGR (
SUBJ NVARCHAR(40) NOT NULL,
IDST INT FOREIGN KEY REFERENCES STUD(IDST) ,
PDATE DATE,
NOTE INT DEFAULT 1 CHECK (NOTE>=1 AND NOTE<=10)
);

CREATE TABLE [GROUP] (
IDGROUP  INT  CONSTRAINT IDGR_PK PRIMARY KEY,
FACLT NVARCHAR(20) ,
PROF  NVARCHAR(20),
YEARP INT
);

CREATE TABLE STUD(
IDST INT IDENTITY(1,1) CONSTRAINT IDST_PK  PRIMARY KEY,
IDGROUP INT FOREIGN KEY REFERENCES [GROUP](IDGROUP),
[NAME] NVARCHAR(20),
[SURNAME] NVARCHAR(20),
BDAY DATE
);
--������� ��� ������� � ������������� ��� ������ ��� ������ ����

INSERT INTO [GROUP] (IDGROUP,FACLT,PROF,YEARP)
VALUES
(1,'FIT','ISIT',2021),
(2,'FIT','POIT',2021),
(3,'LX','FOREST',2021);

UPDATE [GROUP] SET YEARP = 2022 
WHERE IDGROUP = 3; 

SELECT * FROM [GROUP];

INSERT INTO STUD (IDGROUP,[NAME],SURNAME,BDAY)
VALUES
(1,'Andrey','Korenchuck','01.12.2003'),
(2,'Dima','Gaykow','01.12.2004'),
(3,'Vasy','Pupkin','01.12.2005');

SELECT * FROM STUD;

INSERT INTO PROGR(SUBJ,IDST,PDATE,NOTE)
VALUES('�����',6,'01.12.2022',10),
('�����',7,'01.12.2022',5),
('�����',8,'01.12.2022',4);

SELECT * FROM PROGR;

SELECT * FROM STUD 
INNER JOIN [GROUP] 
ON STUD.IDGROUP = [GROUP].IDGROUP
WHERE STUD.BDAY BETWEEN '2003' AND '2005'
ORDER BY BDAY;

SELECT * FROM  STUD
JOIN PROGR ON STUD.IDST = PROGR.IDST
WHERE PROGR.NOTE BETWEEN 4 AND 6



