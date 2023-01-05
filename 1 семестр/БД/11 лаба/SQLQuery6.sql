/*6. –азработать два сценари€ A и B на примере базы данных X_UNIVER. ((фантомное чтение))
—ценарий A представл€ет собой €вную транзакцию с уровнем изолированности REPEATABLE READ. 
—ценарий B Ц €вную транзакцию с уровнем изолированности READ COMMITED. 
—ценарий A должен демонстрировать, что уровень REAPETABLE READ не допускает неподтвержденного
чтени€ и неповтор€ющегос€ чтени€, но при этом возможно фантомное чтение. 
*/
USE UNIVER;
GO
-- A ---
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ
BEGIN TRANSACTION
SELECT COUNT(*) FROM SUBJECT WHERE SUBJECT = 'TEST';
-------------------------- T1 ------------------
-------------------------- T2 -----------------
SELECT COUNT(*) FROM SUBJECT WHERE SUBJECT = 'TEST';
COMMIT TRAN;
rollback



