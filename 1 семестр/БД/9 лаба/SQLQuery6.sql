﻿/*6. Разработать пример, демон-стрирующий применение параметра FILLFACTOR 
при создании некла-стеризованного индекса.
*/
use UNIVER;
-- PAD_INDEX ON означает «Применить FILLFACTOR ко всем слоям»
CREATE TABLE  #TASK5
(
INFO NVARCHAR (20),
ITERATOR INT IDENTITY(1,1),
INDEX_ INT 
)

DECLARE @X INT =1;
WHILE @X <= 11000
BEGIN
INSERT INTO  #TASK5(INFO,INDEX_)
VALUES ('СТРОКА' + CAST(@X AS NVARCHAR),FLOOR(20000*RAND()))
SET @X +=1;
END


DROP INDEX #TASK5_TKEY ON #TASK5 
CREATE INDEX #TASK5_TKEY ON #TASK5(INDEX_) WITH FILLFACTOR = 65 

INSERT TOP(50)PERCENT #TASK5(INDEX_, INFO) SELECT INDEX_, INFO FROM #TASK5

SELECT NAME [Индекс], AVG_FRAGMENTATION_IN_PERCENT [Фрагментация (%)]
        FROM SYS.DM_DB_INDEX_PHYSICAL_STATS(DB_ID(N'TEMPDB'),
        OBJECT_ID(N'#TASK5'), NULL, NULL, NULL) SS
        JOIN SYS.INDEXES II ON SS.OBJECT_ID = II.OBJECT_ID AND SS.INDEX_ID = II.INDEX_ID WHERE NAME IS NOT NULL;
