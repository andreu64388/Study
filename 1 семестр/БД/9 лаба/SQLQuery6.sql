/*6. Разработать пример, демон-стрирующий применение параметра FILLFACTOR 
при создании некла-стеризованного индекса.
*/
use UNIVER;
-- PAD_INDEX ON означает «Применить FILLFACTOR ко всем слоям»

drop index #task5_tkey on #task5 
create index #task5_tkey on #task5(tkey) with fillfactor = 65 -- ïðîöåíò çàïîëíåíèÿ èíäåêñíûõ ñòðàíèö íèæíåãî óðîâíÿ

insert top(50)percent #task5(tkey, tf) select tkey, tf from #task5

select name [Èíäåêñ], avg_fragmentation_in_percent [Ôðàãìåíòàöèÿ (%)]
        FROM sys.dm_db_index_physical_stats(DB_ID(N'TEMPDB'),
        OBJECT_ID(N'#task5'), NULL, NULL, NULL) ss
        JOIN sys.indexes ii on ss.object_id = ii.object_id and ss.index_id = ii.index_id where name is not null;
