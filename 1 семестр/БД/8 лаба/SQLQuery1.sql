/*1. Разработать T-SQL-скрипт, в котором: 
 объявить переменные типа char, varchar, datetime, time, int, smallint, tinint, numeric(12, 5); 
 первые две переменные проинициализировать в операторе объявления;
 присвоить произвольные значения следующим двум переменным с помощью оператора SET, одной из этих переменных присвоить значение, полученное в результате запроса SELECT; 
 одну из переменных оставить без инициализации и не присваивать ей значения, оставшимся переменным присвоить некоторые значения с помощью оператора SELECT; 
 значения одной половины переменных вывести с помощью оператора SELECT, значения другой половины переменных распечатать с помощью оператора PRINT. 
Проанализировать результаты.
*/
DECLARE @A CHAR = 'А',
@B VARCHAR(3) = 'ФИТ',
@C DATETIME,
@D TIME,
@E INT,
@F SMALLINT,
@G TINYINT,
@H NUMERIC(12,5);

	
SET @D = (SELECT CONVERT(VARCHAR(12), GETDATE(), 114) 'hh:mi:ss:mmm');

SELECT @E = 21122001, @F = 21, @G = 1;

SELECT @A СИМВОЛ, @B СТРОКА, @C ДАТА;

PRINT 'ВРЕМЯ = ' + CAST(@D AS NVARCHAR);
PRINT 'INT = ' + CONVERT(NVARCHAR, @E);
PRINT 'SMALLINT = ' + CONVERT(NVARCHAR, @F);
PRINT 'TINYINT = ' + CONVERT(NVARCHAR, @G);
PRINT 'NUMERIC = ' + CONVERT(NVARCHAR, @H);