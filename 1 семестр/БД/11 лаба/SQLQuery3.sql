/*3. Разработать сценарий, демонстрирующий применение оператора SAVE TRAN на примере базы данных X_UNIVER. 
В блоке CATCH предусмотреть выдачу соответствующих сообщений об ошибках. 
Опробовать работу сценария при использовании различных контрольных точек и различных операторов модификации таблиц.
*/
USE UNIVER;
DECLARE @POINT VARCHAR(32);

BEGIN TRY
	BEGIN TRAN                           
		SET @POINT = 'P1'; 
		SAVE TRAN @POINT; 
		INSERT PULPIT VALUES
		       
			   ('ТТ', ' Тест тестирует', 'ТОВ')
  
		SET @POINT = 'P2'; 
		SAVE TRAN @POINT; 
		INSERT PULPIT VALUES
		       ('НТ', 'НЕТ ИДЕЙ', 'ИТ'); 
	COMMIT TRAN;                                              
END TRY

BEGIN CATCH
	PRINT 'ERROR: '+ CASE 
		WHEN ERROR_NUMBER() = 2627 AND PATINDEX('%PULPIT_PK%', ERROR_MESSAGE()) > 0 
		THEN 'ER' 
		ELSE 'OTHER ERROR:: '+ CAST(ERROR_NUMBER() AS  VARCHAR(5)) + ERROR_MESSAGE()  
	END; 


    IF @@TRANCOUNT > 0
	BEGIN
	   PRINT 'КОНТРОЛЬНАЯ ТОЧКА: '+ @POINT;
	   ROLLBACK TRAN @POINT; 
	   COMMIT TRAN; 
	END;     
END CATCH;

SELECT * FROM PULPIT; 

-------------------------------------------------------------
--------------------------BANK-------------------------------
-------------------------------------------------------------
USE BANK;
DECLARE @POINT_ VARCHAR(32);

BEGIN TRY
	BEGIN TRAN                           
		SET @POINT_ = 'P1'; 
		SAVE TRAN @POINT_; 
	    INSERT INTO БАНК (id,Назаание_кредита,Ставка) VALUES (4, 'БЫСТРЫЙ',1212);
		SET @POINT_ = 'P2'; 
		SAVE TRAN @POINT_; 
	    INSERT INTO БАНК (id,Назаание_кредита,Ставка) VALUES (3, 'БЫСТРЫЙ',1212);
	COMMIT TRAN;                                              
END TRY

BEGIN CATCH
	PRINT 'ERROR: '+ CASE 
		WHEN ERROR_NUMBER() = 2627 AND PATINDEX('%PK_БАНК', ERROR_MESSAGE()) > 0 
		THEN 'ER' 
		ELSE 'OTHER ERROR:: '+ CAST(ERROR_NUMBER() AS  VARCHAR(5)) + ERROR_MESSAGE()  
	END; 


    IF @@TRANCOUNT > 0
	BEGIN
	   PRINT 'КОНТРОЛЬНАЯ ТОЧКА: '+ @POINT_;
	   ROLLBACK TRAN @POINT_; 
	   COMMIT TRAN; 
	END;     
END CATCH;

