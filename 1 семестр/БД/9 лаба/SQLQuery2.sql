/*2. Создать временную локальную таблицу. Заполнить ее данными (10000 строк или больше). 
Разработать SELECT-запрос. По-лучить план запроса и определить его стоимость. 
Создать некластеризованный не-уникальный составной индекс. 
Оценить процедуры поиска ин-формации.
*/
USE UNIVER;
create table #test2
(
Info nvarchar (20),
Iterator int identity(1,1),
Time datetime
)

declare @x int =1;
while @x <= 11000
begin
insert into #test2 values
('Строка' + cast(@x as nvarchar), SYSDATETIME())
set @x +=1;
end

select * from #test2 where Info = 'Строка21' and Time <= SYSDATETIME() -- 0.0627894

checkpoint;
dbcc dropcleanbuffers

create index #test2_nonCl on #test2(Info, Time)

select * from #test2 where Info = 'Строка21' and Time <= SYSDATETIME() -- 0.0065704

drop index #test2_nonCl on #test2