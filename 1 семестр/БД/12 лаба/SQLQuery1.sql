/*1. Разработать хранимую процедуру без параметров с именем PSUBJECT.
Процедура формирует результи-рующий набор на основе таблицы SUBJECT, анало-гичный набору,
представленному на рисунке: 
К точке вызова процедура должна возвращать ко-личество строк, выведенных в результирующий набор.
*/

------------------------------------------------
----------------------UNVER---------------------
------------------------------------------------
USE UNIVER;
GO
CREATE PROCEDURE PSUBJECT
AS
BEGIN
DECLARE @K INT=(SELECT COUNT(*) FROM SUBJECT);
SELECT SUBJECT [КОД], SUBJECT_NAME [ДИСЦИПЛИНА], PULPIT [КАФЕДРА] FROM SUBJECT;
RETURN @K;
END;

EXEC @N = PSUBJECT;

DECLARE @I INT=0;
EXEC @I=PSUBJECT;
PRINT 'КОЛИЧЕСТВО ПРЕДМЕТОВ: '+CAST(@I AS VARCHAR(3));

--DROP PROCEDURE PSUBJECT;

------------------------------------------------
----------------------BANK----------------------
------------------------------------------------
USE BANK;
GO 
CREATE PROCEDURE PBANK 
 AS 
 BEGIN 
   DECLARE @COUNTS_ INT = (SELECT COUNT(*) FROM Клиент)
   SELECT * FROM Клиент
   RETURN @COUNTS_
 END
 

DECLARE @T INT;
EXEC @T= PBANK
PRINT @T
--DROP PROCEDURE PBANK;
