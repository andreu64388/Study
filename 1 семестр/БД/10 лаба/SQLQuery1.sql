/*1. Разработать сценарий, формиру-ющий список дисциплин на кафедре ИСиТ.
В отчет должны быть выведены краткие названия (поле SUBJECT) из таблицы SUBJECT в одну строку через запятую. 
Использовать встроенную функцию RTRIM.*/

USE UNIVER

DECLARE LINES CURSOR FOR SELECT SUBJECT FROM SUBJECT
DECLARE @ONE NVARCHAR(10), @ALL NVARCHAR(200) = ' ';

OPEN LINES
FETCH LINES INTO @ONE
PRINT 'ВЫВОД КОДОВ ПРЕДМЕТОВ В СТРОКУ'
WHILE @@FETCH_STATUS = 0
BEGIN
SET @ALL = RTRIM(@ONE) + ', ' + @ALL -- УДАЛЕНИЕ ПРОБЕЛОВ В КОНЦЕ СТРОКИ
FETCH LINES INTO @ONE
END
PRINT RTRIM(@ALL) + ' КОНЕЦ ПЕРЕЧИСЛЕНИЯ.'
CLOSE LINES

DEALLOCATE LINES