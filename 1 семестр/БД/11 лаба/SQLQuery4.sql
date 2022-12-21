	/*4. Разработать два сценария A и B на примере базы данных X_UNIVER. 
Сценарий A представляет собой явную транзакцию с уровнем изолированности READ UNCOMMITED, 
сценарий B – явную транзакцию с уровнем изолированности READ COMMITED (по умолчанию). 
Сценарий A должен демонстрировать, что уровень READ UNCOMMITED допускает неподтвержденное,
неповторяющееся и фантомное чтение. 
*/

USE UNIVER;
GO
------A------
SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED
BEGIN TRANSACTION
-----T1---------
SELECT @@SPID, 'INSERT FACULTY' 'RESULT', *
FROM FACULTY WHERE FACULTY = 'ФИТ';

SELECT @@SPID, 'UPDATE PULPIT' 'RESULT', *
FROM PULPIT WHERE FACULTY = 'ИЭФ';
COMMIT;

ROLLBACK;

SELECT * FROM FACULTY;
SELECT * FROM PULPIT;

-----B–----

BEGIN TRANSACTION
SELECT @@SPID
INSERT FACULTY VALUES('ФИТ','ФАКУЛЬТЕТ ИТ');

UPDATE PULPIT SET FACULTY = 'ИЭФ' WHERE PULPIT = 'ИСИТ'
-----T1----------
-----T2----------
ROLLBACK;

DELETE FACULTY WHERE FACULTY = 'ФИТ';