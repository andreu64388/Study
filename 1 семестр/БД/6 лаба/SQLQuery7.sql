/*7. На основе таблиц GROUPS, STU-DENT и PROGRESS разработать SELECT-запрос, в котором определяются результаты сдачи экзаменов.В запросе должны отражаться специаль-ности, дисциплины, средние оценки студен-тов на факультете ТОВ.
Отдельно разработать запрос, в котором определяются результаты сдачи экзаменов на факультете ХТиТ.
Объединить результаты двух запросов с использованием операторов UNION и UN-ION ALL. Объяснить результаты.
*/

use UNIVER;

select GROUPS.PROFESSION,P.SUBJECT,AVG(NOTE) as AVERAGE_NOTE
from GROUPS  full join STUDENT S on GROUPS.IDGROUP = S.IDGROUP and GROUPS.FACULTY='ТОВ'
 full join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by P.SUBJECT, GROUPS.PROFESSION
UNION
select GROUPS.PROFESSION,P.SUBJECT,AVG(NOTE) as AVERAGE_NOTE
from GROUPS full join STUDENT S on GROUPS.IDGROUP = S.IDGROUP and GROUPS.FACULTY='ХТиТ'
 full join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by P.SUBJECT, GROUPS.PROFESSION


select GROUPS.PROFESSION,P.SUBJECT,AVG(NOTE) as AVERAGE_NOTE
from GROUPS full join STUDENT S on GROUPS.IDGROUP = S.IDGROUP and GROUPS.FACULTY='ТОВ'
 full join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by P.SUBJECT, GROUPS.PROFESSION
UNION ALL
select GROUPS.PROFESSION,P.SUBJECT,AVG(NOTE) as AVERAGE_NOTE
from GROUPS full join STUDENT S on GROUPS.IDGROUP = S.IDGROUP and GROUPS.FACULTY='ХТиТ'
 full join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by P.SUBJECT, GROUPS.PROFESSION



--------------------------------------------------------
USE BANK;
SELECT БАНК.Назаание_кредита,
БАНК.Ставка, 
avg(Оформление.сумма)
FROM БАНК 
Full JOIN Оформление ON БАНК.id = Оформление.id
GROUP BY Назаание_кредита,Ставка
UNION
SELECT БАНК.Назаание_кредита,
БАНК.Ставка, 
avg(Оформление.сумма)
FROM БАНК 
JOIN Оформление ON БАНК.id = Оформление.id
GROUP BY Назаание_кредита,Ставка