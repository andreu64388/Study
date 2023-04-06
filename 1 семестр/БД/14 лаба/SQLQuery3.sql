/*3. янгдюрэ AFTER-рпхццеп я хлемел TR_TEACHER_UPD дкъ рюакхжш 
TEA-CHER, пеюцхпсчыхи мю янашрхе UPDATE. рпхццеп днкфем гюохяшбюрэ ярпнйс дюммшу б рюакхжс 
TR_AUDIT дкъ йюфдни хглемъелни ярпнйх. б ярнкаеж яя онлеыючряъ гмювемхъ ярнкажнб хглемъелни ярпнйх 
дн х оняке хгле-мемхъ.*/


--------------------------------------------
------------------UNIVER--------------------
--------------------------------------------
USE UNIVER
GO
    CREATE  TRIGGER TR_TEACHER_UPD
      ON TEACHER AFTER UPDATE
      AS
      DECLARE @A1 CHAR(10), @A2 VARCHAR(100), @A3 CHAR(1), @A4 CHAR(20), @IN VARCHAR(300);
	  DECLARE @INS INT = (SELECT COUNT(*) FROM INSERTED)
      PRINT 'намнбкемхе';
      SET @A1 = (SELECT TEACHER FROM INSERTED);
      SET @A2= (SELECT TEACHER_NAME FROM INSERTED);
      SET @A3= (SELECT GENDER FROM INSERTED);
	  SET @A4 = (SELECT PULPIT FROM INSERTED);
      SET @IN = @A1+' '+ @A2 +' '+ @A3+ ' ' +@A4;
      INSERT INTO TR_AUDIT(STMT, TRNAME, CC)
                            VALUES('UPD', 'TR_TEACHER_UPD', @IN);
      RETURN;
      GO

	  UPDATE TEACHER SET GENDER = 'ф' WHERE TEACHER='йпюб'
	  SELECT * FROM TR_AUDIT



--------------------------------------------
--------------------BANK--------------------
--------------------------------------------

USE BANK
GO
    CREATE  TRIGGER TR_BANK_UPD
      ON аюмй AFTER UPDATE
      AS
     DECLARE @A1 INT, @A2 VARCHAR(100), @A3 INT , @IN VARCHAR(300);
      PRINT 'намнбкемхе';
      SET @A1 = (SELECT ID FROM INSERTED);
      SET @A2= (SELECT мюгююмхе_йпедхрю FROM INSERTED);
      SET @A3= (SELECT ярюбйю FROM INSERTED);
      SET @IN = CAST(@A1 AS NVARCHAR)+' '+ @A2 +' '+  CAST(@A3 AS NVARCHAR);
      INSERT INTO TR_BANK(STMT, TRNAME, CC)
      VALUES('UPD', 'TR_BANK_UPD', @IN);
      RETURN;
      GO
	  UPDATE аюмй SET мюгююмхе_йпедхрю ='еRR'
	  WHERE аюмй.ID = 5
      SELECT * FROM TR_BANK
	  
  