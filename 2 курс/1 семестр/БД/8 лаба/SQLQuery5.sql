/*
5. ������������������ ����������� IF� ELSE �� ������� ������� ������ ������ ���� ������ �_UNIVER.*/


USE UNIVER;
DECLARE @MAX_CAPACITY INT =(SELECT MAX(AUDITORIUM_CAPACITY) FROM AUDITORIUM ); 
IF  @MAX_CAPACITY= 90 
BEGIN
PRINT '90 MAX SIZE'
END
ELSE PRINT '> THAN 90'