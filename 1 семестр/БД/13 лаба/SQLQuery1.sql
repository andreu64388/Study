/*1. Разработать скалярную функцию с именем COUNT_STUDENTS, которая вычисляет количество сту-дентов на факультет
е, код которого задается параметром типа VARCHAR(20) с именем @faculty. Использовать внутреннее соединение таблиц 
FACULTY, GROUPS, STU-DENT. Опробовать работу функции.
Внести изменения в текст функции с помощью оператора ALTER с тем, чтобы функция принимала второй параметр @prof
типа VARCHAR(20), обозначающий специальность студентов. Для параметров определить значения по умолча-нию NULL.
Опробовать работу функции с помощью SE-LECT-запросов.
*/
USE UNIVER;
CREATE FUNCTION COUNT_STUDENTS (@FACULTY NVARCHAR(20)) RETURNS INT AS
BEGIN
DECLARE @COUNT INT=0;
SET @COUNT=(SELECT COUNT(STUDENT.IDSTUDENT)
FROM FACULTY
INNER JOIN GROUPS ON GROUPS.FACULTY = FACULTY.FACULTY
INNER JOIN STUDENT ON STUDENT.IDGROUP = GROUPS.IDGROUP
WHERE FACULTY.FACULTY = @FACULTY)
RETURN @COUNT;
END;
GO
--DROP FUNCTION COUNT_STUDENTS;

DECLARE @TEMP_1 INT = DBO.COUNT_STUDENTS('ИДИП');
PRINT 'КОЛИЧЕСТВО СТУДЕНТОВ НА ФАКУЛЬТЕТЕ ' +CAST(@TEMP_1 AS NVARCHAR(20))+ ' ЧЕЛОВЕК.';

SELECT FACULTY 'ФАКУЛЬТЕТ',
DBO.COUNT_STUDENTS(FACULTY) 'КОЛ-ВО СТУДЕНТОВ'
FROM FACULTY
GO

-- ВНЕСТИ ИЗМЕНЕНИЯ В ТЕКСТ ФУНКЦИИ С ПОМОЩЬЮ ОПЕРАТОРА ALTER С ТЕМ, ЧТОБЫ ФУНКЦИЯ ПРИНИМАЛА ВТОРОЙ ПАРАМЕТР @PROF:
ALTER FUNCTION COUNT_STUDENTS (@FACULTY NVARCHAR(20), @PROF NVARCHAR(20)) RETURNS INT AS
BEGIN
DECLARE @COUNT INT=0;
SET @COUNT=(SELECT COUNT(STUDENT.IDSTUDENT)
FROM FACULTY
INNER JOIN GROUPS ON GROUPS.FACULTY = FACULTY.FACULTY
INNER JOIN STUDENT ON STUDENT.IDGROUP = GROUPS.IDGROUP
WHERE FACULTY.FACULTY = @FACULTY AND GROUPS.PROFESSION = @PROF)
RETURN @COUNT;
END;
GO

DECLARE @TEMP_1 INT = DBO.COUNT_STUDENTS('ИДИП', '1-40 01 02');
PRINT 'КОЛИЧЕСТВО СТУДЕНТОВ: ' + CONVERT(VARCHAR, @TEMP_1);

SELECT FACULTY.FACULTY 'ФАКУЛЬТЕТ',
GROUPS.PROFESSION 'СПЕЦИАЛЬНОСТЬ',
DBO.COUNT_STUDENTS(FACULTY.FACULTY, GROUPS.PROFESSION) 'КОЛ-ВО СТУДЕНТОВ'
FROM FACULTY
INNER JOIN GROUPS ON GROUPS.FACULTY = FACULTY.FACULTY
GROUP BY FACULTY.FACULTY, GROUPS.PROFESSION
GO