/*1. Разработать хранимую процедуру без параметров с именем PSUBJECT.
Процедура формирует результи-рующий набор на основе таблицы SUBJECT, анало-гичный набору,
представленному на рисунке: 
К точке вызова процедура должна возвращать ко-личество строк, выведенных в результирующий набор.
*/
USE UNIVER;


CREATE PROCEDURE PSUBJECT
AS
BEGIN
DECLARE @K INT = (SELECT COUNT(*) FROM SUBJECT);
SELECT SUBJECT [КОД], SUBJECT_NAME [ДИСЦИПЛИНА], PULPIT [КАФЕДРА] FROM SUBJECT;
RETURN @K;
END;

DECLARE @Y INT = 0;
EXEC @Y = PSUBJECT;
PRINT('КОЛИЧЕСТВО СТРОК = ') + CAST(@Y AS VARCHAR(3));

DROP PROCEDURE PSUBJECT;