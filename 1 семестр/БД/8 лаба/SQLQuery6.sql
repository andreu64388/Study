/*6. Разработать сценарий, в котором с помощью CASE анализируются оценки, полученные
студентами некоторого фа-культета при сдаче экзаменов.*/

use UNIVER;

select (case
when NOTE between 0 and 3 then 'Не сдал'
when NOTE between 4 and 5 then 'Плохо'
when NOTE between 6 and 7 then 'Нормально'
when NOTE between 8 and 10 then 'Хорошо'
end) Оценка, count(*) [Количество] from PROGRESS
group by (case
when NOTE between 0 and 3 then 'Не сдал'
when NOTE between 4 and 5 then 'Плохо'
when NOTE between 6 and 7 then 'Нормально'
when NOTE between 8 and 10 then 'Хорошо'
end)
