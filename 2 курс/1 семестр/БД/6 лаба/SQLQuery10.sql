/*10. На основе таблицы PROGRESS определить для каждой дисциплины коли-чество студентов, получивших оценки 8 и 9.
Использовать группировку, секцию HAVING, сортировку. */

use UNIVER;
select SUBJECT,
       count(NOTE) as [Кол-во]
from PROGRESS
group by SUBJECT, NOTE
HAVING NOTE in (8, 9)


------------------------

USE BANK;
SELECT БАНК.Назаание_кредита,
БАНК.Ставка, 
avg(Оформление.сумма)
FROM БАНК 
Full JOIN Оформление ON БАНК.id = Оформление.id
GROUP BY Назаание_кредита,Ставка
HAVING Ставка >10