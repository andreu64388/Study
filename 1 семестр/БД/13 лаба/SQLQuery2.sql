/*2. Разработать скалярную функцию с именем FSUB-JECTS, принимающую параметр @p типа VARCHAR(20), значение которого задает код кафедры (столбец SUB-JECT.PULPIT). 
Функция должна возвращать строку типа VARCHAR(300) с перечнем дисциплин в отчете. 


Создать и выполнить сценарий, который создает отчет, аналогичный представленному ниже. 
Примечание: использовать локальный статический курсор на основе SELECT-запроса к таблице SUBJECT.
*/


USE UNIVER;
CREATE FUNCTION FSUBJECTS (@P NVARCHAR(20)) RETURNS NVARCHAR(300) AS
BEGIN
DECLARE @LIST VARCHAR(300) = 'ДИСЦИПЛИНЫ: ', @SUB VARCHAR(20);
DECLARE SUBJECT_CURSOR CURSOR LOCAL FOR
SELECT SUBJECT.SUBJECT 'ДИСЦИПЛИНА'
FROM SUBJECT
WHERE SUBJECT.PULPIT = @P
OPEN SUBJECT_CURSOR
FETCH NEXT FROM SUBJECT_CURSOR INTO @SUB
WHILE @@FETCH_STATUS = 0
BEGIN
SET @LIST=@LIST+RTRIM(@SUB)+', ';
FETCH SUBJECT_CURSOR INTO @SUB
END;
RETURN @LIST;
END;
-- DROP FUNCTION FSUBJECTS;

PRINT DBO.FSUBJECTS('ИСИТ');
-- ОБРАЩЕНИЕ К ФУНКЦИИ:
SELECT PULPIT 'КАФЕДРА', DBO.FSUBJECTS(PULPIT) 'ДИСЦИПЛИНЫ' FROM PULPIT;