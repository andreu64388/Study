/*
4. �� ������� ���� ������� ��������, ��������������� ������ ��������� ������� FCTEACHER.
������� �����-���� ���� ��������, �������� ��� �������. ������� ���-������� ���������� ��������������
�� �������� �������-��� �������.
���� �������� ����� NULL, �� ������������ ����� ���������� ��������������. */
USE UNIVER;
CREATE FUNCTION FCTEACHER(@PUL NVARCHAR(10)) RETURNS INT AS
    BEGIN
        DECLARE @COUNT INT=(SELECT COUNT(*) FROM TEACHER
        WHERE PULPIT=ISNULL(@PUL, PULPIT));
        RETURN @COUNT;
    END;
GO
-- DROP FUNCTION FCTEACHER;

-- ��������� � �������:
SELECT PULPIT, DBO.FCTEACHER(PULPIT) [���������� ��������������] FROM PULPIT;

SELECT DBO.FCTEACHER(NULL) [����� ��������������];