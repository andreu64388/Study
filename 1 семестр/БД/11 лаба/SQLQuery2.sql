/*2. Разработать сценарий, демонстрирующий свойство атомарности явной транзакции на примере базы данных X_UNIVER. 
В блоке CATCH предусмотреть выдачу соответствующих сообщений об ошибках. 
Опробовать работу сценария при использовании различных операторов модификации таблиц.
*/
USE UNIVER;
BEGIN TRY        
	BEGIN TRAN                 
		INSERT AUDITORIUM VALUES ('2', 'ЛБ-К', '15', '206-1');
	    INSERT AUDITORIUM VALUES ('206-1', 'ЛК', '30', '206-1');
	COMMIT TRAN;               
END TRY

BEGIN CATCH
	PRINT 'ERROR: '+ CASE 
		WHEN ERROR_NUMBER() = 2627 AND PATINDEX('%AUDITORIUM_PK%', ERROR_MESSAGE()) > 0 
		THEN 'ERROR'	
		ELSE 'OTHER ERROR: '+ CAST(ERROR_NUMBER() AS  VARCHAR(5))+ ERROR_MESSAGE()  
	END;
	IF @@TRANCOUNT > 0 ROLLBACK TRAN; 	  
END CATCH;

SELECT * FROM AUDITORIUM;


-------------------------------------------------------------
--------------------------BANK-------------------------------
-------------------------------------------------------------
USE BANK;

BEGIN TRY        
	BEGIN TRAN                 
		INSERT INTO БАНК (id,Назаание_кредита,Ставка) VALUES (4, 'БЫСТРЫЙ',1212);
	    INSERT INTO БАНК (id,Назаание_кредита,Ставка) VALUES (5, 'МЕДЛЕННЫЙ',12);
	COMMIT TRAN;               
END TRY

BEGIN CATCH
	PRINT 'ERROR: '+ CASE 
		WHEN ERROR_NUMBER() = 2627 AND PATINDEX('%БАНК_PK%', ERROR_MESSAGE()) > 0
		THEN 'ERRORS'	
		ELSE 'OTHER ERROR: '+ CAST(ERROR_NUMBER() AS  VARCHAR(5))+ ERROR_MESSAGE()  
	END;
	IF @@TRANCOUNT > 0 ROLLBACK TRAN; 	  
END CATCH;

SELECT* FROM БАНК