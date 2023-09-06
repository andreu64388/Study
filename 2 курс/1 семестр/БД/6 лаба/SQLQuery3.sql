/*3. Разработать запрос на основе таблицы PROGRESS, который содержит количество экзаменационных оценок в заданном интер-вале. При этом учесть, что сортировка строк должна осуществляться в порядке, обратном величине оценки; сумма значений в столбце количество должна быть равна количеству строк в таблице PROGRESS.
Использовать подзапрос в секции FROM, в подзапросе применить GROUP BY, сор-тировку осуществить во внешнем запросе. В секции GROUP BY, в SELECT-списке подзапроса и в ORDER BY внешнего запро-са применить CASE. */

use UNIVER

Select *
from (select case
                 when (PROGRESS.NOTE in (6, 7)) then '6-7'
                 when (PROGRESS.NOTE in (8, 9)) then '8-9'
                 when (PROGRESS.NOTE in (4, 5)) then '4-5'
                 when (PROGRESS.NOTE = 10) then '10'
                 end  [оценки],
             count(*) [количество]
      from PROGRESS
      group by case
                   when (PROGRESS.NOTE in (6, 7)) then '6-7'
                   when (PROGRESS.NOTE in (8, 9)) then '8-9'
                   when (PROGRESS.NOTE in (4, 5)) then '4-5'
                   when (PROGRESS.NOTE = 10) then '10'
                   end
     ) as a
order by case a.оценки
               when '6-7' then 3
               when '8-9' then 2
               when '4-5' then 4
               when '10' then 1
               end

-----------------------------------------
USE BANK;
SELECT  
 CASE 
WHEN (Оформление.сумма=1000) then '1000р'
WHEN (Оформление.сумма=1020) then '1200р'
end [сумма],
COUNT(*)
FROM Оформление
GROUP BY  CASE
WHEN (Оформление.сумма=1000) then '1000р'
WHEN (Оформление.сумма=1020) then '1200р'
end 
