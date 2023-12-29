/*
5 Дисциплины. Представление должно быть по-строено на основе SELECT-запроса к таблице SUBJECT
, отображать все дисциплины в ал-фавитном порядке и содержать следующие столбцы: код (SUBJECT)
, наименование дис-циплины (SUBJECT_NAME) и код кафедры (PULPIT). Использовать TOP и ORDER BY.*/
USE UNIVER
GO
CREATE VIEW [Дисциплины] 
AS  SELECT  TOP(100) 
SUBJECT,
SUBJECT_NAME,  
PULPIT
FROM SUBJECT
ORDER BY SUBJECT_NAME
GO
SELECT * FROM [Дисциплины];

DROP VIEW [Дисциплины]
-----------------------------------
USE BANK;
GO
CREATE VIEW [Test_bank] 
AS SELECT 
TOP(100)
БАНК.Назаание_кредита 
FROM БАНК

SELECT * FROM [Test_bank]

DROP VIEW [Test_bank]

