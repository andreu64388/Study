/*3. Разработать сценарий, демонстрирующий применение оператора SAVE TRAN на примере базы данных X_UNIVER. 
В блоке CATCH предусмотреть выдачу соответствующих сообщений об ошибках. 
Опробовать работу сценария при использовании различных контрольных точек и различных операторов модификации таблиц.
*/
USE UNIVER
GO
DECLARE @POINT VARCHAR(32);

BEGIN TRY
	BEGIN TRAN
		SET @POINT = 'P1';
		SAVE TRAN @POINT;  -- КОНТРОЛЬНАЯ ТОЧКА P1
		INSERT STUDENT(IDGROUP, NAME, BDAY, INFO, FOTO) VALUES
		                      (20,'АНДРЕЙ', '1997-08-02', NULL, NULL),
							  (20,'ДИМА', '1997-08-06', NULL, NULL),
							  (20,'ДИМА', '1997-08-01', NULL, NULL),
							  (20,'ПАША', '1997-08-03', NULL, NULL);
		SET @POINT = 'P2';
		SAVE TRAN @POINT; -- КОНТРОЛЬНАЯ ТОЧКА P2
		INSERT STUDENT(IDGROUP, NAME, BDAY, INFO, FOTO) VALUES
							  (21, 'ОСОБЕННЫЙ СТУДЕНТ', '1997-08-02', NULL, NULL);
	COMMIT TRAN;
END TRY

BEGIN CATCH
	PRINT 'ОШИБКА: '+ CASE
		WHEN ERROR_NUMBER() = 2627 AND PATINDEX('%STUDENT_PK%', ERROR_MESSAGE()) > 0 THEN 'ДУБЛИРОВАНИЕ СТУДЕНТА'
		ELSE 'НЕИЗВЕСТНАЯ ОШИБКА: '+ CAST(ERROR_NUMBER() AS  VARCHAR(5)) + ERROR_MESSAGE()
	END;
    IF @@TRANCOUNT > 0 -- ЕСЛИ ТРАНЗАКЦИЯ НЕ ЗАВЕРШЕНА
	BEGIN
	   PRINT 'КОНТРОЛЬНАЯ ТОЧКА: '+ @POINT;
	   ROLLBACK TRAN @POINT; -- ОТКАТ К ПОСЛЕДНЕЙ КОНТР.ТОЧКЕ
	   COMMIT TRAN; -- ФИКСАЦИЯ ИЗМЕНЕНИЙ, ВЫПОЛН ДО КОНТР.ТОЧКИ
	END;
END CATCH;

SELECT * FROM STUDENT WHERE IDGROUP=20;
DELETE STUDENT WHERE IDGROUP=20 AND IDGROUP = 21
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

