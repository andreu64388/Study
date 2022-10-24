/*4. Разработать T-SQL-скрипты, вы-полняющие: 
 вычисление значений переменной z 
 
для различных значений исходных дан-ных;
 преобразование полного ФИО сту-дента в сокращенное (например, Макей-чик Татьяна Леонидовна в Макейчик Т. Л.);
 поиск студентов, у которых день рождения в следующем месяце, и опре-деление их возраста;
 поиск дня недели, в который сту-денты некоторой группы сдавали экза-мен по СУБД.
*/
declare @z float, @t float = 21, @x float = 5;

if @t > @x
set @z = power(sin(@t), 2);

else if @t < @x
set @z = 4*(@t + @x);

else
set @z = 1 - exp(@x-2);

select @z;
-------------------------------------
declare @lastName nvarchar(20) = 'Коренчук',
@firstName nvarchar(20) = 'Андрей',
@surname nvarchar(20) = 'Васильевич',
@longName nvarchar(50),
@shortName nvarchar(30);

set @longName = @lastName + ' ' + @firstName + ' ' + @surname;

set @firstName = substring(@firstName, 1,1)+'.';
set @surname = substring(@surname, 1,1)+'.';
set @shortName = @lastName + ' ' + @firstName + ' ' + @surname;

select @longName [Полное имя] ,@shortName [Сокращенное имя];
-----------------------------------


select STUDENT.NAME, STUDENT.BDAY, (datediff(YY, STUDENT.BDAY, sysdatetime())) as Возраст
from STUDENT
where month(STUDENT.BDAY) = month(sysdatetime()) + 1;
----------------------------------

declare @groupNumber int = 4;

select distinct PROGRESS.PDATE[Дата прохождения экзамена], case
when DATEPART(dw,PROGRESS.PDATE) = 1 then 'Понедельник'
when DATEPART(dw,PROGRESS.PDATE) = 2 then 'Вторник'
when DATEPART(dw,PROGRESS.PDATE) = 3 then 'Среда'
when DATEPART(dw,PROGRESS.PDATE) = 4 then 'Четверг'
when DATEPART(dw,PROGRESS.PDATE) = 5 then 'Пятница'
when DATEPART(dw,PROGRESS.PDATE) = 6 then 'Суббота'
when DATEPART(dw,PROGRESS.PDATE) = 7 then 'Воскресенье'
end [День недели]
from GROUPS inner join STUDENT on STUDENT.IDGROUP = GROUPS.IDGROUP
inner join PROGRESS on STUDENT.IDSTUDENT= PROGRESS.IDSTUDENT
where GROUPS.IDGROUP = @groupNumber and PROGRESS.SUBJECT = 'СУБД'
