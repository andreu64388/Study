/*2. ����� ��������� PSUBJECT � ������� ���-��������� �������� (Object Explorer) 
SSMS � ����� ����������� ���� ������� �������� �� ��������� ���-������ ���������� ALTER.
�������� ��������� PSUBJECT, ��������� � ��-����� 1, ����� �������, ����� ��� ��������� 
��� ��-������� � ������� @p � @c. �������� @p �������� �������, ����� ��� VARCHAR(20) �
�������� �� ��������� NULL. �������� @� �������� ��������, ����� ��� INT.
��������� PSUBJECT ������ ����������� ��-������������ �����, ����������� ������,
��������-������� �� ������� ����, �� ��� ���� ��������� ������, ��������������� ���� �������
, ��������� ���������� @p. ����� ����, ��������� ������ ���-�������� �������� ��������� ��������� @�, 
������ ���������� ����� � �������������� ������, � ����� ���������� �������� � ����� ������,
������ ������ ���������� ��������� (���������� ����� � ������� SUBJECT). 
*/
------------------------------------------------
----------------------UNVER---------------------
------------------------------------------------
USE UNIVER;
GO
ALTER PROCEDURE PSUBJECT @P VARCHAR(20) = NULL, @C INT OUTPUT
 AS
   BEGIN
 SELECT * FROM SUBJECT WHERE SUBJECT.SUBJECT = @P;
 SET @C = @@ROWCOUNT;
 DECLARE @K INT = (SELECT COUNT(*) FROM SUBJECT);
 PRINT '���������: @P='+@P+', @C='+CAST(@C AS VARCHAR(3));
 RETURN @K;
   END

DECLARE @N INT, @A INT,@X NVARCHAR(20);
EXEC @N = PSUBJECT '���', @A OUTPUT ;
PRINT CAST(@A AS NVARCHAR(4))
PRINT CAST(@N AS NVARCHAR(4))

------------------------------------------------
----------------------BANK----------------------
------------------------------------------------
USE BANK;
GO
ALTER PROCEDURE PBANK @ID INT, @C_ INT OUTPUT
 AS
   BEGIN
SELECT * FROM ������ WHERE ID_CLIENT = @ID;
 SET @C_ = @@ROWCOUNT;
 DECLARE @K_ INT = (SELECT COUNT(*) FROM ������);
 RETURN @K_;
   END

DECLARE @N INT, @A INT,@X NVARCHAR(20);
EXEC @N = PBANK 10, @A OUTPUT ;
PRINT CAST(@A AS NVARCHAR(4))
PRINT CAST(@N AS NVARCHAR(4))