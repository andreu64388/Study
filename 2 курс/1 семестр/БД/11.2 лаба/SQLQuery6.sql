USE UNIVER
GO

--- B ---
BEGIN TRANSACTION
-------------------------- T1 --------------------
--DELETE FROM SUBJECT WHERE SUBJECT = 'TEST';
INSERT SUBJECT VALUES ('TEST', 'TEST', '»—»“');

COMMIT TRAN;
rollback

