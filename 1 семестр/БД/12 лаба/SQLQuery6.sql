/*6. ����������� ��������� � ������ PAUDITORI-UM_INSERTX. ��������� ��������� ���� ������� ����������: @A, @N, @C, @T � @TN. 
��������� @A, @N, @C, @T ���������� �������-��� ��������� PAUDITORIUM_INSERT. �������-������� �������� @TN �������� �������, ����� ��� VARCHAR(50), ������������ ��� ����� �������� �
������� AUDITORIUM_TYPE.AUDITORIUM_TYPENAME.
��������� ��������� ��� ������. ������ ������ ����������� � ������� AUDITORIUM_TYPE. �����-��� �������� AUDITORIUM_TYPE � AUDITORI-UM_ TYPENAME ����������� ������ �������� ��-������������ ����������� @T � @TN. ������ ������
����������� ����� ������ ��������� PAUDITORI-UM_INSERT.
���������� ������ � ������� AUDITORI-UM_TYPE � ����� ��������� PAUDITORI-UM_INSERT ������ ����������� � ������ ����� ����� ���������� � ������� ��������������� SERI-ALIZABLE. 
� ��������� ������ ���� ������������� ��������� ������ � ������� ��������� TRY/CATCH. ��� ������ ������ ���� ���������� � ������� �������-��������� ��������� � ����������� �������� �����. 
��������� PAUDITORIUM_INSERTX ������ ���������� � ����� ������ �������� -1 � ��� ������, ���� ��������� ������ � 1, ���� ���������� �����-���� ����������� �������. 
*/

------------------------------------------------
----------------------UNVER---------------------
------------------------------------------------

USE UNIVER;
GO
CREATE PROCEDURE PAUDITORIUM_INSERTX
		@A CHAR(20),
		@N VARCHAR(50),
		@C INT = 0,
		@T CHAR(10),
		@TN VARCHAR(50)	--���., ��� ����� � AUD_TYPEAUD_TYPENAME
AS BEGIN
DECLARE @RC INT = 1;
BEGIN TRY
	SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
	BEGIN TRAN
	INSERT INTO AUDITORIUM_TYPE(AUDITORIUM_TYPE, AUDITORIUM_TYPENAME)
				VALUES(@N, @TN);
	EXEC @RC = PAUDITORIUM_INSERT @A, @N, @C, @T;
	COMMIT TRAN;
	RETURN @RC;
END TRY
BEGIN CATCH
	PRINT '����� ������: ' + CAST(ERROR_NUMBER() AS VARCHAR(6));
	PRINT '���������: ' + ERROR_MESSAGE();
	PRINT '�������: ' + CAST(ERROR_SEVERITY() AS VARCHAR(6));
	PRINT '�����: ' + CAST(ERROR_STATE() AS VARCHAR(8));
	PRINT '����� ������: ' + CAST(ERROR_LINE() AS VARCHAR(8));
	IF ERROR_PROCEDURE() IS NOT  NULL
	PRINT '��� ���������: ' + ERROR_PROCEDURE();
	IF @@TRANCOUNT > 0 ROLLBACK TRAN ;
	RETURN -1;
END CATCH;
END;


DECLARE @K3 INT;
EXEC @K3 = PAUDITORIUM_INSERTX '102-3', @N = '��', @C = 85, @T = '102-3', @TN = '���������';
PRINT '��� : ' + CAST(@K3 AS VARCHAR(3));
GO
SELECT * FROM AUDITORIUM;
SELECT * FROM AUDITORIUM_TYPE;

DELETE AUDITORIUM WHERE AUDITORIUM='102-3';
DELETE AUDITORIUM_TYPE WHERE AUDITORIUM_TYPE='��';
GO
DROP PROCEDURE PAUDITORIUM_INSERTX;


------------------------------------------------
----------------------BANK----------------------
------------------------------------------------

USE BANK;
GO
CREATE PROCEDURE PBANK_INSERTX @ID_CL INT,@MOBILE INT,@FACE NVARCHAR(20),@ADDRES NVARCHAR(20),@VALUES INT
AS BEGIN
DECLARE @RC INT = 1;
BEGIN TRY
	SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
	BEGIN TRAN
	INSERT INTO TEST_X(VAL)
				VALUES(@VALUES);
	EXEC @RC = PBANK_INSERT @ID_CL, @MOBILE, @FACE, @ADDRES
	COMMIT TRAN;
	RETURN @RC;
END TRY
BEGIN CATCH
	PRINT '����� ������: ' + CAST(ERROR_NUMBER() AS VARCHAR(6));
	PRINT '���������: ' + ERROR_MESSAGE();
	PRINT '�������: ' + CAST(ERROR_SEVERITY() AS VARCHAR(6));
	PRINT '�����: ' + CAST(ERROR_STATE() AS VARCHAR(8));
	PRINT '����� ������: ' + CAST(ERROR_LINE() AS VARCHAR(8));
	IF ERROR_PROCEDURE() IS NOT  NULL
	PRINT '��� ���������: ' + ERROR_PROCEDURE();
	IF @@TRANCOUNT > 0 ROLLBACK TRAN ;
	RETURN -1;
END CATCH;
END;


DECLARE @K3 INT;
EXEC @K3 = PBANK_INSERTX @ID_CL = 13, @MOBILE = 31, @FACE = 'NO', @ADDRES = 'FLAT' , @VALUES =6
PRINT '��� : ' + CAST(@K3 AS VARCHAR(3));
GO
SELECT * FROM ������
SELECT * FROM TEST_X



