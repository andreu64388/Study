/*2. ����������� ��������� ������� � ������ FSUB-JECTS, ����������� �������� @p ���� VARCHAR(20), �������� �������� ������ ��� ������� (������� SUB-JECT.PULPIT). 
������� ������ ���������� ������ ���� VARCHAR(300) � �������� ��������� � ������. 
������� � ��������� ��������, ������� ������� �����, ����������� ��������������� ����. 
����������: ������������ ��������� ����������� ������ �� ������ SELECT-������� � ������� SUBJECT.
*/


 ---------------------------------------
 ---------------UNIVER------------------
 ---------------------------------------
USE UNIVER;
GO
CREATE FUNCTION FSUBJECTS (@P NVARCHAR(20)) RETURNS NVARCHAR(300) AS
BEGIN
    DECLARE @LIST VARCHAR(300) = '����������: ', @SUB VARCHAR(20);
    DECLARE SUBJECT_CURSOR CURSOR LOCAL FOR
    SELECT SUBJECT.SUBJECT '����������'
    FROM SUBJECT
    WHERE SUBJECT.PULPIT = @P
    OPEN SUBJECT_CURSOR
    FETCH NEXT FROM SUBJECT_CURSOR INTO @SUB
    WHILE @@FETCH_STATUS = 0
        BEGIN
            SET @LIST=@LIST+RTRIM(@SUB)+', ';
            FETCH SUBJECT_CURSOR INTO @SUB
        END;
    RETURN @LIST;
END;
-- DROP FUNCTION FBANK;

PRINT DBO.FSUBJECTS('����');
SELECT PULPIT '�������', DBO.FSUBJECTS(PULPIT) '����������' FROM PULPIT;
GO

-------------------------------------------------
-----------------------BANK----------------------
-------------------------------------------------

USE BANK;
GO

SELECT  * FROM ����

CREATE FUNCTION FBANK (@P INT) RETURNS NVARCHAR(300) AS
BEGIN
    DECLARE @LIST VARCHAR(300) = '', @NAME VARCHAR(20);
    DECLARE NAME_CURSOR CURSOR LOCAL FOR
	SELECT  ����.��������_������� FROM ����
	WHERE ����.ID = @P
    OPEN NAME_CURSOR
    FETCH NEXT FROM NAME_CURSOR INTO @NAME
    WHILE @@FETCH_STATUS = 0
        BEGIN
            SET @LIST=@LIST+RTRIM(@NAME)+', ';
            FETCH NAME_CURSOR INTO @NAME
        END;
    RETURN @LIST;
END;
-- DROP FUNCTION FBANK;

PRINT DBO.FBANK(1);
SELECT ����.��������_�������,����.������, DBO.FBANK(����.ID) FROM ����
