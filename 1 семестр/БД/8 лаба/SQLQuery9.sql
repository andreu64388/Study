/*
9. ����������� �������� � ��������, � ������� ������������ ��� ��������� ������ ����� TRY � CATCH. 
�����-���� ������� ERROR_NUMBER (��� ��������� ������), ERROR_ES-SAGE (��������� �� ������), ERROR_LINE 
(��� ��������� ������), ER-ROR_PROCEDURE (��� ��������� ��� NULL), ERROR_SEVERITY
(������� ����������� ������), ERROR_ STATE (����� ������). ���������������� ��-�������.*/
USE UNIVER;
BEGIN TRY
UPDATE PROGRESS SET NOTE = '������ ������ INT!' WHERE NOTE = 9
END TRY
BEGIN CATCH
PRINT ERROR_NUMBER() -- ��� ��������� ������
PRINT ERROR_MESSAGE() -- ��������� �� ������
PRINT ERROR_LINE() -- ��� ��������� ������
PRINT ERROR_PROCEDURE() -- ��� ��������� ��� NULL
PRINT ERROR_SEVERITY() -- ������� ����������� ������
PRINT ERROR_STATE() 
END CATCH