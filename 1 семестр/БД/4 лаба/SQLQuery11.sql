use UNIVER;
--9. Разработать SELECT-запрос на основе CROSS JOIN-соединения таблиц AUDITORIUM_TYPE и AUDITORIUM, формиру-ющего результат, аналогичный результату, полученному при выполнении запроса в за-дании 1.

select AUDITORIUM.AUDITORIUM, AUDITORIUM_TYPE.AUDITORIUM_TYPE
from AUDITORIUM
cross join AUDITORIUM_TYPE
where AUDITORIUM.AUDITORIUM_TYPE = AUDITORIUM_TYPE.AUDITORIUM_TYPE;


----------------------
use BANK;
select БАНК.Назаание_кредита,Оформление.Номер_кредита 
from БАНК cross join
Оформление 


