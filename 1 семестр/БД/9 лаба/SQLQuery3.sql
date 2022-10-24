/*3. —оздать временную локальную таблицу. «аполнить ее данными (не менее 10000 строк). 
–азработать SELECT-запрос. ѕо-лучить план запроса и определить его стоимость. 
—оздать некластеризованный ин-декс покрыти€, уменьшающий сто-имость SELECT-запроса. 
*/
USE UNIVER;
create table #task3Pok
(
Info nvarchar (20),
Iterator int identity(1,1),
Time datetime
)
declare @h int =1;
while @h <= 11000
begin
insert into #task3Pok values
('—трока' + cast(@h as nvarchar), SYSDATETIME())
set @h +=1;
end

select Info from #task3Pok where Iterator >=10000 -- 0.0627894

checkpoint;
dbcc dropcleanbuffers

create index #NonClustPok on #task3Pok(Iterator) include (Info)

select Info from #task3Pok where Iterator >=10000 -- 0.0080868

drop index #NonClustPok on #task3Pok

drop table #task3Pok