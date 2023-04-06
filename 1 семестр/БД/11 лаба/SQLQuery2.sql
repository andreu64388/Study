/*2. ����������� ��������, ��������������� �������� ����������� ����� ���������� �� ������� ���� ������ X_UNIVER. 
� ����� CATCH ������������� ������ ��������������� ��������� �� �������. 
���������� ������ �������� ��� ������������� ��������� ���������� ����������� ������.
*/
USE UNIVER;
GO
BEGIN TRY
	BEGIN TRAN                 -- ������  ����� ����������
		--INSERT FACULTY VALUES ('��', '��������� ������ ����');
	    INSERT FACULTY VALUES ('���', '��������� PRINT-����������');
	COMMIT TRAN;               -- �������� ����������
END TRY

BEGIN CATCH
	PRINT '������: '+ CASE
		WHEN ERROR_NUMBER() = 2627 AND PATINDEX('%FACULTY_PK%', ERROR_MESSAGE()) > 0 THEN '������������ '	
		ELSE '����������� ������: '+ CAST(ERROR_NUMBER() AS  VARCHAR(5))+ ERROR_MESSAGE()
	END;
	IF @@TRANCOUNT > 0 ROLLBACK TRAN; -- ��.����������� ��.>0,  ����� �� ���������
END CATCH;

DELETE FACULTY WHERE FACULTY = '��';
DELETE FACULTY WHERE FACULTY = '���';

SELECT * FROM FACULTY;
-------------------------------------------------------------
--------------------------BANK-------------------------------
-------------------------------------------------------------
USE BANK;

BEGIN TRY        
	BEGIN TRAN                 
		INSERT INTO ���� (id,��������_�������,������) VALUES (4, '�������',1212);
	    INSERT INTO ���� (id,��������_�������,������) VALUES (5, '���������',12);
	COMMIT TRAN;               
END TRY

BEGIN CATCH
	PRINT 'ERROR: '+ CASE 
		WHEN ERROR_NUMBER() = 2627 AND PATINDEX('%����_PK%', ERROR_MESSAGE()) > 0
		THEN 'ERRORS'	
		ELSE 'OTHER ERROR: '+ CAST(ERROR_NUMBER() AS  VARCHAR(5))+ ERROR_MESSAGE()  
	END;
	IF @@TRANCOUNT > 0 ROLLBACK TRAN; 	  
END CATCH;

SELECT* FROM ����