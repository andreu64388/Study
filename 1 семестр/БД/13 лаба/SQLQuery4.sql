/*
4. �� ������� ���� ������� ��������, ��������������� ������ ��������� ������� FCTEACHER.
������� �����-���� ���� ��������, �������� ��� �������. ������� ���-������� ���������� ��������������
�� �������� �������-��� �������.
���� �������� ����� NULL, �� ������������ ����� ���������� ��������������. */
USE UNIVER
GO
CREATE FUNCTION FCTEACHER(@PUL NVARCHAR(10)) RETURNS INT AS
    BEGIN
        DECLARE @COUNT INT=(SELECT COUNT(*) FROM TEACHER
        WHERE PULPIT=ISNULL(@PUL, PULPIT));
        RETURN @COUNT;
    END;
GO
-- DROP FUNCTION FCTEACHER;

SELECT PULPIT, DBO.FCTEACHER(PULPIT) [���������� ��������������] FROM PULPIT;

SELECT DBO.FCTEACHER(NULL) [����� ��������������];

 ---------------------------------------
 ---------------BANK--------------------
 ---------------------------------------
USE BANK
GO
CREATE FUNCTION FBAKR(@ID INT) RETURNS INT AS
    BEGIN
        DECLARE @COUNT INT=(SELECT COUNT(*) FROM ����
        WHERE ID =ISNULL(@ID, ID));
        RETURN @COUNT;
    END;
GO

SELECT DBO.FBAKR(NULL) [����� ������];

SELECT DBO.FBAKR(1) [����� ������];

