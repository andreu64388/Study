/*1. ����������� ��������� ������� � ������ COUNT_STUDENTS, ������� ��������� ���������� ���-������ �� ���������
�, ��� �������� �������� ���������� ���� VARCHAR(20) � ������ @faculty. ������������ ���������� ���������� ������ 
FACULTY, GROUPS, STU-DENT. ���������� ������ �������.
������ ��������� � ����� ������� � ������� ��������� ALTER � ���, ����� ������� ��������� ������ �������� @prof
���� VARCHAR(20), ������������ ������������� ���������. ��� ���������� ���������� �������� �� ������-��� NULL.
���������� ������ ������� � ������� SE-LECT-��������.
*/
USE UNIVER;
CREATE FUNCTION COUNT_STUDENTS (@FACULTY NVARCHAR(20)) RETURNS INT AS
BEGIN
DECLARE @COUNT INT=0;
SET @COUNT=(SELECT COUNT(STUDENT.IDSTUDENT)
FROM FACULTY
INNER JOIN GROUPS ON GROUPS.FACULTY = FACULTY.FACULTY
INNER JOIN STUDENT ON STUDENT.IDGROUP = GROUPS.IDGROUP
WHERE FACULTY.FACULTY = @FACULTY)
RETURN @COUNT;
END;
GO
--DROP FUNCTION COUNT_STUDENTS;

DECLARE @TEMP_1 INT = DBO.COUNT_STUDENTS('����');
PRINT '���������� ��������� �� ���������� ' +CAST(@TEMP_1 AS NVARCHAR(20))+ ' �������.';

SELECT FACULTY '���������',
DBO.COUNT_STUDENTS(FACULTY) '���-�� ���������'
FROM FACULTY
GO

-- ������ ��������� � ����� ������� � ������� ��������� ALTER � ���, ����� ������� ��������� ������ �������� @PROF:
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

DECLARE @TEMP_1 INT = DBO.COUNT_STUDENTS('����', '1-40 01 02');
PRINT '���������� ���������: ' + CONVERT(VARCHAR, @TEMP_1);

SELECT FACULTY.FACULTY '���������',
GROUPS.PROFESSION '�������������',
DBO.COUNT_STUDENTS(FACULTY.FACULTY, GROUPS.PROFESSION) '���-�� ���������'
FROM FACULTY
INNER JOIN GROUPS ON GROUPS.FACULTY = FACULTY.FACULTY
GROUP BY FACULTY.FACULTY, GROUPS.PROFESSION
GO