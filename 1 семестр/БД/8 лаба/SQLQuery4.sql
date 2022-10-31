/*4. Разработать T-SQL-скрипты, вы-полняющие: 
 вычисление значений переменной z 
 
для различных значений исходных дан-ных;
 преобразование полного ФИО сту-дента в сокращенное (например, Макей-чик Татьяна Леонидовна в Макейчик Т. Л.);
 поиск студентов, у которых день рождения в следующем месяце, и опре-деление их возраста;
 поиск дня недели, в который сту-денты некоторой группы сдавали экза-мен по СУБД.
*/
DECLARE 
@Z FLOAT,
@T FLOAT = 21,
@X FLOAT = 5;

IF @T > @X
SET @Z = POWER(SIN(@T), 2);

ELSE IF @T < @X
SET @Z = 4*(@T + @X);

ELSE
SET @Z = 1 - EXP(@X-2);

SELECT @Z;
-------------------------------------
DECLARE @LASTNAME NVARCHAR(20) = 'КОРЕНЧУК',
@FIRSTNAME NVARCHAR(20) = 'АНДРЕЙ',
@SURNAME NVARCHAR(20) = 'ВАСИЛЬЕВИЧ',
@LONGNAME NVARCHAR(50),
@SHORTNAME NVARCHAR(30);

SET @LONGNAME = @LASTNAME + ' ' + @FIRSTNAME + ' ' + @SURNAME;

SET @FIRSTNAME = SUBSTRING(@FIRSTNAME, 1,1)+'.';
SET @SURNAME = SUBSTRING(@SURNAME, 1,1)+'.';
SET @SHORTNAME = @LASTNAME + ' ' + @FIRSTNAME + ' ' + @SURNAME;

SELECT @LONGNAME [ПОЛНОЕ ИМЯ] ,@SHORTNAME [СОКРАЩЕННОЕ ИМЯ];
-----------------------------------
USE UNIVER;
SELECT STUDENT.NAME, STUDENT.BDAY, (DATEDIFF(YY, STUDENT.BDAY, SYSDATETIME())) AS ВОЗРАСТ
FROM STUDENT
WHERE MONTH(STUDENT.BDAY) = MONTH(SYSDATETIME()) + 1;
----------------------------------
DECLARE @GROUPNUMBER INT = 4;

SELECT DISTINCT PROGRESS.PDATE[ДАТА ПРОХОЖДЕНИЯ ЭКЗАМЕНА], CASE
WHEN DATEPART(DW,PROGRESS.PDATE) = 1 THEN 'ПОНЕДЕЛЬНИК'
WHEN DATEPART(DW,PROGRESS.PDATE) = 2 THEN 'ВТОРНИК'
WHEN DATEPART(DW,PROGRESS.PDATE) = 3 THEN 'СРЕДА'
WHEN DATEPART(DW,PROGRESS.PDATE) = 4 THEN 'ЧЕТВЕРГ'
WHEN DATEPART(DW,PROGRESS.PDATE) = 5 THEN 'ПЯТНИЦА'
WHEN DATEPART(DW,PROGRESS.PDATE) = 6 THEN 'СУББОТА'
WHEN DATEPART(DW,PROGRESS.PDATE) = 7 THEN 'ВОСКРЕСЕНЬЕ'
END [ДЕНЬ НЕДЕЛИ]
FROM GROUPS INNER JOIN STUDENT ON STUDENT.IDGROUP = GROUPS.IDGROUP
INNER JOIN PROGRESS ON STUDENT.IDSTUDENT= PROGRESS.IDSTUDENT
WHERE GROUPS.IDGROUP = @GROUPNUMBER AND PROGRESS.SUBJECT = 'СУБД'
