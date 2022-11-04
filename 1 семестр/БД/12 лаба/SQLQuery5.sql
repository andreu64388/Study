/*
5. Разработать процедуру с именем SUB-JECT_REPORT, формирующую в стандартный вы-ходной поток отчет со списком дисциплин на кон-кретной кафедре. В отчет должны быть выведены краткие названия (поле SUBJECT) из таблицы SUBJECT в одну строку через запятую (использовать встроенную функцию RTRIM). Процедура имеет входной параметр с именем @p типа CHAR(10), кото-рый предназначен для указания кода кафедры.
В том случае, если по заданному значению @p не-возможно определить код кафедры, процедура должна генерировать ошибку с сообщением ошибка в пара-метрах. 
Процедура SUBJECT_REPORT должна возвра-щать к точке вызова количество дисциплин, отобра-женных в отчете. 
*/
USE UNIVER;

CREATE PROCEDURE SUBJECT_REPORT @P NVARCHAR(10) AS
BEGIN
DECLARE @COUNTER INT = 0;
BEGIN TRY
DECLARE @SUB NVARCHAR(10), @LINE_SUB NVARCHAR(500) = ''
DECLARE SUBJECTS CURSOR LOCAL STATIC FOR
SELECT SUBJECT FROM SUBJECT WHERE PULPIT = @P ORDER BY PULPIT
IF NOT EXISTS (SELECT PULPIT FROM SUBJECT WHERE PULPIT = @P)
BEGIN
RAISERROR('ОШИБКА, НЕТ ТАКИХ КАФЕДР', 11, 1);
END
ELSE
BEGIN
OPEN SUBJECTS
FETCH SUBJECTS INTO @SUB
SET @LINE_SUB = TRIM(@SUB)
SET @COUNTER +=1
FETCH SUBJECTS INTO @SUB
WHILE @@FETCH_STATUS = 0
BEGIN
SET @LINE_SUB = '' + TRIM(@SUB) + ', ' + @LINE_SUB
SET @COUNTER +=1
FETCH SUBJECTS INTO @SUB
END
PRINT 'ПРЕДМЕТЫ НА КАФЕДРЕ ' + @P + ': ' + @LINE_SUB
RETURN @COUNTER
END
END TRY
BEGIN CATCH
PRINT 'ОШИБКА В ПАРАМЕТРАХ'
IF ERROR_PROCEDURE() IS NOT NULL
PRINT 'ИМЯ ПРОЦЕДУРЫ : ' + ERROR_PROCEDURE()
RETURN @COUNTER
END CATCH
END
GO

DECLARE @C INT
EXEC @C = SUBJECT_REPORT @P = 'ИСИТ'
PRINT 'КОЛИЧЕСТВО ПРЕДМЕТОВ НА СПЕЦИАЛЬНОСТИ: ' + CAST(@C AS NVARCHAR)

DROP PROCEDURE SUBJECT_REPORT;