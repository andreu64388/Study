/*8.  ��� ������� FACULTY ������� IN-STEAD OF-�������, ����������� �������� ����� � �������. 
����������� ��������, ������� ���������-���� �� ������� ���� ������ X_UNIVER, ��� �������� ����������� ����������� ���������, ���� ���� INSTEAD OF-�������.
� ������� ��������� DROP ������� ��� DML-��������, ��������� � ���� ������������ ������.
*/
USE UNIVER
GO

--DROP TRIGGER F_INSTEAD_OF
	CREATE TRIGGER F_INSTEAD_OF
	ON FACULTY INSTEAD OF DELETE
	AS
	    BEGIN
RAISERROR(N'�������� ���������', 10, 1);
RETURN;	
END;
	

 DELETE FACULTY WHERE FACULTY = 'NEW';

DROP TRIGGER F_INSTEAD_OF,PTRAN,TEACH_AFTER_DEL1,TEACH_AFTER_DEL2,TEACH_AFTER_DEL3,TR_TEACHER 