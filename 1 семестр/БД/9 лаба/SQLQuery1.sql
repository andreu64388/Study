/*1. С помощью SSMS определить все индексы, которые имеются в БД UNIVER. Определить, какие из них являются кластеризованными, а ка-кие некластеризованными. 
Создать временную локальную таблицу. Заполнить ее данными (не менее 1000 строк). 
Разработать SELECT-запрос. По-лучить план запроса и определить его стоимость. 
Создать кластеризованный индекс, уменьшающий стоимость SELECT-запроса.*/
USE UNIVER;

exec sp_helpindex 'AUDITORIUM_TYPE' -- перечень индексов

create table #task1 (first int, second varchar(100))
set nocount on -- не выводить сообщени¤ о вводе строк
declare @i int = 0
while @i < 1000
begin
insert #task1(first, second) values (floor(20000*rand()), replicate('строка', 10))
if (@i % 100 = 0) print @i;
set @i = @i + 1
end

select * from #task1 where first between 1500 and 2500 order by first -- 0.0230752

checkpoint; -- фиксаци¤ Ѕƒ
dbcc dropcleanbuffers

create clustered index #task1_cl on #task1(first asc)

select * from #task1 where first between 1500 and 2500 order by first -- 0.0033414

drop index #task1_cl on #task1