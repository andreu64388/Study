/*2. Разработать сценарий, демонстрирующий свойство атомарности явной транзакции на примере базы данных X_UNIVER. 
В блоке CATCH предусмотреть выдачу соответствующих сообщений об ошибках. 
Опробовать работу сценария при использовании различных операторов модификации таблиц.
*/
USE UNIVER;
GO
BEGIN TRY
	BEGIN TRAN                 -- НАЧАЛО  ЯВНОЙ ТРАНЗАКЦИИ
		--INSERT FACULTY VALUES ('ИТ', 'ФАКУЛЬТЕТ ДРУГИХ НАУК');
	    INSERT FACULTY VALUES ('ПИМ', 'ФАКУЛЬТЕТ PRINT-ТЕХНОЛОГИЙ');
	COMMIT TRAN;               -- ФИКСАЦИЯ ТРАНЗАКЦИИ
END TRY

BEGIN CATCH
	PRINT 'ОШИБКА: '+ CASE
		WHEN ERROR_NUMBER() = 2627 AND PATINDEX('%FACULTY_PK%', ERROR_MESSAGE()) > 0 THEN 'ДУБЛИРОВАНИЕ '	
		ELSE 'НЕИЗВЕСТНАЯ ОШИБКА: '+ CAST(ERROR_NUMBER() AS  VARCHAR(5))+ ERROR_MESSAGE()
	END;
	IF @@TRANCOUNT > 0 ROLLBACK TRAN; -- УР.ВЛОЖЕННОСТИ ТР.>0,  ТРАНЗ НЕ ЗАВЕРШЕНА
END CATCH;

DELETE FACULTY WHERE FACULTY = 'ДФ';
DELETE FACULTY WHERE FACULTY = 'ПИМ';

SELECT * FROM FACULTY;
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