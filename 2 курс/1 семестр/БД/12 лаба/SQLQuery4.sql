/*4. Разработать процедуру с именем PAUDITORI-UM_INSERT. Процедура принимает четыре входных параметра: @a, @n, @c и @t. Параметр @a имеет тип CHAR(20), параметр @n имеет тип VARCHAR(50), параметр @c имеет тип INT и значение по умолчанию 0, параметр @t имеет тип CHAR(10).
Процедура добавляет строку в таблицу AUDITO-RIUM. Значения столбцов AUDITORIUM, AUDI-TORIUM_NAME, AUDITORIUM_CAPACITY и AUDITORIUM_TYPE добавляемой строки задаются соответственно параметрами @a, @n, @c и @t.
Процедура PAUDITORIUM_INSERT должна при-менять механизм TRY/CATCH для обработки ошибок. В случае возникновения ошибки, процедура должна формировать сообщение, содержащее код ошибки, уровень серьезности и текст сообщения в стандартный выходной поток. 
Процедура должна возвращать к точке вызова зна-чение -1 в том случае, если произошла ошибка и 1, ес-ли выполнение успешно. 
Опробовать работу процедуры с различными значе-ниями исходных данных, которые вставляются в таб-лицу.
*/
------------------------------------------------
----------------------UNVER---------------------
------------------------------------------------
USE UNIVER;
GO

CREATE PROCEDURE PAUDITORIUM_INSERT @A CHAR(20), @N VARCHAR(50), @C INT = 0, @T CHAR(10)
AS 
 BEGIN 
   BEGIN TRY
	INSERT INTO AUDITORIUM(AUDITORIUM, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY, AUDITORIUM_NAME)
		VALUES(@A, @N, @C, @T);
	RETURN 1;
  END TRY
  BEGIN CATCH
	PRINT 'NUM: ' + CAST(ERROR_NUMBER() AS VARCHAR(6));
	PRINT 'MESSAGE: ' + ERROR_MESSAGE();
	PRINT 'SEVERITY: ' + CAST(ERROR_SEVERITY() AS VARCHAR(6));
	PRINT 'STATE: ' + CAST(ERROR_STATE() AS VARCHAR(8));
	PRINT 'ERROR LINE: ' + CAST(ERROR_LINE() AS VARCHAR(8));
	IF ERROR_PROCEDURE() IS NOT NULL   
	PRINT 'IN WHAT PROC: ' + ERROR_PROCEDURE();
	RETURN -1;
  END CATCH;
END;


DECLARE @RC INT;  
EXEC @RC = PAUDITORIUM_INSERT @A = '100', @N = 'ЛК', @C = 30, @T = '100'; 
PRINT 'STATUS: ' + CAST(@RC AS VARCHAR(3));

SELECT * FROM AUDITORIUM WHERE AUDITORIUM.AUDITORIUM = '100'

DELETE AUDITORIUM WHERE AUDITORIUM='100';



------------------------------------------------
----------------------BANK----------------------
------------------------------------------------
USE BANK;
GO

CREATE PROCEDURE PBANK_INSERT @ID_CL INT,@MOBILE INT,@FACE NVARCHAR(20),@ADDRES NVARCHAR(20)
AS 
 BEGIN 
   BEGIN TRY
	INSERT INTO КЛИЕНТ(ID_CLIENT,ТЕЛЕФОН,АДРЕС,КОНТАКТОЕ_ЛИЦО)
		VALUES(@ID_CL, @MOBILE, @ADDRES, @FACE);
	RETURN 1;
  END TRY
  BEGIN CATCH
	PRINT 'NUM: ' + CAST(ERROR_NUMBER() AS VARCHAR(6));
	PRINT 'MESSAGE: ' + ERROR_MESSAGE();
	PRINT 'SEVERITY: ' + CAST(ERROR_SEVERITY() AS VARCHAR(6));
	PRINT 'STATE: ' + CAST(ERROR_STATE() AS VARCHAR(8));
	PRINT 'ERROR LINE: ' + CAST(ERROR_LINE() AS VARCHAR(8));
	IF ERROR_PROCEDURE() IS NOT NULL   
	PRINT 'IN WHAT PROC: ' + ERROR_PROCEDURE();
	RETURN -1;
  END CATCH;
END;


DECLARE @RC INT;  
EXEC @RC = PBANK_INSERT @ID_CL = 12, @MOBILE = 31, @FACE = 'NO', @ADDRES = 'FLAT'; 
PRINT 'STATUS: ' + CAST(@RC AS VARCHAR(3));

SELECT * FROM КЛИЕНТ

DELETE  КЛИЕНТ WHERE ID_CLIENT =12;

