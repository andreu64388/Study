/* 1. С ПОМОЩЬЮ СЦЕНАРИЯ, ПРЕДСТАВЛЕННОГО НА РИСУНКЕ, СОЗДАТЬ ТАБЛИЦУ TR_AUDIT.
ТАБЛИЦА ПРЕДНАЗНАЧЕНА ДЛЯ ДОБАВЛЕНИЯ В НЕЕ СТРОК ТРИГГЕРАМИ. 
В СТОЛБЕЦ STMT ТРИГГЕР ДОЛЖЕН ПОМЕСТИТЬ СОБЫТИЕ, НА КОТОРОЕ ОН СРЕАГИРОВАЛ, А В СТОЛ-БЕЦ TRNAME  СОБСТВЕННОЕ ИМЯ. 
РАЗРАБОТАТЬ AFTER-ТРИГГЕР С ИМЕНЕМ TR_TEACHER_INS ДЛЯ ТАБЛИЦЫ TEACHER, РЕАГИРУЮЩИЙ НА СОБЫТИЕ INSERT. ТРИГГЕР ДОЛЖЕН ЗАПИСЫВАТЬ
СТРОКИ ВВОДИМЫХ ДАННЫХ В ТАБЛИЦУ TR_AUDIT. В СТОЛБЕЦ СС ПОМЕЩА-ЮТСЯ ЗНАЧЕНИЯ СТОЛБЦОВ ВВОДИМОЙ СТРОКИ. 
*/

--------------------------------------------
------------------UNIVER--------------------
--------------------------------------------
USE UNIVER;
GO

CREATE TABLE TR_AUDIT
(
ID INT IDENTITY,
STMT VARCHAR(20)
CHECK (STMT IN ('INS', 'DEL', 'UPD')),
TRNAME VARCHAR(50),
CC VARCHAR(300)
)
DROP TRIGGER TR_TEACHER_INS

 CREATE TRIGGER TR_TEACHER_INS
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

INSERT INTO TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT)
VALUES ('КРАВ','КОРЕНЧУК АНДРЕЙ ВАСИЛЬЕВИЧ','М','ИСИТ')

DELETE FROM TEACHER 
WHERE TEACHER = 'КРАВ'

SELECT * FROM TR_AUDIT

--------------------------------------------
--------------------BANK--------------------
--------------------------------------------

USE BANK;
GO 
CREATE TABLE TR_BANK
(
ID INT IDENTITY,
STMT VARCHAR(20)
CHECK (STMT IN ('INS', 'DEL', 'UPD')),
TRNAME VARCHAR(50),
CC VARCHAR(300)
)

 CREATE TRIGGER TR_BANK_FIRST
      ON БАНК AFTER INSERT
      AS
      DECLARE @A1 INT, @A2 VARCHAR(100), @A3 INT , @IN VARCHAR(300);
      PRINT 'ВСТАВКА';
      SET @A1 = (SELECT ID FROM INSERTED);
      SET @A2= (SELECT НАЗААНИЕ_КРЕДИТА FROM INSERTED);
      SET @A3= (SELECT СТАВКА FROM INSERTED);
      SET @IN = CAST(@A1 AS NVARCHAR)+' '+ @A2 +' '+  CAST(@A3 AS NVARCHAR);
      INSERT INTO TR_BANK(STMT, TRNAME, CC)
      VALUES('INS', 'TR_BANK_INS', @IN);
      RETURN;
      GO

	  SELECT * FROM БАНК
	  INSERT INTO БАНК (ID,НАЗААНИЕ_КРЕДИТА,СТАВКА)
	  VALUES (6,'LOW',32)

DELETE FROM БАНК
WHERE ID = 6

SELECT * FROM TR_BANK