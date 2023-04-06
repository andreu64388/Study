
/*
1. Разработать представление с именем Пре-подаватель. Представление должно быть по-строено
на основе SELECT-запроса к таблице TEACHER и содержать следующие столбцы:
код (TEACHER), имя преподавателя (TEACHER_NAME),
пол (GENDER), код кафедры (PULPIT). */
USE UNIVER;
GO
CREATE VIEW [Преподаватель] 
AS SELECT 
TEACHER.TEACHER [Код],
TEACHER.TEACHER_NAME [Имя преподавателя],
TEACHER.GENDER [Пол],
TEACHER.PULPIT [Код кафедры]
FROM TEACHER;

SELECT * FROM [Преподаватель]
GO
DROP VIEW [Преподаватель]

-------------------------------------

USE BANK;
GO
CREATE VIEW [Банки] 
AS SELECT БАНК.id [Код],
БАНК.Назаание_кредита [Название кредита],
БАНК.Ставка [Ставка]
FROM БАНК;

SELECT * FROM [Банки]

GO
DROP VIEW [Банки]