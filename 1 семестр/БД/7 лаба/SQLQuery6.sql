/*
6. Изменить представление Количе-ство_кафедр, созданное в задании 2 так, чтобы оно 
было привязано к базовым таблицам. Про-демонстрировать свойство привязанности представления к базовым
таблицам. Примеча-ние: использовать опцию SCHEMABINDING. 

*/
USE UNIVER;
GO
ALTER VIEW [Количество кафедр] with schemabinding
AS SELECT FACULTY.FACULTY_NAME [факультет],
COUNT(PULPIT.FACULTY) [количество]
FROM dbo.FACULTY join dbo.PULPIT
ON FACULTY.FACULTY = PULPIT.FACULTY
GROUP BY FACULTY.FACULTY_NAME

SELECT * FROM [Количество кафедр]
-------------------------------------------
USE BANK;
GO
ALTER VIEW [Количество кредитов] with schemabinding
AS SELECT 
БАНК.Назаание_кредита [Название кредита],
COUNT(БАНК.Ставка) [Кол-во]
FROM dbo.БАНК
GROUP BY Назаание_кредита

SELECT * FROM [Количество кредитов]
