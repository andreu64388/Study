/*3. ����������� ��������, ��������������� ���������� ��������� SAVE TRAN �� ������� ���� ������ X_UNIVER. 
� ����� CATCH ������������� ������ ��������������� ��������� �� �������. 
���������� ������ �������� ��� ������������� ��������� ����������� ����� � ��������� ���������� ����������� ������.
*/
USE UNIVER
GO
DECLARE @POINT VARCHAR(32);

BEGIN TRY
	BEGIN TRAN
		SET @POINT = 'P1';
		SAVE TRAN @POINT;  -- ����������� ����� P1
		INSERT STUDENT(IDGROUP, NAME, BDAY, INFO, FOTO) VALUES
		                      (20,'������', '1997-08-02', NULL, NULL),
							  (20,'����', '1997-08-06', NULL, NULL),
							  (20,'����', '1997-08-01', NULL, NULL),
							  (20,'����', '1997-08-03', NULL, NULL);
		SET @POINT = 'P2';
		SAVE TRAN @POINT; -- ����������� ����� P2
		INSERT STUDENT(IDGROUP, NAME, BDAY, INFO, FOTO) VALUES
							  (21, '��������� �������', '1997-08-02', NULL, NULL);
	COMMIT TRAN;
END TRY

BEGIN CATCH
	PRINT '������: '+ CASE
		WHEN ERROR_NUMBER() = 2627 AND PATINDEX('%STUDENT_PK%', ERROR_MESSAGE()) > 0 THEN '������������ ��������'
		ELSE '����������� ������: '+ CAST(ERROR_NUMBER() AS  VARCHAR(5)) + ERROR_MESSAGE()
	END;
    IF @@TRANCOUNT > 0 -- ���� ���������� �� ���������
	BEGIN
	   PRINT '����������� �����: '+ @POINT;
	   ROLLBACK TRAN @POINT; -- ����� � ��������� �����.�����
	   COMMIT TRAN; -- �������� ���������, ������ �� �����.�����
	END;
END CATCH;

SELECT * FROM STUDENT WHERE IDGROUP=20;
DELETE STUDENT WHERE IDGROUP=20 AND IDGROUP = 21
-------------------------------------------------------------
--------------------------BANK-------------------------------
-------------------------------------------------------------
USE BANK;
DECLARE @POINT_ VARCHAR(32);

BEGIN TRY
	BEGIN TRAN                           
		SET @POINT_ = 'P1'; 
		SAVE TRAN @POINT_; 
	    INSERT INTO ���� (id,��������_�������,������) VALUES (4, '�������',1212);
		SET @POINT_ = 'P2'; 
		SAVE TRAN @POINT_; 
	    INSERT INTO ���� (id,��������_�������,������) VALUES (3, '�������',1212);
	COMMIT TRAN;                                              
END TRY

BEGIN CATCH
	PRINT 'ERROR: '+ CASE 
		WHEN ERROR_NUMBER() = 2627 AND PATINDEX('%PK_����', ERROR_MESSAGE()) > 0 
		THEN 'ER' 
		ELSE 'OTHER ERROR:: '+ CAST(ERROR_NUMBER() AS  VARCHAR(5)) + ERROR_MESSAGE()  
	END; 


    IF @@TRANCOUNT > 0
	BEGIN
	   PRINT '����������� �����: '+ @POINT_;
	   ROLLBACK TRAN @POINT_; 
	   COMMIT TRAN; 
	END;     
END CATCH;

