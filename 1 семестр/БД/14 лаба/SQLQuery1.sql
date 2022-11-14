/* 1. С ПОМОЩЬЮ СЦЕНАРИЯ, ПРЕДСТАВЛЕННОГО НА РИСУНКЕ, СОЗДАТЬ ТАБЛИЦУ TR_AUDIT.
 
ТАБЛИЦА ПРЕДНАЗНАЧЕНА ДЛЯ ДОБАВЛЕНИЯ В НЕЕ СТРОК ТРИГГЕРАМИ. 
В СТОЛБЕЦ STMT ТРИГГЕР ДОЛЖЕН ПОМЕСТИТЬ СОБЫТИЕ, НА КОТОРОЕ ОН СРЕАГИРОВАЛ, А В СТОЛ-БЕЦ TRNAME  СОБСТВЕННОЕ ИМЯ. 

РАЗРАБОТАТЬ AFTER-ТРИГГЕР С ИМЕНЕМ TR_TEACHER_INS ДЛЯ ТАБЛИЦЫ TEACHER, РЕАГИРУЮЩИЙ НА СОБЫТИЕ INSERT. ТРИГГЕР ДОЛЖЕН ЗАПИСЫВАТЬ СТРОКИ ВВОДИМЫХ ДАННЫХ В ТАБЛИЦУ TR_AUDIT. В СТОЛБЕЦ СС ПОМЕЩА-ЮТСЯ ЗНАЧЕНИЯ СТОЛБЦОВ ВВОДИМОЙ СТРОКИ. 
*/

USE UNIVER;
GO

CREATE TABLE TR_AUDIT
(
ID INT IDENTITY,
STMT VARCHAR(20)
CHECK (STMT IN ('INS', 'DEL', 'UPD')),
TRNAME VARCHAR(50), --Имя триггера
CC VARCHAR(300)
)
DROP TRIGGER TR_TEACHER_INS

 CREATE  TRIGGER TR_TEACHER_INS
      ON TEACHER AFTER INSERT
      AS
      DECLARE @A1 CHAR(10), @A2 VARCHAR(100), @A3 CHAR(1), @A4 CHAR(20), @IN VARCHAR(300);
      PRINT 'ВСТАВКА';
      SET @A1 = (SELECT TEACHER FROM INSERTED);
      SET @A2= (SELECT TEACHER_NAME FROM INSERTED);
      SET @A3= (SELECT GENDER FROM INSERTED);
	  SET @A4 = (SELECT PULPIT FROM INSERTED);
      SET @IN = @A1+' '+ @A2 +' '+ @A3+ ' ' +@A4;
      INSERT INTO TR_AUDIT(STMT, TRNAME, CC)
                            VALUES('INS', 'TR_TEACHER_INS', @IN);
      RETURN;
      GO

	
INSERT INTO TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT) VALUES
('КРАВ','КОРЕНЧУК АНДРЕЙ ВАСИЛЬЕВИЧ','М','ИСИТ')
DELETE FROM TEACHER 
WHERE TEACHER = 'КРАВ'

SELECT * FROM TR_AUDIT