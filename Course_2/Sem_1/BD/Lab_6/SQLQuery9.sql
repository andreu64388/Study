/*9. Получить разницу между множеством строк, созданных в результате запросов пункта 8.
 Объяснить результат.
Использовать оператор EXCEPT.*/
use UNIVER;

select GROUPS.PROFESSION, P.SUBJECT, AVG(NOTE) as AVERAGE_NOTE
from GROUPS
         join STUDENT S on GROUPS.IDGROUP = S.IDGROUP and GROUPS.FACULTY = 'ТОВ'
         join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by P.SUBJECT, GROUPS.PROFESSION
UNION
select GROUPS.PROFESSION, P.SUBJECT, AVG(NOTE) as AVERAGE_NOTE
from GROUPS
         join STUDENT S on GROUPS.IDGROUP = S.IDGROUP and GROUPS.FACULTY = 'ХТиТ'
         join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by P.SUBJECT, GROUPS.PROFESSION
EXCEPT
select GROUPS.PROFESSION, P.SUBJECT, AVG(NOTE) as AVERAGE_NOTE
from GROUPS
         join STUDENT S on GROUPS.IDGROUP = S.IDGROUP and GROUPS.FACULTY = 'ТОВ'
         join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by P.SUBJECT, GROUPS.PROFESSION
UNION ALL
select GROUPS.PROFESSION, P.SUBJECT, AVG(NOTE) as AVERAGE_NOTE
from GROUPS
         join STUDENT S on GROUPS.IDGROUP = S.IDGROUP and GROUPS.FACULTY = 'ХТиТ'
         join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by P.SUBJECT, GROUPS.PROFESSION




------------------------------------------
USE BANK;
SELECT БАНК.Назаание_кредита,
БАНК.Ставка, 
avg(Оформление.сумма)
FROM БАНК 
Full JOIN Оформление ON БАНК.id = Оформление.id
GROUP BY Назаание_кредита,Ставка
EXCEPT
SELECT БАНК.Назаание_кредита,
БАНК.Ставка, 
avg(Оформление.сумма)
FROM БАНК 
JOIN Оформление ON БАНК.id = Оформление.id
GROUP BY Назаание_кредита,Ставка