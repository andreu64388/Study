---B---
USE UNIVER;
GO
BEGIN TRANSACTION
SELECT @@SPID
INSERT SUBJECT VALUES ('TEST', 'TEST', '»—»“');

--------------------- T1 --------------------
--------------------- T2 --------------------
ROLLBACK TRAN;
--COMMIT TRAN;
