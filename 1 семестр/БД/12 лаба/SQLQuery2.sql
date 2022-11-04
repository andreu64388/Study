/*2. Найти процедуру PSUBJECT с помощью обо-зревателя объектов (Object Explorer) 
SSMS и через контекстное меню создать сценарий на изменение про-цедуры оператором ALTER.
Изменить процедуру PSUBJECT, созданную в за-дании 1, таким образом, чтобы она принимала 
два па-раметра с именами @p и @c. Параметр @p является входным, имеет тип VARCHAR(20) и
значение по умолчанию NULL. Параметр @с является выходным, имеет тип INT.
Процедура PSUBJECT должна формировать ре-зультирующий набор, аналогичный набору,
представ-ленному на рисунке выше, но при этом содержать строки, соответствующие коду кафедры
, заданному параметром @p. Кроме того, процедура должна фор-мировать значение выходного параметра @с, 
равное количеству строк в результирующем наборе, а также возвращать значение к точке вызова,
равное общему количеству дисциплин (количеству строк в таблице SUBJECT). 
*/

USE UNIVER;

SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE PSUBJECT @P VARCHAR(20) = NULL, @C INT OUTPUT
AS
BEGIN
DECLARE @K INT = (SELECT COUNT(*) FROM SUBJECT WHERE PULPIT = @P);
PRINT 'ПАРАМЕТРЫ: @P = ' + @P + ', @C = ' + CAST(@C AS VARCHAR(3));
SELECT SUBJECT [КОД], SUBJECT_NAME [ДИСЦИПЛИНА], PULPIT [КАФЕДРА] FROM SUBJECT WHERE PULPIT = @P;
SET @C = @@ROWCOUNT;
RETURN @K;
END;

DECLARE @Y INT = 0, @Z VARCHAR(20) = 'ИСИТ', @W INT = 0
EXEC @Y = PSUBJECT @P = @Z, @C = @W OUTPUT
PRINT 'ВСЕГО СТРОК: ' + CAST(@Y AS NVARCHAR)
PRINT 'СТРОК С ФАКУЛЬТЕТОМ ' + @Z + ': '+ CAST(@W AS NVARCHAR)