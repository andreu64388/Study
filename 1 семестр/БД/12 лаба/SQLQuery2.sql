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
------------------------------------------------
----------------------UNVER---------------------
------------------------------------------------
USE UNIVER;
GO
ALTER PROCEDURE PSUBJECT @P VARCHAR(20) = NULL, @C INT OUTPUT
 AS
   BEGIN
 SELECT * FROM SUBJECT WHERE SUBJECT.SUBJECT = @P;
 SET @C = @@ROWCOUNT;
 DECLARE @K INT = (SELECT COUNT(*) FROM SUBJECT);
 PRINT 'ПАРАМЕТРЫ: @P='+@P+', @C='+CAST(@C AS VARCHAR(3));
 RETURN @K;
   END

DECLARE @N INT, @A INT,@X NVARCHAR(20);
EXEC @N = PSUBJECT 'ООП', @A OUTPUT ;
PRINT CAST(@A AS NVARCHAR(4))
PRINT CAST(@N AS NVARCHAR(4))

------------------------------------------------
----------------------BANK----------------------
------------------------------------------------
USE BANK;
GO
ALTER PROCEDURE PBANK @ID INT, @C_ INT OUTPUT
 AS
   BEGIN
SELECT * FROM КРЕДИТ WHERE ID_CLIENT = @ID;
 SET @C_ = @@ROWCOUNT;
 DECLARE @K_ INT = (SELECT COUNT(*) FROM КЛИЕНТ);
 RETURN @K_;
   END

DECLARE @N INT, @A INT,@X NVARCHAR(20);
EXEC @N = PBANK 10, @A OUTPUT ;
PRINT CAST(@A AS NVARCHAR(4))
PRINT CAST(@N AS NVARCHAR(4))