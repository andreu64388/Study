/*1. ����������� �������� ��������� ��� ���������� � ������ PSUBJECT.
��������� ��������� ��������-������ ����� �� ������ ������� SUBJECT, �����-������ ������,
��������������� �� �������: 
� ����� ������ ��������� ������ ���������� ��-�������� �����, ���������� � �������������� �����.
*/

------------------------------------------------
----------------------UNVER---------------------
------------------------------------------------
USE UNIVER;
GO
CREATE PROCEDURE PSUBJECT
AS
BEGIN
DECLARE @K INT=(SELECT COUNT(*) FROM SUBJECT);
SELECT SUBJECT [���], SUBJECT_NAME [����������], PULPIT [�������] FROM SUBJECT;
RETURN @K;
END;

EXEC @N = PSUBJECT;

DECLARE @I INT=0;
EXEC @I=PSUBJECT;
PRINT '���������� ���������: '+CAST(@I AS VARCHAR(3));

--DROP PROCEDURE PSUBJECT;

------------------------------------------------
----------------------BANK----------------------
------------------------------------------------
USE BANK;
GO 
CREATE PROCEDURE PBANK 
 AS 
 BEGIN 
   DECLARE @COUNTS_ INT = (SELECT COUNT(*) FROM ������)
   SELECT * FROM ������
   RETURN @COUNTS_
 END
 

DECLARE @T INT;
EXEC @T= PBANK
PRINT @T
--DROP PROCEDURE PBANK;
