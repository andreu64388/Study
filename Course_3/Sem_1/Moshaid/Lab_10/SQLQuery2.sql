use LABA_11;
go

exec sp_configure 'show advanced options', 1;
go 
reconfigure
go 
exec sp_configure 'clr enabled',1;
exec sp_configure 'clr strict security', 0

DECLARE @result FLOAT;

EXEC dbo.CalculateAverageWithoutMinMax
    @values = '1,2,3,4,5',
    @result = @result OUTPUT;

SELECT @result AS Result;



DECLARE @result FLOAT;

SELECT @result = dbo.CalculateAverageWithoutx('1,2,3,4,5');

SELECT @result AS Result;


CREATE TABLE PassportTable
(
    ID INT PRIMARY KEY,
    Passport PassportData
);

INSERT INTO PassportTable (ID, Passport)
VALUES (1, 'AB 123456');


SELECT * FROM PassportTable;
EXEC sp_configure 'show advanced options', 1;
RECONFIGURE;
EXEC sp_configure 'clr enabled', 1;
RECONFIGURE;


-- ¬ызов хранимой процедуры
EXEC dbo.ReadDataFromFile 'file:///E:\student\learn\3_course\1_sem\ћ—’ќијƒ\Lab_10\test.txt';
ALTER DATABASE LABA_11 SET TRUSTWORTHY ON;

EXEC dbo.ReadDataFromFile 'file:///E:\student\learn\3_course\1_sem\ћ—’ќијƒ\Lab_10\', 'test.txt';



ALTER  ASSEMBLY 'PASHA_Lab_10' WITH PERMISSION_SET = EXTERNAL_ACCESS;
