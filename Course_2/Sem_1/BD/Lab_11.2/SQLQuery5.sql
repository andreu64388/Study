
USE UNIVER
GO

--- B ---
BEGIN TRANSACTION
-------------------------- T1 --------------------
UPDATE SUBJECT SET SUBJECT_NAME = 'хглемем32'  WHERE SUBJECT = 'ад';
COMMIT TRAN;
-------------------------- T2 --------------------ROLLBACK TRAN;
rollback