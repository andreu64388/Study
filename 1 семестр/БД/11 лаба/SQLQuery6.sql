/*6. ����������� ��� �������� A � B �� ������� ���� ������ X_UNIVER. ((��������� ������))
�������� A ������������ ����� ����� ���������� � ������� ��������������� REPEATABLE READ. 
�������� B � ����� ���������� � ������� ��������������� READ COMMITED. 
�������� A ������ ���������������, ��� ������� REAPETABLE READ �� ��������� �����������������
������ � ���������������� ������, �� ��� ���� �������� ��������� ������. 
*/
USE UNIVER;
GO
-- A ---
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ
BEGIN TRANSACTION
SELECT COUNT(*) FROM SUBJECT WHERE SUBJECT = 'TEST';
-------------------------- T1 ------------------
-------------------------- T2 -----------------
SELECT COUNT(*) FROM SUBJECT WHERE SUBJECT = 'TEST';
COMMIT TRAN;
rollback



