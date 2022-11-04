/*����������� SELECT-������, � ��-����� �������� � ������� PROGRESS ��� �������� 
� ���������� ������� IDSTUDENT 
�������������� ������ (������������� �� �������).*/

USE UNIVER;
DECLARE @SUBJECT NVARCHAR(10), @IDSTUDENT INT, @NOTE INT
DECLARE TASK6 CURSOR GLOBAL DYNAMIC FOR SELECT SUBJECT, IDSTUDENT, NOTE
FROM PROGRESS FOR UPDATE

OPEN TASK6
FETCH TASK6 INTO @SUBJECT, @IDSTUDENT, @NOTE
WHILE @@FETCH_STATUS = 0
BEGIN
PRINT @SUBJECT + ' ' +CAST(@IDSTUDENT AS NVARCHAR(10)) + ' ' + CAST(@NOTE AS NVARCHAR(20)) -- �������������� ����� ������
IF @IDSTUDENT = 1021 UPDATE PROGRESS SET NOTE = NOTE - 1 WHERE CURRENT OF TASK6
FETCH TASK6 INTO @SUBJECT, @IDSTUDENT, @NOTE
END
CLOSE TASK6
DEALLOCATE TASK6

SELECT SUBJECT[�������], IDSTUDENT[ID ��������], NOTE[������] FROM PROGRESS
GO

UPDATE PROGRESS SET NOTE = 9 WHERE IDSTUDENT = 1021