/*2. Разработать скрипт, в котором определяется общая вместимость ауди-торий. 
Когда общая вместимость пре-вышает 200, то вывести количество аудиторий, среднюю вместимость ауди-торий,
количество аудиторий, вмести-мость которых меньше средней, и про-цент таких аудиторий. Когда общая вместимость
аудиторий меньше 200, то вывести сообщение о размере общей вместимости.*/
USE UNIVER;

DECLARE 
@CAPACITY INT = (SELECT SUM(AUDITORIUM_CAPACITY) FROM AUDITORIUM),
@TOTAL INT,
@AVGCAPACITY INT,
@TOTALLESS INT,
@PROCENT NUMERIC(4,2);


IF @CAPACITY > 200
BEGIN
SET @TOTAL = (SELECT COUNT(*) FROM AUDITORIUM);
SET @AVGCAPACITY = (SELECT AVG(AUDITORIUM_CAPACITY) FROM AUDITORIUM);
SET @TOTALLESS= (SELECT COUNT(*) FROM AUDITORIUM
WHERE AUDITORIUM_CAPACITY < @AVGCAPACITY);
SET @PROCENT = @TOTALLESS * 100 / @TOTAL;
SELECT @CAPACITY [ВМЕСТИМОСТЬ],
@TOTAL [ВСЕГО АУДИТОРИЙ],
@AVGCAPACITY [СРЕДНЯЯ ВМЕСТИМОСТЬ],
@TOTALLESS [АУДИТОРИЙ НИЖЕ СТРЕДНЕГО КОЛ-ВО],
@PROCENT [ПРОЦЕНТ]
END

ELSE PRINT 'ОБЩАЯ ВМЕСТИМОСТЬ < 200'

