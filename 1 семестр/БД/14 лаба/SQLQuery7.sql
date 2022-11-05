/*7. Разработать сценарий, демонстрирующий на примере базы данных X_UNIVER утвер-ждение:
AFTER-триггер является частью тран-закции,
в рамках которого выполняется опера-тор, активизировавший триггер.*/

USE UNIVER

GO
	CREATE TRIGGER PTRAN
	ON PULPIT AFTER INSERT, DELETE, UPDATE
	AS DECLARE @C INT = (SELECT COUNT (*) FROM PULPIT);
	 IF (@C >18)
	 BEGIN
       RAISERROR('ОБЩАЯ КОЛИЧЕСТВО КАФЕДР НЕ МОЖЕТ БЫТЬ >26', 10, 1);
	 ROLLBACK;
	 END;
	 RETURN;

INSERT INTO PULPIT(PULPIT) VALUES ('ТТПЛ');