/*
5. Разработать процедуру с именем SUB-JECT_REPORT, формирующую в стандартный вы-ходной поток отчет со списком дисциплин на кон-кретной кафедре. В отчет должны быть выведены краткие названия (поле SUBJECT) из таблицы SUBJECT в одну строку через запятую (использовать встроенную функцию RTRIM). Процедура имеет входной параметр с именем @p типа CHAR(10), кото-рый предназначен для указания кода кафедры.
В том случае, если по заданному значению @p не-возможно определить код кафедры, процедура должна генерировать ошибку с сообщением ошибка в пара-метрах. 
Процедура SUBJECT_REPORT должна возвра-щать к точке вызова количество дисциплин, отобра-женных в отчете. 
*/
------------------------------------------------
----------------------UNVER---------------------
------------------------------------------------
USE UNIVER;
GO
CREATE PROCEDURE SUBJECT_REPORT @P CHAR(10)
  AS DECLARE @RC INT = 0;
	BEGIN TRY
		IF NOT EXISTS (SELECT SUBJECT FROM SUBJECT WHERE PULPIT = @P)
			RAISERROR('ОШИБКА В ПАРАМЕТРАХ', 11, 1);
		DECLARE @SUBS_LIST CHAR(300) = '', @SUB CHAR(10);
		DECLARE SUBJECTS_LAB12 CURSOR FOR
			SELECT SUBJECT FROM SUBJECT WHERE PULPIT = @P;
		OPEN SUBJECTS_LAB12;
			FETCH SUBJECTS_LAB12 INTO @SUB;
			WHILE (@@FETCH_STATUS = 0)
				BEGIN
					SET @SUBS_LIST = RTRIM(@SUB) + ', ' + @SUBS_LIST;
					SET @RC += 1;		
					FETCH SUBJECTS_LAB12 INTO @SUB;
				END;
			PRINT 'ДИСЦИПЛИНЫ НА КАФЕДРЕ ' + RTRIM(@P) + ':';
			PRINT RTRIM(@SUBS_LIST);
		CLOSE SUBJECTS_LAB12;
		DEALLOCATE SUBJECTS_LAB12;
		RETURN @RC;
	END TRY
	BEGIN CATCH
		PRINT 'НОМЕР ОШИБКИ: ' + CONVERT(VARCHAR, ERROR_NUMBER());
		PRINT 'СООБЩЕНИЕ: ' + ERROR_MESSAGE();
		PRINT 'УРОВЕНЬ: ' + CONVERT(VARCHAR, ERROR_SEVERITY());
		PRINT 'МЕТКА: ' + CONVERT(VARCHAR, ERROR_STATE());
		PRINT 'НОМЕР СТРОКИ: ' + CONVERT(VARCHAR, ERROR_LINE());
		IF ERROR_PROCEDURE() IS NOT NULL
			PRINT 'ИМЯ ПРОЦЕДУРЫ: ' + ERROR_PROCEDURE();
		RETURN @RC;
	END CATCH;
GO

DECLARE @TEMP_5 INT;
EXEC @TEMP_5 = SUBJECT_REPORT 'ИСИТ';
PRINT 'КОЛИЧЕСТВО ДИСЦИПЛИН: ' + CONVERT(VARCHAR, @TEMP_5);


--DROP PROCEDURE SUBJECT_REPORT
