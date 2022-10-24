/*2. На основе таблиц AUDITORIUM и AUDITORIUM_TYPE разработать запрос, вычисляющий для каждого типа 
аудиторий максимальную, минимальную,
среднюю вместимость аудиторий, суммарную вме-стимость всех аудиторий и общее количе-ство аудиторий
данного типа. Результирующий набор должен содер-жать столбец с наименованием типа ауди-торий 
(столбец AUDITORIUM_TYPE.AU-DITORIUM_TYPENAME) и столбцы с вычисленными величинами.
Использовать внутреннее соединение таблиц, секцию GROUP BY и агрегатные функции. */

use UNIVER;

SELECT AUDITORIUM_TYPENAME, max(AUDITORIUM_CAPACITY) as [Максимальная вместительность],
 min(AUDITORIUM_CAPACITY) as [Минимальная вместительность],
 avg(AUDITORIUM_CAPACITY) as [Средняя вместительность],
count(AUDITORIUM) as [Общее кол-во аудиторий],
 sum(AUDITORIUM_CAPACITY) as [Общая вместительность аудитории данного типа]
From AUDITORIUM_TYPE  join AUDITORIUM A on AUDITORIUM_TYPE.AUDITORIUM_TYPE = A.AUDITORIUM_TYPE
Group By AUDITORIUM_TYPENAME


-------------------------------
USE BANK;
SELECT
Назаание_кредита,
MAX(сумма) AS [Максимальная сумма],
min(сумма) AS [Минимальная сумма],
avg(сумма) AS [Средняя сумма],
count (сумма) AS [Кол-во]
FROM Оформление
join БАНК on БАНК.id = Оформление.id
group by Назаание_кредита