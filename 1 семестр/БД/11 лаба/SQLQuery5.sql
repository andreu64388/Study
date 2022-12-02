/*5. Разработать два сценария A и B на примере базы данных X_UNIVER. 
Сценарии A и В  представля-ют собой явные транзакции с уровнем изолированности READ COMMITED. 
Сценарий A должен демон-стрировать, что уровень READ COMMITED не допускает не-подтвержденного 
чтения, но при этом возможно неповторя-ющееся и фантомное чтение. 
*/

USE UNIVER;
-- A ---
SET TRANSACTION ISOLATION LEVEL READ COMMITTED
BEGIN TRANSACTION
SELECT * FROM SUBJECT WHERE SUBJECT = 'БД';
-------------------------- T1 ------------------
-------------------------- T2 -----------------
SELECT * FROM SUBJECT WHERE SUBJECT = 'БД';
COMMIT TRAN;

-----B----
BEGIN TRANSACTION
------T1-----
UPDATE PULPIT SET FACULTY = 'ИТ' WHERE PULPIT = 'ТЛ';
------T2------
ROLLBACK
