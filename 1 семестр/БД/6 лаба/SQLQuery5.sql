/*5. На основе таблиц FACULTY,GROUPS, STUDENT и PROGRESS разра-ботать SELECT-запрос,
в котором выводят-ся специальность, дисциплины и средние оценки при сдаче экзаменов на
факультете ТОВ. Использовать группировку по полям FACULTY, PROFESSION, SUBJECT.
 Добавить в запрос конструкцию ROLLUP и проанализировать результат. */

/*ФАКУЛЬТЕТ СМЕНИЛ НА ИДИП, ТАК КАК ТОЛЬКО ОНИ НА ЭКЗАМЕНЫ ХОДЯТ
*/

use UNIVER;

SELECT PROFESSION,SUBJECT,G.FACULTY , AVG(NOTE) AS [средний балл]
from FACULTY join GROUPS G on FACULTY.FACULTY = G.FACULTY and G.FACULTY = 'ИДип'
join STUDENT S on G.IDGROUP = S.IDGROUP
join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by  rollup (SUBJECT,G.FACULTY,PROFESSION) 
SELECT PROFESSION,SUBJECT,G.FACULTY , AVG(NOTE) AS [средний балл]
from FACULTY join GROUPS G on FACULTY.FACULTY = G.FACULTY and G.FACULTY = 'ИДип'
join STUDENT S on G.IDGROUP = S.IDGROUP
join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by  rollup(G.FACULTY,PROFESSION,SUBJECT)


USE BANK;
SELECT БАНК.Назаание_кредита,
БАНК.Ставка, 
avg(Оформление.сумма)
FROM БАНК 
JOIN Оформление ON БАНК.id = Оформление.id
GROUP BY cube(Назаание_кредита,Ставка)