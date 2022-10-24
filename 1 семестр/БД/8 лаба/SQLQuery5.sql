/*
5. Продемонстрировать конструкцию IF… ELSE на примере анализа данных таблиц базы данных Х_UNIVER.*/


use UNIVER;

IF (SELECT MAX(AUDITORIUM_CAPACITY) FROM AUDITORIUM )= 90 
BEGIN
PRINT '90 MAX SIZE'
END
ELSE PRINT '> THAN 90'