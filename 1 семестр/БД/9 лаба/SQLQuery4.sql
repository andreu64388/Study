/*4. Создать и заполнить временную локальную таблицу. 
Разработать SELECT-запрос, по-лучить план запроса и определить его стоимость. 
Создать некластеризованный фильтруемый индекс, уменьшаю-щий стоимость SELECT-запроса.
*/


-----------------------------------------------
--------------------UNIVER---------------------
-----------------------------------------------

USE UNIVER;

CREATE TABLE #TASK4
(
INFO NVARCHAR (20),
ITERATOR INT IDENTITY(1,1),
INDEX_ INT 
)

DECLARE @X INT =0;
WHILE @X <= 10000
BEGIN
INSERT INTO #TASK4(INFO,INDEX_)
VALUES ('СТРОКА' + CAST(@X AS NVARCHAR),FLOOR(20000*RAND()))
SET @X +=1;
END


SELECT ITERATOR FROM #TASK4 
WHERE ITERATOR > 1500 AND ITERATOR < 2000

CREATE INDEX #INDEX ON #TASK4(ITERATOR)
WHERE (ITERATOR > 1500 AND ITERATOR < 2000)

CHECKPOINT;
DBCC DROPCLEANBUFFERS

SELECT ITERATOR FROM #TASK4 
WHERE ITERATOR > 1500 AND ITERATOR < 2000

DROP INDEX #INDEX ON #TASK4

-----------------------------------------------
---------------------BANK----------------------
-----------------------------------------------

USE BANK;

SELECT * FROM КЛИЕНТ
WHERE ID_CLIENT = 10 AND КОНТАКТОЕ_ЛИЦО = 'ДОМ'

CREATE INDEX MY_BANK_2 ON КЛИЕНТ(ID_CLIENT) WHERE 

SELECT * FROM Клиент
WHERE ID_CLIENT = 10 AND КОНТАКТОЕ_ЛИЦО = 'ДОМ'

DROP INDEX MY_BANK_2 ON БАНК;