/*7. Создать временную локальную таблицу из трех столбцов и 10 строк, заполнить ее и вывести содержимое. 
Использовать оператор WHILE.*/
create table #MyTable(Числа int, Слова nvarchar(50), [Еще слова] nvarchar(50));
set nocount on;
declare @i int = 1;
while @i <11
begin
insert into #MyTable values
(cast(@i as int), cast(@i as nvarchar(10)) + ' - Лаба ','БД ' + cast(@i as nvarchar(10)))
set @i +=1;
end
select * from #MyTable
order by Числа desc
go

drop table #MyTable;