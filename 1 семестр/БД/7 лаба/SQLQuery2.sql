/*
Разработать и создать представление с именем Количество кафедр. Представление должно
быть построено на основе SELECT-запроса к таблицам FACULTY и PULPIT.
Представление должно содержать следую-щие столбцы: факультет (FACUL-TY.FACULTY_ NAME),
количество кафедр (вычисляется на основе строк таблицы PULPIT). 
 
*/
USE UNIVER;
GO
CREATE VIEW [Количество кафедр]
AS SELECT
FACULTY.FACULTY_NAME [Факультет],
COUNT(PULPIT.PULPIT)[Количество кафедр]
FROM FACULTY 
JOIN PULPIT ON FACULTY.FACULTY=PULPIT.FACULTY
GROUP BY FACULTY_NAME

SELECT * FROM [Количество кафедр];
-----------------------------------------------
USE BANK;
GO
CREATE VIEW [Количество кредитов] 
AS SELECT 
БАНК.Назаание_кредита [Название кредита],
COUNT(БАНК.Ставка) [Кол-во]
FROM БАНК
GROUP BY Назаание_кредита

SELECT * FROM [Количество кредитов]

GO
DROP VIEW [Количество кредитов]