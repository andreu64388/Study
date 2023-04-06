/*2. Разработать скалярную функцию с именем FSUB-JECTS, принимающую параметр @p типа VARCHAR(20), значение которого задает код кафедры (столбец SUB-JECT.PULPIT). 
Функция должна возвращать строку типа VARCHAR(300) с перечнем дисциплин в отчете. 
Создать и выполнить сценарий, который создает отчет, аналогичный представленному ниже. 
Примечание: использовать локальный статический курсор на основе SELECT-запроса к таблице SUBJECT.
*/


 ---------------------------------------
 ---------------UNIVER------------------
 ---------------------------------------
USE UNIVER;
GO
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
-- DROP FUNCTION FBANK;

PRINT DBO.FSUBJECTS('ИСИТ');
SELECT PULPIT 'КАФЕДРА', DBO.FSUBJECTS(PULPIT) 'ДИСЦИПЛИНЫ' FROM PULPIT;
GO

-------------------------------------------------
-----------------------BANK----------------------
-------------------------------------------------

USE BANK;
GO

SELECT  * FROM БАНК

CREATE FUNCTION FBANK (@P INT) RETURNS NVARCHAR(300) AS
BEGIN
    DECLARE @LIST VARCHAR(300) = '', @NAME VARCHAR(20);
    DECLARE NAME_CURSOR CURSOR LOCAL FOR
	SELECT  БАНК.НАЗААНИЕ_КРЕДИТА FROM БАНК
	WHERE БАНК.ID = @P
    OPEN NAME_CURSOR
    FETCH NEXT FROM NAME_CURSOR INTO @NAME
    WHILE @@FETCH_STATUS = 0
        BEGIN
            SET @LIST=@LIST+RTRIM(@NAME)+', ';
            FETCH NAME_CURSOR INTO @NAME
        END;
    RETURN @LIST;
END;
-- DROP FUNCTION FBANK;

PRINT DBO.FBANK(1);
SELECT БАНК.НАЗААНИЕ_КРЕДИТА,БАНК.СТАВКА, DBO.FBANK(БАНК.ID) FROM БАНК
