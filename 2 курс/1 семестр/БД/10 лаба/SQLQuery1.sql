/*1. ����������� ��������, �������-���� ������ ��������� �� ������� ����.
� ����� ������ ���� �������� ������� �������� (���� SUBJECT) �� ������� SUBJECT 
� ���� ������ ����� �������. 
������������ ���������� ������� RTRIM.*/

 ---------------------------------------
 ---------------UNIVER------------------
 ---------------------------------------
USE UNIVER

DECLARE @ONE NVARCHAR(20), @ALL NVARCHAR(300) = '';
DECLARE LINES CURSOR FOR SELECT SUBJECT FROM SUBJECT

OPEN LINES
FETCH LINES INTO @ONE
PRINT '����� ����� ��������� � ������'
WHILE @@FETCH_STATUS = 0
BEGIN
SET @ALL = RTRIM(@ONE) + ', ' + @ALL 
FETCH LINES INTO @ONE
END
PRINT RTRIM(@ALL) + ' ����� ������������.'
CLOSE LINES
 


 ---------------------------------------
 ---------------BANK--------------------
 ---------------------------------------

USE BANK;
GO 
DECLARE @TWO NVARCHAR(20), @ALL_TWO NVARCHAR(300) = '';
DECLARE LINES_T CURSOR FOR SELECT ��������_������� FROM ����
OPEN LINES_T
FETCH LINES_T INTO @TWO
PRINT '����� �������� � ������'
WHILE @@FETCH_STATUS = 0
BEGIN
SET @ALL_TWO = RTRIM(@TWO) + ', ' + @ALL_TWO
FETCH LINES_T INTO @TWO
END
PRINT RTRIM(@ALL_TWO) + ' ����� ������������.'
CLOSE LINES_T
 


