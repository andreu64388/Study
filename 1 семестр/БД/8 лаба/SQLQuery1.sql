/*1. Разработать T-SQL-скрипт, в котором: 
 объявить переменные типа char, varchar, datetime, time, int, smallint, tinint, numeric(12, 5); 
 первые две переменные проинициализировать в операторе объявления;
 присвоить произвольные значения следующим двум переменным с помощью оператора SET, одной из этих переменных присвоить значение, полученное в результате запроса SELECT; 
 одну из переменных оставить без инициализации и не присваивать ей значения, оставшимся переменным присвоить некоторые значения с помощью оператора SELECT; 
 значения одной половины переменных вывести с помощью оператора SELECT, значения другой половины переменных распечатать с помощью оператора PRINT. 
Проанализировать результаты.
*/
declare @a char = 'А',
@b varchar(3) = 'ФИТ',
@c datetime,
@d time,
@e int,
@f smallint,
@g tinyint,
@h numeric(12,5);

set @c = getdate();
set @d = (select convert(varchar(12), getdate(), 114) 'hh:mi:ss:mmm');

select @e = 21122001, @f = 21, @G = 1;

select @a Символ, @b Строка, @c Дата;

print 'Время = ' + cast(@d as nvarchar);
print 'Int = ' + convert(nvarchar, @e);
print 'Smallint = ' + convert(nvarchar, @f);
print 'Tinyint = ' + convert(nvarchar, @g);
print 'Numeric = ' + convert(nvarchar, @h);