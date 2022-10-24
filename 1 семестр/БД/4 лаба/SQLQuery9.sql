
/*OIN.
7. В запросе, реализующем пункт 6, поме-нять порядок таблиц в выражении LEFT OUTER JOIN. Объяснить: почему в столбце Кафедра не может быть значения NULL.
Переписать запрос таким образом, чтобы получился аналогичный результат, но при-менялось соединение таблиц RIGHT OUTER JOIN.*/

use UNIVER;
select PULPIT.PULPIT_NAME [Кафедра], isnull(TEACHER.TEACHER_NAME, '***') [Преподаватель]
from TEACHER
         left outer join PULPIT
                         on PULPIT.PULPIT = TEACHER.PULPIT;


select PULPIT.PULPIT_NAME as 'Кафедра', isnull(TEACHER.TEACHER_NAME, '***') as 'Преподаватель'
from TEACHER
         right outer join PULPIT
                          on PULPIT.PULPIT = TEACHER.PULPIT;

