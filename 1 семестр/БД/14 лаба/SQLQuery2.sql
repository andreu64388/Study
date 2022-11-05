/*2. Создать AFTER-триггер с именем TR_TEACHER_DEL для таблицы TEA-CHER, реагирующий на событие 
DELETE. Триггер должен записывать строку данных в таблицу TR_AUDIT для каждой удаляемой строки. 
В столбец СС помещаются значения столбца
TEACHER удаляемой строки. 
*/
USE UNIVER
GO

    CREATE  TRIGGER TR_TEACHER_DEL
      ON TEACHER AFTER DELETE
      AS
      DECLARE @A1 CHAR(10), @A2 VARCHAR(100), @A3 CHAR(1), @A4 CHAR(20), @IN VARCHAR(300);
      PRINT 'УДАЛЕНИЕ';
      SET @A1 = (SELECT TEACHER FROM DELETED);
      SET @A2= (SELECT TEACHER_NAME FROM DELETED);
      SET @A3= (SELECT GENDER FROM DELETED);
	  SET @A4 = (SELECT PULPIT FROM DELETED);
      SET @IN = @A1+' '+ @A2 +' '+ @A3+ ' ' +@A4;
      INSERT INTO TR_AUDIT(STMT, TRNAME, CC)
                            VALUES('DEL', 'TR_TEACHER_DEL', @IN);
      RETURN;
      GO

	   DELETE TEACHER WHERE TEACHER='КРАВ'
	  SELECT * FROM TR_AUDIT