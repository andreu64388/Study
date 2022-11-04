/*
4. На рисунке ниже показан сценарий, демонстрирующий работу скалярной функции FCTEACHER.
Функция прини-мает один параметр, задающий код кафедры. Функция воз-вращает количество преподавателей
на заданной парамет-ром кафедре.
Если параметр равен NULL, то возвращается общее количество преподавателей. */
USE UNIVER;
CREATE FUNCTION FCTEACHER(@PUL NVARCHAR(10)) RETURNS INT AS
    BEGIN
        DECLARE @COUNT INT=(SELECT COUNT(*) FROM TEACHER
        WHERE PULPIT=ISNULL(@PUL, PULPIT));
        RETURN @COUNT;
    END;
GO
-- DROP FUNCTION FCTEACHER;

-- ОБРАЩЕНИЕ К ФУНКЦИИ:
SELECT PULPIT, DBO.FCTEACHER(PULPIT) [КОЛИЧЕСТВО ПРЕПОДАВАТЕЛЕЙ] FROM PULPIT;

SELECT DBO.FCTEACHER(NULL) [ВСЕГО ПРЕПОДАВАТЕЛЕЙ];