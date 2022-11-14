/*2. Создать временную локальную таблицу. Заполнить ее данными (10000 строк или больше). 
Разработать SELECT-запрос. По-лучить план запроса и определить его стоимость. 
Создать некластеризованный не-уникальный составной индекс. 
Оценить процедуры поиска ин-формации.
*/
USE UNIVER;
CREATE TABLE #TEST2
(
INFO NVARCHAR (20),
ITERATOR INT IDENTITY(1,1),
INDEX_ INT 
)

DECLARE @X INT =0;
WHILE @X <= 10000
BEGIN
INSERT INTO #TEST2(INFO,INDEX_)
VALUES ('СТРОКА' + CAST(@X AS NVARCHAR),FLOOR(20000*RAND()))
SET @X +=1;
END

SELECT * FROM #TEST2 WHERE INFO = 'СТРОКА2' AND INDEX_ >= 1000 

CHECKPOINT;

DBCC DROPCLEANBUFFERS

CREATE INDEX #TEST2_NONCL ON #TEST2(INFO,INDEX_)

SELECT * FROM #TEST2 WHERE INFO = 'СТРОКА2' AND INDEX_ >= 1000

DROP INDEX #TEST2_NONCL ON #TEST2
