/*2. Разработать сценарий, демонстри-рующий отличие глобального курсора от локального на 
примере базы данных X_UNIVER.*/


------------------------------------------------------
-----------------------LOCAL-------------------------
------------------------------------------------------

USE UNIVER;
DECLARE LINESLOCAL CURSOR LOCAL FOR SELECT SUBJECT FROM SUBJECT
DECLARE @FIRST NVARCHAR(10), @ALL NVARCHAR(200) = ' ';

OPEN LINESLOCAL
FETCH LINESLOCAL INTO @FIRST
PRINT '1. ' + @FIRST
GO

DECLARE @FIRST NVARCHAR(20), @ALL NVARCHAR(300) = '';
FETCH LINESLOCAL INTO @FIRST --A CURSOR WITH THE NAME 'LINESLOCAL' DOES NOT EXIST.
PRINT '2. ' + @FIRST
GO   
------------------------------------------------------
-----------------------GLOBAL-------------------------
------------------------------------------------------

DECLARE GLOB CURSOR GLOBAL FOR SELECT SUBJECT FROM SUBJECT
DECLARE @SUB1 NVARCHAR(20);
OPEN GLOB;
FETCH GLOB INTO @SUB1;
PRINT RTRIM(@SUB1)+' - ПРЕДМЕТ';
GO
DECLARE @SUB2 NVARCHAR(20);
FETCH GLOB INTO @SUB2;
PRINT RTRIM(@SUB2)+' - ПРЕДМЕТ';
GO
DECLARE @SUB3 NVARCHAR(30);
FETCH GLOB INTO @SUB3;
PRINT RTRIM(@SUB3)+' - ПРЕДМЕТ';
CLOSE GLOB;

DEALLOCATE GLOB; 


---------------------------------------
---------------BANK--------------------
---------------------------------------

USE BANK;
GO 
DECLARE GLOB_B CURSOR GLOBAL FOR SELECT Назаание_кредита FROM БАНК
DECLARE @STAVKA1 NVARCHAR(20);
OPEN GLOB_B;
FETCH GLOB_B INTO @STAVKA1;
PRINT RTRIM(@STAVKA1)+' - СТАВКА';
GO
DECLARE @STAVKA2 NVARCHAR(20);
FETCH GLOB_B INTO @STAVKA2;
PRINT RTRIM(@STAVKA2)+' - СТАВКА';
GO
DECLARE @STAVKA3 NVARCHAR(30);
FETCH GLOB_B INTO @STAVKA3;
PRINT RTRIM(@STAVKA3)+' - СТАВКА';
CLOSE GLOB_B;

DEALLOCATE GLOB_B; 
