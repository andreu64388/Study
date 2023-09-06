/*1. ����������� ��������� ������� � ������ COUNT_STUDENTS, ������� ��������� ���������� ���-������ �� ���������
�, ��� �������� �������� ���������� ���� VARCHAR(20) � ������ @faculty. ������������ ���������� ���������� ������ 
FACULTY, GROUPS, STU-DENT. ���������� ������ �������.
*/
-------------------------------------------------
---------------------UNIVER----------------------
-------------------------------------------------
USE UNIVER;
GO
CREATE FUNCTION COUNT_STUDENTS (@FACULTY NVARCHAR(20)) RETURNS INT AS
BEGIN
    DECLARE @COUNT INT=0;
    SET @COUNT=(SELECT COUNT(STUDENT.IDSTUDENT)
    FROM FACULTY
	JOIN GROUPS ON GROUPS.FACULTY = FACULTY.FACULTY
	JOIN STUDENT ON STUDENT.IDGROUP = GROUPS.IDGROUP
	WHERE FACULTY.FACULTY = @FACULTY)
    RETURN @COUNT;
END;
GO


--DROP FUNCTION COUNT_STUDENTS;

DECLARE @TEMP_1 INT = DBO.COUNT_STUDENTS('����');
PRINT '���������� ��������� �� ���������� ' +CAST(@TEMP_1 AS NVARCHAR(20))+ ' �������.';

GO
SELECT FACULTY '���������',
DBO.COUNT_STUDENTS(FACULTY) '���-�� ���������'
FROM FACULTY
GO

/*������ ��������� � ����� ������� � ������� ��������� ALTER � ���, ����� ������� ��������� 
������ �������� @PROF ���� VARCHAR(20), ������������ ������������� ���������. ��� ���������� ����������
�������� �� ������-��� NULL. ���������� ������ ������� � ������� SE-LECT-��������.*/

ALTER FUNCTION COUNT_STUDENTS (@FACULTY NVARCHAR(20), @PROF NVARCHAR(20)) RETURNS INT AS
BEGIN
    DECLARE @COUNT INT=0;
    SET @COUNT=(SELECT COUNT(STUDENT.IDSTUDENT)
    FROM FACULTY
    INNER JOIN GROUPS ON GROUPS.FACULTY = FACULTY.FACULTY
    INNER JOIN STUDENT ON STUDENT.IDGROUP = GROUPS.IDGROUP
    WHERE FACULTY.FACULTY = @FACULTY AND GROUPS.PROFESSION = @PROF)
    RETURN @COUNT;
END;
GO

DECLARE @RESULT INT = DBO.COUNT_STUDENTS('���', '1-25 01 07');
PRINT '���������� ���������: ' + CONVERT(VARCHAR, @RESULT);

SELECT FACULTY.FACULTY '���������',
	GROUPS.PROFESSION '�������������',
	DBO.COUNT_STUDENTS(FACULTY.FACULTY, GROUPS.PROFESSION) '���-�� ���������'
FROM FACULTY
	INNER JOIN GROUPS ON GROUPS.FACULTY = FACULTY.FACULTY
GROUP BY FACULTY.FACULTY, GROUPS.PROFESSION
GO

-------------------------------------------------
-----------------------BANK----------------------
-------------------------------------------------


CREATE FUNCTION COUNT_CREDITS (@ID_USER INT) RETURNS INT AS 
BEGIN
DECLARE @COUNTS INT = 0;
SET @COUNTS = (SELECT COUNT(����������.id) AS �������� FROM ����������
WHERE ����������.id = @ID_USER)   
RETURN @COUNTS
END

DECLARE @RESULT INT = DBO.COUNT_CREDITS(2);
PRINT '��-�� �������� �� ����� �������� = ' + CAST(@RESULT AS NVARCHAR)


SELECT ����������.�����_������� [����� �������],
 DBO.COUNT_CREDITS(����������.ID) [���-��],
 ����������.����� [�����]
FROM ����������

------------------------------------------------
