
use UNIVER;
select AUDITORIUM.AUDITORIUM, AUDITORIUM_TYPE.AUDITORIUM_TYPENAME
from AUDITORIUM_TYPE
         Inner Join AUDITORIUM
                    on AUDITORIUM_TYPE.AUDITORIUM_TYPE = AUDITORIUM.AUDITORIUM_TYPE;

----------------------------------------
use BANK;

select БАНК.Назаание_кредита ,Оформление.сумма from БАНК 
join Оформление on 
БАНК.id = Оформление.id