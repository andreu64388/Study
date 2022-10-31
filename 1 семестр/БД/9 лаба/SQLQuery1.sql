/*1. С ПОМОЩЬЮ SSMS ОПРЕДЕЛИТЬ ВСЕ ИНДЕКСЫ, КОТОРЫЕ ИМЕЮТСЯ В БД UNIVER. ОПРЕДЕЛИТЬ, КАКИЕ ИЗ НИХ ЯВЛЯЮТСЯ КЛАСТЕРИЗОВАННЫМИ, А КА-КИЕ НЕКЛАСТЕРИЗОВАННЫМИ. 
СОЗДАТЬ ВРЕМЕННУЮ ЛОКАЛЬНУЮ ТАБЛИЦУ. ЗАПОЛНИТЬ ЕЕ ДАННЫМИ (НЕ МЕНЕЕ 1000 СТРОК). 
РАЗРАБОТАТЬ SELECT-ЗАПРОС. ПО-ЛУЧИТЬ ПЛАН ЗАПРОСА И ОПРЕДЕЛИТЬ ЕГО СТОИМОСТЬ. 
СОЗДАТЬ КЛАСТЕРИЗОВАННЫЙ ИНДЕКС, УМЕНЬШАЮЩИЙ СТОИМОСТЬ SELECT-ЗАПРОСА.*/
USE UNIVER;

EXEC SP_HELPINDEX 'AUDITORIUM_TYPE' -- ПЕРЕЧЕНЬ ИНДЕКСОВ

CREATE TABLE #TIMETEST
(INDEX_ INT, 
MESSAGES_
NVARCHAR(20))
SET NOCOUNT ON -- НЕ ВЫВОДИТЬ СООБЩЕНИ¤ О ВВОДЕ СТРОК
DECLARE @I INT = 0
WHILE @I < 1000
BEGIN
INSERT #TIMETEST(INDEX_, MESSAGES_) VALUES (FLOOR(20000*RAND()), REPLICATE('СТРОКА ', 3))
IF (@I % 100 = 0) PRINT @I;
SET @I = @I + 1
END

SELECT * FROM #TIMETEST WHERE INDEX_ BETWEEN 1000 AND 1500 ORDER BY INDEX_ 

CHECKPOINT; 

DBCC DROPCLEANBUFFERS

CREATE CLUSTERED INDEX TIMETEST_CL ON #TIMETEST(INDEX_ ASC)

SELECT * FROM #TIMETEST WHERE INDEX_ BETWEEN 1500 AND 2500 ORDER BY INDEX_

DROP INDEX TIMETEST_CL ON TIMETEST

----------------------------------------
USE BANK;
EXEC SP_HELPINDEX 'БАНК' 

SELECT * FROM БАНК
WHERE id = 3

CREATE INDEX MY_BANK ON БАНК(id);

DROP INDEX MY_BANK ON БАНК;

SELECT * FROM БАНК
WHERE id = 3
