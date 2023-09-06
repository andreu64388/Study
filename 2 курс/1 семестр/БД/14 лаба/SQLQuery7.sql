/*7. ����������� ��������, ��������������� �� ������� ���� ������ X_UNIVER �����-������:
AFTER-������� �������� ������ ����-������,
� ������ �������� ����������� �����-���, ���������������� �������.*/


--------------------------------------------
------------------UNIVER--------------------
--------------------------------------------
USE UNIVER

GO
	CREATE TRIGGER PTRAN
	ON PULPIT AFTER INSERT, DELETE, UPDATE
	AS DECLARE @C INT = (SELECT COUNT (*) FROM PULPIT);
	 IF (@C >20)
	 BEGIN
       RAISERROR('����� ���������� ������ �� ����� ���� >20', 10, 1);
	 ROLLBACK;
	 END;
	 RETURN;

INSERT INTO PULPIT(PULPIT) VALUES ('����');

