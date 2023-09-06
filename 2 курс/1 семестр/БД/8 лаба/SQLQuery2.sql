/*2. ����������� ������, � ������� ������������ ����� ����������� ����-�����. 
����� ����� ����������� ���-������ 200, �� ������� ���������� ���������, ������� ����������� ����-�����,
���������� ���������, ������-����� ������� ������ �������, � ���-���� ����� ���������. ����� ����� �����������
��������� ������ 200, �� ������� ��������� � ������� ����� �����������.*/
USE UNIVER;

DECLARE 
@CAPACITY INT = (SELECT SUM(AUDITORIUM_CAPACITY) FROM AUDITORIUM),
@TOTAL INT,
@AVGCAPACITY INT,
@TOTALLESS INT,
@PROCENT INT;


IF @CAPACITY > 200
BEGIN
SET @TOTAL = (SELECT COUNT(*) FROM AUDITORIUM);
SET @AVGCAPACITY = (SELECT AVG(AUDITORIUM_CAPACITY) FROM AUDITORIUM);
SET @TOTALLESS= (SELECT COUNT(*) FROM AUDITORIUM
WHERE AUDITORIUM_CAPACITY < @AVGCAPACITY);
SET @PROCENT = @TOTALLESS * 100 / @TOTAL;
SELECT @CAPACITY [�����������],
@TOTAL [����� ���������],
@AVGCAPACITY [������� �����������],
@TOTALLESS [��������� ���� ��������� ���-��],
@PROCENT [�������]
END

ELSE PRINT '����� ����������� < 200'

