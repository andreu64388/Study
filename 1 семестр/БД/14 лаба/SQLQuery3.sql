/*3. Создать AFTER-триггер с именем TR_TEACHER_UPD для таблицы 
TEA-CHER, реагирующий на событие UPDATE. Триггер должен записывать строку данных в таблицу 
TR_AUDIT для каждой изменяемой строки. В столбец СС помещаются значения столбцов изменяемой строки 
до и после изме-нения.*/

USE UNIVER
GO
    CREATE  TRIGGER TR_TEACHER_UPD
      ON TEACHER AFTER UPDATE
      AS
      DECLARE @A1 CHAR(10), @A2 VARCHAR(100), @A3 CHAR(1), @A4 CHAR(20), @IN VARCHAR(300);
	  DECLARE @INS INT = (SELECT COUNT(*) FROM INSERTED)
      PRINT 'ОБНОВЛЕНИЕ';
      SET @A1 = (SELECT TEACHER FROM INSERTED);
      SET @A2= (SELECT TEACHER_NAME FROM INSERTED);
      SET @A3= (SELECT GENDER FROM INSERTED);
	  SET @A4 = (SELECT PULPIT FROM INSERTED);
      SET @IN = @A1+' '+ @A2 +' '+ @A3+ ' ' +@A4;
      INSERT INTO TR_AUDIT(STMT, TRNAME, CC)
                            VALUES('UPD', 'TR_TEACHER_UPD', @IN);
      RETURN;
      GO

	  UPDATE TEACHER SET GENDER = 'ж' WHERE TEACHER='КРАВ'
	  SELECT * FROM TR_AUDIT

	  DELETE FROM TR_AUDIT WHERE STMT = 'UPD'