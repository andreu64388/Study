/* 1. Разработать сценарий, де-монстрирующий работу в ре-жиме неявной транзакции.
Проанализировать пример, приведенный справа, в котором создается таблица Х, и создать сценарий 
для другой таблицы.
*/
SET NOCOUNT ON;
IF EXISTS (SELECT * FROM SYS.OBJECTS WHERE OBJECT_ID = OBJECT_ID(N'DBO.X')) -- ТАБЛИЦА ЕСТЬ?
DROP TABLE X;

DECLARE @C INT, @FLAG CHAR = 'R';-- ЕСЛИ С->R, ТАБЛИЦА НЕ СОХР
SET IMPLICIT_TRANSACTIONS ON;-- ВКЛЮЧ. РЕЖИМ НЕЯВНОЙ ТРАНЗАКЦИИ
CREATE TABLE X (VAL INT);-- НАЧАЛО ТРАНЗАКЦИИ
INSERT X VALUES (1), (2), (3);
SET @C = (SELECT COUNT(*) FROM X);
PRINT 'КОЛ-ВО СТРОК В ТАБЛИЦЕ X: ' + CONVERT(VARCHAR, @C);
IF @FLAG = 'C'-- ЗАВЕРШЕНИЕ ТРАНЗАКЦИИ: ФИКСАЦИЯ
COMMIT;
ELSE
ROLLBACK;-- ЗАВЕРШЕНИЕ ТРАНЗАКЦИИ: ОТКАТ
SET IMPLICIT_TRANSACTIONS OFF;-- ВЫКЛЮЧ. РЕЖИМ НЕЯВНОЙ ТРАНЗАКЦИИ

IF EXISTS (SELECT * FROM SYS.OBJECTS WHERE OBJECT_ID = OBJECT_ID(N'DBO.X'))
PRINT 'ТАБЛИЦА X ЕСТЬ';
ELSE
PRINT 'ТАБЛИЦЫ X НЕТ';