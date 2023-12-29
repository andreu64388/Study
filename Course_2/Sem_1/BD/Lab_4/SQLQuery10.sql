/*8. Показать на примере, что соединение
FULL OUTER JOIN двух таблиц:
− является коммутативной операцией;
− является объединением LEFT OUTER JOIN и RIGHT OUTER JOIN соединений этих таблиц;
− включает соединение INNER JOIN этих таблиц.
Примечание: создать две таблицы, запол-нить их данными. Разработать SELECT-запросы, реализующие задания.
Создать три новых запроса:
− запрос, результат которого содержит дан-ные левой (в операции FULL OUTER JOIN) таблицы и не содержит данные правой;
− запрос, результат которого содержит дан-ные правой таблицы и не содержащие данные левой;
− запрос, результат которого содержит дан-ные правой таблицы и левой таблиц;
и выполняется для каждой строки результирующего набора
его выполнения подставляется в каждую строку результирующего набора. 
Примечание: использовать в запросах вы-ражение IS NULL и IS NOT NULL.*/
--коррелированный 
use UNIVER;

select [NAME], YEAR_FIRST from STUDENT full  join GROUPS G on STUDENT.IDGROUP = G.IDGROUP
select [NAME], YEAR_FIRST from GROUPS full  join STUDENT S on GROUPS.IDGROUP = S.IDGROUP


    SELECT NAME, YEAR_FIRST
    From GROUPS
             Left OUTER JOIN STUDENT S2 on GROUPS.IDGROUP = S2.IDGROUP

    SELECT NAME, YEAR_FIRST
    From GROUPS
             RIGHT outer join STUDENT S3 on GROUPS.IDGROUP = S3.IDGROUP


select PULPIT.FACULTY, PULPIT.PULPIT, PULPIT.PULPIT_NAME
from PULPIT full outer join TEACHER
on PULPIT.PULPIT = TEACHER.PULPIT
where TEACHER.TEACHER is null

select TEACHER.TEACHER_NAME, TEACHER.TEACHER, TEACHER.PULPIT,TEACHER.GENDER
from PULPIT full outer join TEACHER
on PULPIT.PULPIT=TEACHER.PULPIT
where TEACHER.TEACHER is not null

select * from PULPIT full outer join TEACHER
on PULPIT.PULPIT = TEACHER.PULPIT




