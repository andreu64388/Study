/*
5. ����������� ��������� � ������ SUB-JECT_REPORT, ����������� � ����������� ��-������ ����� ����� �� ������� ��������� �� ���-������� �������. � ����� ������ ���� �������� ������� �������� (���� SUBJECT) �� ������� SUBJECT � ���� ������ ����� ������� (������������ ���������� ������� RTRIM). ��������� ����� ������� �������� � ������ @p ���� CHAR(10), ����-��� ������������ ��� �������� ���� �������.
� ��� ������, ���� �� ��������� �������� @p ��-�������� ���������� ��� �������, ��������� ������ ������������ ������ � ���������� ������ � ����-������. 
��������� SUBJECT_REPORT ������ ������-���� � ����� ������ ���������� ���������, ������-������ � ������. 
*/
------------------------------------------------
----------------------UNVER---------------------
------------------------------------------------
USE UNIVER;
GO
CREATE PROCEDURE SUBJECT_REPORT @P CHAR(10)
  AS DECLARE @RC INT = 0;
	BEGIN TRY
		IF NOT EXISTS (SELECT SUBJECT FROM SUBJECT WHERE PULPIT = @P)
			RAISERROR('������ � ����������', 11, 1);
		DECLARE @SUBS_LIST CHAR(300) = '', @SUB CHAR(10);
		DECLARE SUBJECTS_LAB12 CURSOR FOR
			SELECT SUBJECT FROM SUBJECT WHERE PULPIT = @P;
		OPEN SUBJECTS_LAB12;
			FETCH SUBJECTS_LAB12 INTO @SUB;
			WHILE (@@FETCH_STATUS = 0)
				BEGIN
					SET @SUBS_LIST = RTRIM(@SUB) + ', ' + @SUBS_LIST;
					SET @RC += 1;		
					FETCH SUBJECTS_LAB12 INTO @SUB;
				END;
			PRINT '���������� �� ������� ' + RTRIM(@P) + ':';
			PRINT RTRIM(@SUBS_LIST);
		CLOSE SUBJECTS_LAB12;
		DEALLOCATE SUBJECTS_LAB12;
		RETURN @RC;
	END TRY
	BEGIN CATCH
		PRINT '����� ������: ' + CONVERT(VARCHAR, ERROR_NUMBER());
		PRINT '���������: ' + ERROR_MESSAGE();
		PRINT '�������: ' + CONVERT(VARCHAR, ERROR_SEVERITY());
		PRINT '�����: ' + CONVERT(VARCHAR, ERROR_STATE());
		PRINT '����� ������: ' + CONVERT(VARCHAR, ERROR_LINE());
		IF ERROR_PROCEDURE() IS NOT NULL
			PRINT '��� ���������: ' + ERROR_PROCEDURE();
		RETURN @RC;
	END CATCH;
GO

DECLARE @TEMP_5 INT;
EXEC @TEMP_5 = SUBJECT_REPORT '����';
PRINT '���������� ���������: ' + CONVERT(VARCHAR, @TEMP_5);


--DROP PROCEDURE SUBJECT_REPORT
