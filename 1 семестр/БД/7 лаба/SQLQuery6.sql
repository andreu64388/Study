/*
6. �������� ������������� ������-����_������, ��������� � ������� 2 ���, ����� ��� 
���� ��������� � ������� ��������. ���-��������������� �������� ������������� ������������� � �������
��������. �������-���: ������������ ����� SCHEMABINDING. 

*/
USE UNIVER;
GO
ALTER VIEW [���������� ������] with schemabinding
AS SELECT FACULTY.FACULTY_NAME [���������],
COUNT(PULPIT.FACULTY) [����������]
FROM dbo.FACULTY join dbo.PULPIT
ON FACULTY.FACULTY = PULPIT.FACULTY
GROUP BY FACULTY.FACULTY_NAME

SELECT * FROM [���������� ������]

-------------------------------------------

USE BANK;
GO
ALTER VIEW [���������� ��������] with schemabinding
AS SELECT 
����.��������_������� [�������� �������],
COUNT(����.������) [���-��]
FROM dbo.����
GROUP BY ��������_�������

SELECT * FROM [���������� ��������]
