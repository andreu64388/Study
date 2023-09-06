/*4. ����������� ��������� � ������ PAUDITORI-UM_INSERT. ��������� ��������� ������ ������� ���������: @a, @n, @c � @t. �������� @a ����� ��� CHAR(20), �������� @n ����� ��� VARCHAR(50), �������� @c ����� ��� INT � �������� �� ��������� 0, �������� @t ����� ��� CHAR(10).
��������� ��������� ������ � ������� AUDITO-RIUM. �������� �������� AUDITORIUM, AUDI-TORIUM_NAME, AUDITORIUM_CAPACITY � AUDITORIUM_TYPE ����������� ������ �������� �������������� ����������� @a, @n, @c � @t.
��������� PAUDITORIUM_INSERT ������ ���-������ �������� TRY/CATCH ��� ��������� ������. � ������ ������������� ������, ��������� ������ ����������� ���������, ���������� ��� ������, ������� ����������� � ����� ��������� � ����������� �������� �����. 
��������� ������ ���������� � ����� ������ ���-����� -1 � ��� ������, ���� ��������� ������ � 1, ��-�� ���������� �������. 
���������� ������ ��������� � ���������� �����-����� �������� ������, ������� ����������� � ���-����.
*/
------------------------------------------------
----------------------UNVER---------------------
------------------------------------------------
USE UNIVER;
GO

CREATE PROCEDURE PAUDITORIUM_INSERT @A CHAR(20), @N VARCHAR(50), @C INT = 0, @T CHAR(10)
AS 
 BEGIN 
   BEGIN TRY
	INSERT INTO AUDITORIUM(AUDITORIUM, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY, AUDITORIUM_NAME)
		VALUES(@A, @N, @C, @T);
	RETURN 1;
  END TRY
  BEGIN CATCH
	PRINT 'NUM: ' + CAST(ERROR_NUMBER() AS VARCHAR(6));
	PRINT 'MESSAGE: ' + ERROR_MESSAGE();
	PRINT 'SEVERITY: ' + CAST(ERROR_SEVERITY() AS VARCHAR(6));
	PRINT 'STATE: ' + CAST(ERROR_STATE() AS VARCHAR(8));
	PRINT 'ERROR LINE: ' + CAST(ERROR_LINE() AS VARCHAR(8));
	IF ERROR_PROCEDURE() IS NOT NULL   
	PRINT 'IN WHAT PROC: ' + ERROR_PROCEDURE();
	RETURN -1;
  END CATCH;
END;


DECLARE @RC INT;  
EXEC @RC = PAUDITORIUM_INSERT @A = '100', @N = '��', @C = 30, @T = '100'; 
PRINT 'STATUS: ' + CAST(@RC AS VARCHAR(3));

SELECT * FROM AUDITORIUM WHERE AUDITORIUM.AUDITORIUM = '100'

DELETE AUDITORIUM WHERE AUDITORIUM='100';



------------------------------------------------
----------------------BANK----------------------
------------------------------------------------
USE BANK;
GO

CREATE PROCEDURE PBANK_INSERT @ID_CL INT,@MOBILE INT,@FACE NVARCHAR(20),@ADDRES NVARCHAR(20)
AS 
 BEGIN 
   BEGIN TRY
	INSERT INTO ������(ID_CLIENT,�������,�����,���������_����)
		VALUES(@ID_CL, @MOBILE, @ADDRES, @FACE);
	RETURN 1;
  END TRY
  BEGIN CATCH
	PRINT 'NUM: ' + CAST(ERROR_NUMBER() AS VARCHAR(6));
	PRINT 'MESSAGE: ' + ERROR_MESSAGE();
	PRINT 'SEVERITY: ' + CAST(ERROR_SEVERITY() AS VARCHAR(6));
	PRINT 'STATE: ' + CAST(ERROR_STATE() AS VARCHAR(8));
	PRINT 'ERROR LINE: ' + CAST(ERROR_LINE() AS VARCHAR(8));
	IF ERROR_PROCEDURE() IS NOT NULL   
	PRINT 'IN WHAT PROC: ' + ERROR_PROCEDURE();
	RETURN -1;
  END CATCH;
END;


DECLARE @RC INT;  
EXEC @RC = PBANK_INSERT @ID_CL = 12, @MOBILE = 31, @FACE = 'NO', @ADDRES = 'FLAT'; 
PRINT 'STATUS: ' + CAST(@RC AS VARCHAR(3));

SELECT * FROM ������

DELETE  ������ WHERE ID_CLIENT =12;

