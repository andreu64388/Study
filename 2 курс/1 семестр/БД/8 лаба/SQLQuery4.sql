/*4. Разработать T-SQL-скрипты, вы-полняющие: 
 вычисление значений переменной 
для различных значений исходных дан-ных;
 преобразование полного ФИО сту-дента в сокращенное (например, Коренчук А.В);
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
-------------------------------------------
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

-------------------------------------------

USE UNIVER;
SELECT STUDENT.NAME, STUDENT.BDAY, DATEDIFF(YEAR, STUDENT.BDAY, SYSDATETIME()) AS ВОЗРАСТ
FROM STUDENT
WHERE MONTH(STUDENT.BDAY) = MONTH(SYSDATETIME()) + 1;

PRINT SYSDATETIME()
SELECT STUDENT.BDAY FROM STUDENT
-------------------------------------------

DECLARE @GROUPNUMBER INT = 4;
SELECT STUDENT.NAME, DATENAME(dw, PROGRESS.PDATE) [День недели]
FROM STUDENT 
JOIN PROGRESS ON PROGRESS.IDSTUDENT = STUDENT.IDSTUDENT
JOIN  GROUPS ON STUDENT.IDGROUP = GROUPS.IDGROUP
WHERE GROUPS.IDGROUP = @GROUPNUMBER AND  PROGRESS.SUBJECT = 'СУБД';