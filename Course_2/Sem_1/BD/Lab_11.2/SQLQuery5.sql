
USE UNIVER
GO

--- B ---
BEGIN TRANSACTION
-------------------------- T1 --------------------
UPDATE SUBJECT SET SUBJECT_NAME = '�������32'  WHERE SUBJECT = '��';
COMMIT TRAN;
-------------------------- T2 --------------------ROLLBACK TRAN;
rollback