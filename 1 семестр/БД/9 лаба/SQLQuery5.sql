/*5. Заполнить временную локаль-ную таблицу. 
Создать некластеризованный ин-декс. Оценить уровень фрагмента-ции индекса. 
Разработать сценарий на T-SQL, выполнение которого приводит к уровню фрагментации индекса выше 90%. Оценить уровень фрагмента-ции индекса. 
Выполнить процедуру реоргани-зации индекса, оценить уровень фрагментации. 
Выполнить процедуру пере-стройки индекса и оценить уровень фрагментации индекса.
*/
USE UNIVER;
CREATE TABLE  #TASK5
(
INFO NVARCHAR (20),
ITERATOR INT IDENTITY(1,1),
INDEX_ INT 
)

DECLARE @X INT =0;
WHILE @X <= 10000
BEGIN
INSERT INTO  #TASK5(INFO,INDEX_)
VALUES ('СТРОКА' + CAST(@X AS NVARCHAR),FLOOR(20000*RAND()))
SET @X +=1;
END

CHECKPOINT;
DBCC DROPCLEANBUFFERS

CREATE INDEX #TASK5_KEY ON #TASK5(INDEX_)

-- ПОСТАВИТЬ TEMPDB !!!

SELECT NAME [ИНДЕКС], AVG_FRAGMENTATION_IN_PERCENT [ФРАГМЕНТАЦИЯ (%)] 
FROM SYS.DM_DB_INDEX_PHYSICAL_STATS(DB_ID(N'TEMPDB'),
OBJECT_ID(N'#TASK5'), NULL, NULL, NULL) SS
JOIN SYS.INDEXES II ON SS.OBJECT_ID = II.OBJECT_ID
AND SS.INDEX_ID = II.INDEX_ID WHERE NAME IS NOT NULL; 
INSERT TOP(10000) #TASK5(INDEX_ ,INFO) SELECT INDEX_, INFO FROM #TASK5

DROP INDEX #TASK5_KEY ON #TASK5

DROP TABLE #TASK5

ALTER INDEX #TASK5_KEY ON #TASK5 REORGANIZE

ALTER INDEX #TASK5_KEY ON #TASK5 REBUILD WITH (ONLINE = OFF)