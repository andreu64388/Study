/*
3. ����������� � ������� ������������� � ������ ���������. ������������� ������ 
���� ��������� �� ������ ������� AUDITO-RIUM � ��������� �������: ��� (AUDITO-RIUM)
, ������������ ��������� (AUDITO-RIUM_NAME). 
������������� ������ ���������� ������ ���������� ��������� (� ������� AUDITO-RIUM_ 
TYPE ������, ������������ � �����-�� ��) � ��������� ���������� ��������� IN-SERT, UPDATE � DELETE.
*/
CREATE VIEW [Auditor] (AUDITORIUM_TYPE,AUDITORIUM)
as select AUDITORIUM.AUDITORIUM_TYPE as [������������ ���������],
AUDITORIUM.AUDITORIUM as [���]
FROM AUDITORIUM
WHERE AUDITORIUM.AUDITORIUM_TYPE LIKE '��%'

INSERT  [Auditor] VALUES ('��','��')
DELETE FROM Auditor where AUDITORIUM='��'
UPDATE Auditor SET  AUDITORIUM = 'TEST' 
WHERE AUDITORIUM = '��'

select * from Auditor

drop view Auditor
----------------------------------

USE BANK;
GO
CREATE VIEW [�����_t] (id,��������_�������,������) 
AS SELECT ����.id [���],
����.��������_������� [�������� �������],
����.������ [������]
FROM ����;
INSERT  [�����_t] 
VALUES (3,'�������',3000);

DELETE FROM [�����_t] 
WHERE id = 3;

SELECT * FROM [�����_t]
GO
DROP VIEW [�����_t]