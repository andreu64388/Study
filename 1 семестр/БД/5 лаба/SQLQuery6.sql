/*6. На основе таблицы PROGRESS сформировать строку,
содержащую сред-ние значения оценок (столбец NOTE) по дисциплинам,
имеющим следующие коды: ОАиП, БД и СУБД. Примечание: исполь-зовать три
некоррелированных подзапроса в списке SELECT; 
в подзапросах приме-нить агрегатные функции AVG. 
*/
use UNIVER;
SELECT 
top(1)
(SELECT  AVG(NOTE) FROM PROGRESS WHERE [SUBJECT] = 'ОАиП') AS 'ОАиП',
(SELECT AVG(NOTE) FROM PROGRESS WHERE [SUBJECT] = 'КГ') AS 'КГ',
(SELECT  AVG(NOTE) FROM PROGRESS WHERE [SUBJECT] = 'СУБД') AS 'СУБД'
FROM PROGRESS;



