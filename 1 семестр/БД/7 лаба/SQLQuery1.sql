
/*
1. ����������� ������������� � ������ ���-����������. ������������� ������ ���� ��-�������
�� ������ SELECT-������� � ������� TEACHER � ��������� ��������� �������:
��� (TEACHER), ��� ������������� (TEACHER_NAME),
��� (GENDER), ��� ������� (PULPIT). */
USE UNIVER;
GO
CREATE VIEW [�������������] 
AS SELECT 
TEACHER.TEACHER [���],
TEACHER.TEACHER_NAME [��� �������������],
TEACHER.GENDER [���],
TEACHER.PULPIT [��� �������]
FROM TEACHER;

SELECT * FROM [�������������]
GO
DROP VIEW [�������������]

-------------------------------------

USE BANK;
GO
CREATE VIEW [�����] 
AS SELECT ����.id [���],
����.��������_������� [�������� �������],
����.������ [������]
FROM ����;

SELECT * FROM [�����]

GO
DROP VIEW [�����]