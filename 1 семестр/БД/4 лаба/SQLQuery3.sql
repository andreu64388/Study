/*2. На основе таблиц AUDITORI-UM_TYPE и AUDITORIUM сформировать перечень кодов аудиторий (столбец AUDI-TORIUM.AUDITORIUM) и соответствую-щих им наименований типов аудиторий (столбец AUDITORIUM_ TYPE.AUDITO-RIUM_TYPENAME). При этом следует выбрать только те ауди-тории, в наименовании которых присутству-ет подстрока компьютер.
Примечание: использовать соединение таблиц INNER JOIN и предикат LIKE.*/

use UNIVER
select AUDITORIUM.AUDITORIUM, AUDITORIUM_TYPE.AUDITORIUM_TYPENAME
from AUDITORIUM_TYPE
         Inner Join AUDITORIUM
                    on AUDITORIUM_TYPE.AUDITORIUM_TYPE = AUDITORIUM.AUDITORIUM_TYPE And
                       AUDITORIUM_TYPE.AUDITORIUM_TYPENAME Like '%компьютер%';


----------------------------------------------------
use BANK;

select БАНК.Назаание_кредита ,Оформление.сумма from БАНК 
join Оформление on 
БАНК.id = Оформление.id and  БАНК.Назаание_кредита Like 'быс%'