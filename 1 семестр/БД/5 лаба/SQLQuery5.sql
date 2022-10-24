/*5. На основе таблиц FACULTY и PUL-PIT сформировать список наименований факультетов
(столбец FACULTY_NAME) на котором нет ни одной кафедры (табли-ца PULPIT).
Примечание: использовать предикат EXISTS и коррелированный под-запрос*/

use UNIVER;

select * from FACULTY 
where not exists (select * from PULPIT where PULPIT.FACULTY = FACULTY.FACULTY);
	
--------------------------------------------------
use BANK;
select * from БАНК 
where exists (select * from Оформление 
where Оформление.id = БАНК.id
)
