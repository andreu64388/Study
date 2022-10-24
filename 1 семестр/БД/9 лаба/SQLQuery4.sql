/*4. —оздать и заполнить временную локальную таблицу. 
–азработать SELECT-запрос, по-лучить план запроса и определить его стоимость. 
—оздать некластеризованный фильтруемый индекс, уменьшаю-щий стоимость SELECT-запроса.
*/


USE UNIVER;
create table #task4Filter
(
Info nvarchar (20),
Iterator int identity(1,1),
Time datetime
)
declare @z int =1;
while @z <= 11000
begin
insert into #task4Filter values
('—трока' + cast(@z as nvarchar), SYSDATETIME())
set @z +=1;
end

create index #Index on #task4Filter(Iterator) where (Iterator > 15000 and Iterator < 20000)
checkpoint;
dbcc dropcleanbuffers
select Iterator from #task4Filter where Iterator between 10000 and 20000 -- 0.0627894 -- 0.0627894
select Iterator from #task4Filter where Iterator > 15000 and Iterator < 20000 -- 0.0627894 -- 0.0032831