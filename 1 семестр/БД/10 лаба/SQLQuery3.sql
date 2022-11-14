/*3. Разработать сценарий, демонстри-рующий отличие статических курсоров от динамических
на примере базы дан-ных X_UNIVER.*/


-------------------------------------------------------
------------------------STATIC-------------------------
-------------------------------------------------------

USE UNIVER
DECLARE @PUL CHAR(10), @GEN CHAR(2), @NAME CHAR(30);
DECLARE TEACHERS CURSOR LOCAL STATIC FOR SELECT PULPIT,
GENDER, TEACHER_NAME FROM TEACHER WHERE PULPIT='ИСИТ';

OPEN TEACHERS;
PRINT 'КОЛИЧЕСТВО СТРОК: '+CAST(@@CURSOR_ROWS AS VARCHAR(5));
INSERT INTO TEACHER  (TEACHER,   TEACHER_NAME, GENDER, PULPIT )
VALUES ('КВВ','КОРЕНЧУК ВЛАДИМИР ВЛАДИСЛАВОВИЧ', 'М', 'ИСиТ');
UPDATE TEACHER SET TEACHER_NAME = 'КОРЕНЧУК АНДРЕЙ ВАСИЛЬЕВИЧ' WHERE TEACHER = 'КВВ';
FETCH TEACHERS INTO @PUL, @GEN, @NAME;
WHILE @@FETCH_STATUS=0
BEGIN
FETCH TEACHERS INTO @PUL, @GEN, @NAME;
PRINT 'ПРЕПОДАВАТЕЛЬ: '+RTRIM(@PUL)+' '+RTRIM(@GEN)+' '+RTRIM(@NAME);
END;
CLOSE TEACHERS;
DELETE TEACHER WHERE TEACHER = 'КВВ';

-------------------------------------------------------
-----------------------DYNAMIC-------------------------
-------------------------------------------------------

DECLARE @PUL_ CHAR(10), @GEN_ CHAR(2), @NAME_ CHAR(30);
DECLARE TEACHERS CURSOR LOCAL DYNAMIC FOR SELECT PULPIT,
GENDER, TEACHER_NAME FROM TEACHER WHERE PULPIT='ИСИТ';

OPEN TEACHERS;
PRINT 'КОЛИЧЕСТВО СТРОК: '+CAST(@@CURSOR_ROWS AS VARCHAR(5));
INSERT INTO TEACHER  (TEACHER,   TEACHER_NAME, GENDER, PULPIT )
VALUES ('КВВ','КОРЕНЧУК ВЛАДИМИР ВЛАДИСЛАВОВИЧ', 'М', 'ИСиТ');
UPDATE TEACHER SET TEACHER_NAME = 'КОРЕНЧУК АНДРЕЙ ВАСИЛЬЕВИЧ' WHERE TEACHER = 'КВВ';
FETCH TEACHERS INTO @PUL_, @GEN_, @NAME_;
WHILE @@FETCH_STATUS=0
BEGIN
FETCH TEACHERS INTO @PUL_, @GEN_, @NAME_;
PRINT 'ПРЕПОДАВАТЕЛЬ: '+RTRIM(@PUL_)+' '+RTRIM(@GEN_)+' '+RTRIM(@NAME_);
END;
CLOSE TEACHERS;
DELETE TEACHER WHERE TEACHER = 'КВВ';



---------------------------------------
---------------BANK--------------------
---------------------------------------

USE BANK;
GO 
DECLARE @id int, @Назаание_кредита NVARCHAR(20), @СТАВКА INT;
DECLARE BANK_ CURSOR LOCAL STATIC FOR SELECT id,Назаание_кредита,Ставка FROM БАНК

OPEN BANK_;
PRINT 'КОЛИЧЕСТВО СТРОК: '+CAST(@@CURSOR_ROWS AS VARCHAR(5));
INSERT INTO БАНК(id,Назаание_кредита,Ставка)
VALUES (4,'NOT',32)
UPDATE БАНК SET Ставка = 3 WHERE id = 4;
FETCH BANK_ INTO @id, @Назаание_кредита, @СТАВКА;
WHILE @@FETCH_STATUS=0
BEGIN
FETCH BANK_ INTO @id, @Назаание_кредита, @СТАВКА;
PRINT 'Ставка: '+RTRIM(@id)+' '+RTRIM(@Назаание_кредита)+' '+RTRIM(@СТАВКА);
END;
CLOSE BANK_;

DEALLOCATE BANK_
DELETE БАНК WHERE id = 4