/*3. ������� ��������� ��������� ������� � ������ #SUBJECT. ������������ � ��� �������� ������� ������ ��������������� �������� ��������������� ������ ���������
XPSUBJECT, ������������� � ����-��� 2. 
�������� ��������� PSUBJECT ����� �������, ����� ��� �� ��������� ��������� ���������.
�������� ����������� INSERT� EXECUTE � ��-�������������� ���������� PSUBJECT, �������� ������ � ������� #SUBJECT. 
*/
------------------------------------------------
----------------------UNVER---------------------
------------------------------------------------
USE UNIVER;
GO
ALTER PROCEDURE PSUBJECT @P VARCHAR(20)
AS BEGIN
	SELECT * FROM SUBJECT WHERE SUBJECT = @P;
END;
GO
CREATE TABLE #SUBJECTS
(
	[SUBJECT] VARCHAR(20),
	[SUBJECT_NAME] VARCHAR(100),
	[PULPIT] VARCHAR(20)
);
GO
INSERT #SUBJECTS EXEC PSUBJECT @P = '���';
INSERT #SUBJECTS EXEC PSUBJECT @P = '����';

SELECT * FROM #SUBJECTS;
SELECT * FROM SUBJECT

------------------------------------------------
----------------------BANK----------------------
------------------------------------------------
USE BANK;
GO
ALTER PROCEDURE PBANK @ID INT
AS BEGIN
	SELECT * FROM ������ WHERE ID_CLIENT = @ID;
END;
GO
CREATE TABLE #BANK_
(
  NOMER_CR INT,
  ID_CL INT
);
GO
INSERT #BANK_ EXEC PBANK @ID = 10;
INSERT #BANK_ EXEC PBANK @ID=11;

SELECT * FROM #BANK_;
