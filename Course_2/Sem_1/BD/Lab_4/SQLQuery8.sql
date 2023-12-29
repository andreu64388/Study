

/*6. На основе таблиц PULPIT и TEACHER получить полный перечень кафедр (столбец PULPIT.PULPIT_ NAME) и преподавателей (столбец TEACHER.TEA-CHER_NAME) на этих кафедрах. Результирующий набор должен содержать два столбца: Кафедра и Преподаватель. Если на кафедре нет препо-давателей, то в столбце Преподаватель должна быть выведена строка ***.
Примечание: использовать соединение таблиц LEFT OUTER JOIN и функцию isnull.*/
use UNIVER;

select PULPIT.PULPIT_NAME [Кафедра], isnull(TEACHER.TEACHER_NAME, '***') [Преподаватель]
from PULPIT
         left  join TEACHER
                         on PULPIT.PULPIT = TEACHER.PULPIT;

--------------------------------------------

use BANK;
select БАНК.Назаание_кредита,БАНК.Ставка from БАНК 
left join  Оформление
on БАНК.id = Оформление.id