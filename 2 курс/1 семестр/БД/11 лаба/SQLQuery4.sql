	/*4. ����������� ��� �������� A � B �� ������� ���� ������ X_UNIVER. 
�������� A ������������ ����� ����� ���������� � ������� ��������������� READ UNCOMMITED, 
�������� B � ����� ���������� � ������� ��������������� READ COMMITED (�� ���������). 
�������� A ������ ���������������, ��� ������� READ UNCOMMITED ��������� ����������������,
���������������(���������������� ������)� ��������� ������. 
*/

USE UNIVER;
GO
-----A------

SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED
SELECT @@SPID
BEGIN TRANSACTION
------------------ T1 ------------------
SELECT * FROM SUBJECT WHERE SUBJECT = 'TEST';
ROLLBACK TRAN;

--COMMIT TRAN;
-------t2---------

