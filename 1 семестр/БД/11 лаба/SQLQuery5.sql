/*5. ����������� ��� �������� A � B �� ������� ���� ������ X_UNIVER. (��������������� ������)
�������� A � �  ����������-�� ����� ����� ���������� � ������� ��������������� READ COMMITED. 
�������� A ������ �����-����������, ��� ������� READ COMMITED �� ��������� ��-��������������� 
������, �� ��� ���� �������� ���������-������ � ��������� ������. 
*/

USE UNIVER;
GO
-- A ---
SET TRANSACTION ISOLATION LEVEL READ COMMITTED
BEGIN TRANSACTION
SELECT * FROM SUBJECT WHERE SUBJECT = '��';
-------------------------- T1 ------------------
-------------------------- T2 -----------------
SELECT * FROM SUBJECT WHERE SUBJECT = '��';
COMMIT TRAN;


rollback
