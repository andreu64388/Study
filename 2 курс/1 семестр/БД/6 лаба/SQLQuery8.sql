/*8. Получить пересечение двух множеств строк, созданных в результате выполнения запросов пункта 8. Объяснить результат.
Использовать оператор INTERSECT.*/

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

INTERSECT
select GROUPS.PROFESSION,P.SUBJECT,AVG(NOTE) as AVERAGE_NOTE
from GROUPS full join STUDENT S on GROUPS.IDGROUP = S.IDGROUP and GROUPS.FACULTY='ТОВ'
 full join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by P.SUBJECT, GROUPS.PROFESSION
UNION ALL
select GROUPS.PROFESSION,P.SUBJECT,AVG(NOTE) as AVERAGE_NOTE
from GROUPS full join STUDENT S on GROUPS.IDGROUP = S.IDGROUP and GROUPS.FACULTY='ХТиТ'
 full join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by P.SUBJECT, GROUPS.PROFESSION


------------------------------------------

USE BANK;
SELECT БАНК.Назаание_кредита,
БАНК.Ставка, 
avg(Оформление.сумма)
FROM БАНК 
Full JOIN Оформление ON БАНК.id = Оформление.id
GROUP BY Назаание_кредита,Ставка
UNION ALL
SELECT БАНК.Назаание_кредита,
БАНК.Ставка, 
avg(Оформление.сумма)
FROM БАНК 
JOIN Оформление ON БАНК.id = Оформление.id
GROUP BY Назаание_кредита,Ставка