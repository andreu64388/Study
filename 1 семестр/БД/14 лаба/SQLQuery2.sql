/*2. янгдюрэ AFTER-рпхццеп я хлемел TR_TEACHER_DEL дкъ рюакхжш TEA-CHER, пеюцхпсчыхи мю янашрхе 
DELETE. рпхццеп днкфем гюохяшбюрэ ярпнйс дюммшу б рюакхжс TR_AUDIT дкъ йюфдни сдюкъелни ярпнйх. 
б ярнкаеж яя онлеыючряъ гмювемхъ ярнкажю
TEACHER сдюкъелни ярпнйх. 
*/


--------------------------------------------
------------------UNIVER--------------------
--------------------------------------------

USE UNIVER
GO

    CREATE TRIGGER TR_TEACHER_DEL
      ON TEACHER AFTER DELETE
      AS
      DECLARE @A1 CHAR(10), @A2 VARCHAR(100), @A3 CHAR(1), @A4 CHAR(20), @IN VARCHAR(300);
      PRINT 'сдюкемхе';
      SET @A1 = (SELECT TEACHER FROM DELETED);
      SET @A2= (SELECT TEACHER_NAME FROM DELETED);
      SET @A3= (SELECT GENDER FROM DELETED);
	  SET @A4 = (SELECT PULPIT FROM DELETED);
      SET @IN = @A1+' '+ @A2 +' '+ @A3+ ' ' +@A4;
      INSERT INTO TR_AUDIT(STMT, TRNAME, CC)
                            VALUES('DEL', 'TR_TEACHER_DEL', @IN);
      RETURN;
      GO

	  DELETE TEACHER WHERE TEACHER='йпюб'
	  SELECT * FROM TR_AUDIT



--------------------------------------------
--------------------BANK--------------------
--------------------------------------------


USE BANK
GO

    CREATE TRIGGER TR_BANK_DEL
      ON аюмй AFTER DELETE
      AS
     DECLARE @A1 INT, @A2 VARCHAR(100), @A3 INT , @IN VARCHAR(300);
      PRINT 'сдюкемхе';
      SET @A1 = (SELECT ID FROM INSERTED);
      SET @A2= (SELECT мюгююмхе_йпедхрю FROM INSERTED);
      SET @A3= (SELECT ярюбйю FROM INSERTED);
      SET @IN = CAST(@A1 AS NVARCHAR)+' '+ @A2 +' '+  CAST(@A3 AS NVARCHAR);
      INSERT INTO TR_BANK(STMT, TRNAME, CC)
      VALUES('DEL', 'TR_BANK_DEL', @IN);
      RETURN;
      GO

	  DELETE FROM аюмй
WHERE ID = 6

	  SELECT * FROM TR_BANK
