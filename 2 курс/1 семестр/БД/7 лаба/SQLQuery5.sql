/*
5 ����������. ������������� ������ ���� ��-������� �� ������ SELECT-������� � ������� SUBJECT
, ���������� ��� ���������� � ��-�������� ������� � ��������� ��������� �������: ��� (SUBJECT)
, ������������ ���-������� (SUBJECT_NAME) � ��� ������� (PULPIT). ������������ TOP � ORDER BY.*/
USE UNIVER
GO
CREATE VIEW [����������] 
AS  SELECT  TOP(100) 
SUBJECT,
SUBJECT_NAME,  
PULPIT
FROM SUBJECT
ORDER BY SUBJECT_NAME
GO
SELECT * FROM [����������];

DROP VIEW [����������]
-----------------------------------
USE BANK;
GO
CREATE VIEW [Test_bank] 
AS SELECT 
TOP(100)
����.��������_������� 
FROM ����

SELECT * FROM [Test_bank]

DROP VIEW [Test_bank]

