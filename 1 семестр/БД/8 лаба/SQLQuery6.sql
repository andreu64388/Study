/*6. Разработать сценарий, в котором с помощью CASE анализируются оценки, полученные
студентами некоторого фа-культета при сдаче экзаменов.*/

USE UNIVER;

SELECT (CASE
WHEN NOTE BETWEEN 0 AND 3 THEN 'НЕ СДАЛ'
WHEN NOTE BETWEEN 4 AND 5 THEN 'ПЛОХО'
WHEN NOTE BETWEEN 6 AND 7 THEN 'НОРМАЛЬНО'
WHEN NOTE BETWEEN 8 AND 10 THEN 'ХОРОШО'
END) ОЦЕНКА, COUNT(*) [КОЛИЧЕСТВО] FROM PROGRESS
GROUP BY (CASE
WHEN NOTE BETWEEN 0 AND 3 THEN 'НЕ СДАЛ'
WHEN NOTE BETWEEN 4 AND 5 THEN 'ПЛОХО'
WHEN NOTE BETWEEN 6 AND 7 THEN 'НОРМАЛЬНО'
WHEN NOTE BETWEEN 8 AND 10 THEN 'ХОРОШО'
END)
