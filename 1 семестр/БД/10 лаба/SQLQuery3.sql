/*3. Разработать сценарий, демонстри-рующий отличие статических курсоров от динамических
на примере базы дан-ных X_UNIVER.*/
USE UNIVER
DECLARE @PUL CHAR(10), @GEN CHAR(2), @NAME CHAR(30);
DECLARE TEACHERS CURSOR LOCAL STATIC FOR SELECT PULPIT, GENDER, TEACHER_NAME FROM TEACHER WHERE PULPIT='ИСИТ';
OPEN TEACHERS;
PRINT 'КОЛИЧЕСТВО СТРОК: '+CAST(@@CURSOR_ROWS AS VARCHAR(5));

INSERT INTO TEACHER  (TEACHER,   TEACHER_NAME, GENDER, PULPIT )
VALUES ('КВВ','КОРЕНЧУК ВЛАДИМИР ВЛАДИСЛАВОВИЧ', 'М', 'ИСИТ');
UPDATE TEACHER SET TEACHER_NAME = 'КОРЕНЧУК АНДРЕЙ ВАСИЛЬЕВИЧ' WHERE TEACHER = 'КВВ';
FETCH TEACHERS INTO @PUL, @GEN, @NAME;
PRINT 'ПРЕПОДАВАТЕЛЬ: '+RTRIM(@PUL)+' '+RTRIM(@GEN)+' '+RTRIM(@NAME);
WHILE @@FETCH_STATUS=0
BEGIN
FETCH TEACHERS INTO @PUL, @GEN, @NAME;
PRINT 'ПРЕПОДАВАТЕЛЬ: '+RTRIM(@PUL)+' '+RTRIM(@GEN)+' '+RTRIM(@NAME);
END;
CLOSE TEACHERS;
DELETE TEACHER WHERE TEACHER = 'КВВ';