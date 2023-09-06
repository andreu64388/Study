/*4. Разработать SELECT-запроса на основе таблиц FACULTY, GROUPS, STUDENT и PROGRESS, который содержит среднюю
экзаменационную оценку для каждого кур-са каждой специальности. 
Строки отсорти-ровать в порядке убывания средней оценки.При этом следует учесть,
что средняя оценка должна рассчитываться с точностью до двух знаков после запятой.
Использо-вать внутреннее соединение таблиц, агре-гатную функцию AVG и встроенные функ-ции CAST и ROUND.*/
use UNIVER
select a.FACULTY,
       G.PROFESSION,
       (2014 - G.YEAR_FIRST ) [курс],
       round(avg(cast(NOTE as float(4))), 2) as [средняя оценка]
from FACULTY a
         join GROUPS G on a.FACULTY = G.FACULTY
         join STUDENT S on G.IDGROUP = S.IDGROUP
         join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by a.FACULTY, G.PROFESSION, G.YEAR_FIRST



/*Переписать SELECT-запрос, разработан-ный в задании 4 так,
чтобы в расчете сред-него значения оценок использовались оцен-ки только по дисциплинам с
кодами БД и ОАиП. Использовать WHERE.*/



select a.FACULTY,	
       G.PROFESSION,
       (2014 - G.YEAR_FIRST) [курс],
       round(avg(cast(NOTE as float(4))), 2) as [средняя оценка]
from FACULTY a
         join GROUPS G on a.FACULTY = G.FACULTY
         join STUDENT S on G.IDGROUP = S.IDGROUP
         join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT and P.SUBJECT in ('СУБД','ОАиП')
group by a.FACULTY, G.PROFESSION, G.YEAR_FIRST



-----------------------------------
USE BANK;
SELECT БАНК.Назаание_кредита,
БАНК.Ставка, 
avg(Оформление.сумма)
FROM БАНК 
JOIN Оформление ON БАНК.id = Оформление.id
GROUP BY Назаание_кредита,Ставка