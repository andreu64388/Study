/*3. ����������� ��������, ���������-������ ������� ����������� �������� �� ������������
�� ������� ���� ���-��� X_UNIVER.*/


-------------------------------------------------------
------------------------STATIC-------------------------
-------------------------------------------------------

USE UNIVER
DECLARE @PUL CHAR(10), @GEN CHAR(2), @NAME CHAR(30);
DECLARE TEACHERS CURSOR LOCAL STATIC FOR SELECT PULPIT,
GENDER, TEACHER_NAME FROM TEACHER WHERE PULPIT='����';

OPEN TEACHERS;
PRINT '���������� �����: '+CAST(@@CURSOR_ROWS AS VARCHAR(5));
INSERT INTO TEACHER  (TEACHER,   TEACHER_NAME, GENDER, PULPIT )
VALUES ('���','�������� �������� �������������', '�', '����');
UPDATE TEACHER SET TEACHER_NAME = '�������� ������ ����������' WHERE TEACHER = '���';
FETCH TEACHERS INTO @PUL, @GEN, @NAME;
WHILE @@FETCH_STATUS=0
BEGIN
FETCH TEACHERS INTO @PUL, @GEN, @NAME;
PRINT '�������������: '+RTRIM(@PUL)+' '+RTRIM(@GEN)+' '+RTRIM(@NAME);
END;
CLOSE TEACHERS;
DELETE TEACHER WHERE TEACHER = '���';

-------------------------------------------------------
-----------------------DYNAMIC-------------------------
-------------------------------------------------------

DECLARE @PUL_ CHAR(10), @GEN_ CHAR(2), @NAME_ CHAR(30);
DECLARE TEACHERS CURSOR LOCAL DYNAMIC FOR SELECT PULPIT,
GENDER, TEACHER_NAME FROM TEACHER WHERE PULPIT='����';

OPEN TEACHERS;
PRINT '���������� �����: '+CAST(@@CURSOR_ROWS AS VARCHAR(5));
INSERT INTO TEACHER  (TEACHER,   TEACHER_NAME, GENDER, PULPIT )
VALUES ('���','�������� �������� �������������', '�', '����');
UPDATE TEACHER SET TEACHER_NAME = '�������� ������ ����������' WHERE TEACHER = '���';
FETCH TEACHERS INTO @PUL_, @GEN_, @NAME_;
WHILE @@FETCH_STATUS=0
BEGIN
FETCH TEACHERS INTO @PUL_, @GEN_, @NAME_;
PRINT '�������������: '+RTRIM(@PUL_)+' '+RTRIM(@GEN_)+' '+RTRIM(@NAME_);
END;
CLOSE TEACHERS;
DELETE TEACHER WHERE TEACHER = '���';



---------------------------------------
---------------BANK--------------------
---------------------------------------

USE BANK;
GO 
DECLARE @id int, @��������_������� NVARCHAR(20), @������ INT;
DECLARE BANK_ CURSOR LOCAL STATIC FOR SELECT id,��������_�������,������ FROM ����

OPEN BANK_;
PRINT '���������� �����: '+CAST(@@CURSOR_ROWS AS VARCHAR(5));
INSERT INTO ����(id,��������_�������,������)
VALUES (4,'NOT',32)
UPDATE ���� SET ������ = 3 WHERE id = 4;
FETCH BANK_ INTO @id, @��������_�������, @������;
WHILE @@FETCH_STATUS=0
BEGIN
FETCH BANK_ INTO @id, @��������_�������, @������;
PRINT '������: '+RTRIM(@id)+' '+RTRIM(@��������_�������)+' '+RTRIM(@������);
END;
CLOSE BANK_;

DEALLOCATE BANK_
DELETE ���� WHERE id = 4