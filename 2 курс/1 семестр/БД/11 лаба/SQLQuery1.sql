/* 1. ����������� ��������, ��-������������� ������ � ��-���� ������� ����������.
���������������� ������, ����������� ������, � ������� ��������� ������� �, � ������� �������� 
��� ������ �������.
*/
USE UNIVER
GO
SET NOCOUNT ON
	IF EXISTS (SELECT * FROM  SYS.OBJECTS        -- ������� X ����?
	            WHERE OBJECT_ID= OBJECT_ID(N'DBO.M') )	            
	DROP TABLE M;    
	
	DECLARE @C INT, @FLAG CHAR = 'C';           -- COMMIT ��� ROLLBACK?
	SET IMPLICIT_TRANSACTIONS  ON   -- �����. ����� ������� ����������
	CREATE TABLE M(K INT );                         -- ������ ���������� 
		INSERT M VALUES (1),(2),(3);
		SET @C = (SELECT COUNT(*) FROM M);
		PRINT '���������� ����� � ������� M: ' + CAST( @C AS VARCHAR(2));
		IF @FLAG = 'C'  COMMIT;                   -- ���������� ����������: �������� 
	          ELSE   ROLLBACK;                                 -- ���������� ����������: �����  
      SET IMPLICIT_TRANSACTIONS  OFF   -- ������. ����� ������� ����������
	
	IF  EXISTS (SELECT * FROM  SYS.OBJECTS       -- ������� X ����?
	            WHERE OBJECT_ID= OBJECT_ID(N'DBO.M') )
	PRINT '������� M ����';  
      ELSE PRINT '������� M ���'

-------------------------------------------------------------
--------------------------BANK-------------------------------
-------------------------------------------------------------
DROP TABLE TEST_X;
USE BANK;
DECLARE @LENGHT INT, @FLAG_MY CHAR = 'R'
SET IMPLICIT_TRANSACTIONS ON;-- �����. ����� ������� ����������
CREATE TABLE TEST_X (VAL INT);-- ������ ����������
INSERT INTO TEST_X VALUES (1), (2), (3);
SET @LENGHT = (SELECT COUNT(*) FROM TEST_X);
PRINT '���-�� ����� � ������� TEST: ' + CONVERT(VARCHAR, @LENGHT);
IF @FLAG_MY = 'R'
COMMIT;
ELSE
ROLLBACK;-- ���������� ����������: �����
SET IMPLICIT_TRANSACTIONS OFF;-- ������. ����� ������� ����������
