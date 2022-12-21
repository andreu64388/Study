/* 1. Разработать сценарий, де-монстрирующий работу в ре-жиме неявной транзакции.
Проанализировать пример, приведенный справа, в котором создается таблица Х, и создать сценарий 
для другой таблицы.
*/
USE UNIVER
GO
SET NOCOUNT ON
	IF EXISTS (SELECT * FROM  SYS.OBJECTS        -- ТАБЛИЦА X ЕСТЬ?
	            WHERE OBJECT_ID= OBJECT_ID(N'DBO.M') )	            
	DROP TABLE M;    
	
	DECLARE @C INT, @FLAG CHAR = 'C';           -- COMMIT ИЛИ ROLLBACK?
	SET IMPLICIT_TRANSACTIONS  ON   -- ВКЛЮЧ. РЕЖИМ НЕЯВНОЙ ТРАНЗАКЦИИ
	CREATE TABLE M(K INT );                         -- НАЧАЛО ТРАНЗАКЦИИ 
		INSERT M VALUES (1),(2),(3);
		SET @C = (SELECT COUNT(*) FROM M);
		PRINT 'КОЛИЧЕСТВО СТРОК В ТАБЛИЦЕ M: ' + CAST( @C AS VARCHAR(2));
		IF @FLAG = 'C'  COMMIT;                   -- ЗАВЕРШЕНИЕ ТРАНЗАКЦИИ: ФИКСАЦИЯ 
	          ELSE   ROLLBACK;                                 -- ЗАВЕРШЕНИЕ ТРАНЗАКЦИИ: ОТКАТ  
      SET IMPLICIT_TRANSACTIONS  OFF   -- ВЫКЛЮЧ. РЕЖИМ НЕЯВНОЙ ТРАНЗАКЦИИ
	
	IF  EXISTS (SELECT * FROM  SYS.OBJECTS       -- ТАБЛИЦА X ЕСТЬ?
	            WHERE OBJECT_ID= OBJECT_ID(N'DBO.M') )
	PRINT 'ТАБЛИЦА M ЕСТЬ';  
      ELSE PRINT 'ТАБЛИЦЫ M НЕТ'

-------------------------------------------------------------
--------------------------BANK-------------------------------
-------------------------------------------------------------
DROP TABLE TEST_X;
USE BANK;
DECLARE @LENGHT INT, @FLAG_MY CHAR = 'R'
SET IMPLICIT_TRANSACTIONS ON;-- ВКЛЮЧ. РЕЖИМ НЕЯВНОЙ ТРАНЗАКЦИИ
CREATE TABLE TEST_X (VAL INT);-- НАЧАЛО ТРАНЗАКЦИИ
INSERT INTO TEST_X VALUES (1), (2), (3);
SET @LENGHT = (SELECT COUNT(*) FROM TEST_X);
PRINT 'КОЛ-ВО СТРОК В ТАБЛИЦЕ TEST: ' + CONVERT(VARCHAR, @LENGHT);
IF @FLAG_MY = 'R'
COMMIT;
ELSE
ROLLBACK;-- ЗАВЕРШЕНИЕ ТРАНЗАКЦИИ: ОТКАТ
SET IMPLICIT_TRANSACTIONS OFF;-- ВЫКЛЮЧ. РЕЖИМ НЕЯВНОЙ ТРАНЗАКЦИИ
