/*2. Разработать скрипт, в котором определяется общая вместимость ауди-торий. 
Когда общая вместимость пре-вышает 200, то вывести количество аудиторий, среднюю вместимость ауди-торий,
количество аудиторий, вмести-мость которых меньше средней, и про-цент таких аудиторий. Когда общая вместимость
аудиторий меньше 200, то вывести сообщение о размере общей вместимости.*/
use UNIVER;

declare @capacity int = (select cast(sum(AUDITORIUM_CAPACITY) as int) from AUDITORIUM),
@total int,
@avgCapacity int,
@totalLessThanAvg int,
@procent numeric(4,2);

if @capacity > 200
begin
set @total = (select count(*) from AUDITORIUM);
set @avgCapacity = (select avg(AUDITORIUM_CAPACITY) from AUDITORIUM);
set @totalLessThanAvg = (select count(*) from AUDITORIUM where AUDITORIUM_CAPACITY < @avgCapacity);
set @procent = @totalLessThanAvg * 100 / @total;
select @capacity 'Общая вместимость',
@total 'Всего аудиторий',
@avgCapacity 'Средняя вместимость',
@totalLessThanAvg 'Аудиторий с вместимостью ниже среднего',
@procent 'Процент таких аудиторий'
end

else print 'Общая вместимость < 200'