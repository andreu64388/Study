/*5. ����������� ��������, ������� �����-�������� �� ������� ���� ������ X_UNIVER, 
��� �������� ����������� ����������� �����-������ �� ������������ 
AFTER-��������.*/

--------------------------------------------
------------------UNIVER--------------------
--------------------------------------------
USE UNIVER
GO
INSERT INTO TEACHER(TEACHER,TEACHER_NAME,GENDER,PULPIT)
VALUES(1,2,4,4)
UPDATE TEACHER SET GENDER = '�54' WHERE TEACHER='����'

 SELECT * FROM TR_AUDIT
 SELECT *FROM TEACHER


update TEACHER set PULPIT = '����' where TEACHER = '���'