/*7. ����������� ��� �������� A � B �� ������� ���� ������ X_UNIVER. 
�������� A ������������ ����� ����� ���������� � ������� ��������������� SERIALIZABLE. 
�������� B � ����� ���������� � ������� ��������������� READ COMMITED.
�������� A ������ ��������������� ���������� ����������, ����������������� � ����������������
������. (�������� ��������������� ������)
*/
USE UNIVER;
GO
-- A ---
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE
BEGIN TRANSACTION
SELECT * FROM SUBJECT;
-------------------------- T1 -----------------
-------------------------- T2 ------------------
SELECT * FROM SUBJECT;
COMMIT TRAN;

rollback

rollback
