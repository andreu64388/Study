/*7. –азработать два сценари€ A и B на примере базы данных X_UNIVER. 
—ценарий A представл€ет собой €вную транзакцию с уровнем изолированности SERIALIZABLE. 
—ценарий B Ц €вную транзакцию с уровнем изолированности READ COMMITED.
—ценарий A должен демонстрировать отсутствие фантомного, неподтвержденного и неповтор€ющегос€
чтени€. (проблемы изолированности решены)
*/
USE UNIVER;
GO
-- A ---
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE
BEGIN TRANSACTION
SELECT * FROM SUBJECT;
-------------------------- T1 -----------------
-------------------------- T2 ------------------
SELECT * FROM SUBJECT;
COMMIT TRAN;

rollback

rollback
