/*1. Разработать сценарий, формиру-ющий список дисциплин на кафедре ИСиТ.
В отчет должны быть выведены краткие названия (поле SUBJECT) из таблицы SUBJECT 
в одну строку через запятую. 
Использовать встроенную функцию RTRIM.*/

 ---------------------------------------
 ---------------UNIVER------------------
 ---------------------------------------
USE UNIVER

DECLARE @ONE NVARCHAR(20), @ALL NVARCHAR(300) = '';
DECLARE LINES CURSOR FOR SELECT SUBJECT FROM SUBJECT

OPEN LINES
FETCH LINES INTO @ONE
PRINT 'ВЫВОД КОДОВ ПРЕДМЕТОВ В СТРОКУ'
WHILE @@FETCH_STATUS = 0
BEGIN
SET @ALL = RTRIM(@ONE) + ', ' + @ALL 
FETCH LINES INTO @ONE
END
PRINT RTRIM(@ALL) + ' КОНЕЦ ПЕРЕЧИСЛЕНИЯ.'
CLOSE LINES
 


 ---------------------------------------
 ---------------BANK--------------------
 ---------------------------------------

USE BANK;
GO 
DECLARE @TWO NVARCHAR(20), @ALL_TWO NVARCHAR(300) = '';
DECLARE LINES_T CURSOR FOR SELECT Назаание_кредита FROM БАНК
OPEN LINES_T
FETCH LINES_T INTO @TWO
PRINT 'ВЫВОД КРЕДИТОВ В СТРОКУ'
WHILE @@FETCH_STATUS = 0
BEGIN
SET @ALL_TWO = RTRIM(@TWO) + ', ' + @ALL_TWO
FETCH LINES_T INTO @TWO
END
PRINT RTRIM(@ALL_TWO) + ' КОНЕЦ ПЕРЕЧИСЛЕНИЯ.'
CLOSE LINES_T
 


