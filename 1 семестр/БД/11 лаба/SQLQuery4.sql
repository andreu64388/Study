	/*4. Разработать два сценария A и B на примере базы данных X_UNIVER. 
Сценарий A представляет собой явную транзакцию с уровнем изолированности READ UNCOMMITED, 
сценарий B – явную транзакцию с уровнем изолированности READ COMMITED (по умолчанию). 
Сценарий A должен демонстрировать, что уровень READ UNCOMMITED допускает неподтвержденное,
неповторяющееся(Неподтвержденное чтение)и фантомное чтение. 
*/

USE UNIVER;
GO
-----A------

SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED
SELECT @@SPID
BEGIN TRANSACTION
------------------ T1 ------------------
SELECT * FROM SUBJECT WHERE SUBJECT = 'TEST';
ROLLBACK TRAN;

--COMMIT TRAN;
-------t2---------

