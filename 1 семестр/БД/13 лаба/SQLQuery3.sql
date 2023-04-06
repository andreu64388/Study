/*3. ����������� ��������� ������� FFACPUL, ��������-�� ������ ������� ������������������ �� ������� ����. 
������� ��������� ��� ���������, �������� ��� ��-�������� (������� FACULTY.FACULTY) � ��� ������� (������� PULPIT.PULPIT). ���������� SELECT-������ C ����� ������� ����������� ����� ��������� FACULTY � PULPIT. 
���� ��� ��������� ������� ����� NULL, �� ��� ���-������� ������ ���� ������ �� ���� �����������. 
���� ����� ������ �������� (������ ����� NULL), ����-��� ���������� ������ ���� ������ ��������� ����������. 
���� ����� ������ �������� (������ ����� NULL), ����-��� ���������� �������������� �����, ���������� ����-��, ��������������� �������� �������.
*/
 ---------------------------------------
 ---------------UNIVER------------------
 ---------------------------------------
USE UNIVER
GO
CREATE FUNCTION FFACPUL(@FAC VARCHAR(10), @PUL VARCHAR(10)) RETURNS TABLE
    AS RETURN

    SELECT FACULTY.FACULTY, PULPIT.PULPIT
    FROM FACULTY LEFT OUTER JOIN PULPIT
    ON FACULTY.FACULTY = PULPIT.FACULTY
WHERE FACULTY.FACULTY=ISNULL(@FAC, FACULTY.FACULTY) AND PULPIT.PULPIT=ISNULL(@PUL, PULPIT.PULPIT);

GO
--DROP FUNCTION DBO.FFACPUL;
SELECT * FROM DBO.FFACPUL(NULL,NULL);
SELECT * FROM DBO.FFACPUL('���',NULL);
SELECT * FROM DBO.FFACPUL(NULL,'����');
SELECT * FROM DBO.FFACPUL('����','�����');
SELECT * FROM DBO.FFACPUL('NO','NO');
GO

 ---------------------------------------
 ---------------BANK--------------------
 ---------------------------------------

 USE BANK
GO
CREATE FUNCTION FBANK_3 (@FAC INT, @PUL INT) RETURNS TABLE
    AS RETURN
    SELECT ����.������, ����������.�����
    FROM ���� LEFT OUTER JOIN ����������
    ON ����.ID = ����������.ID
WHERE ����.ID =ISNULL(@FAC, ����������.�����) AND  ����������.ID=ISNULL(@PUL,����������.ID);

GO
SELECT * FROM DBO.FBANK_3(1,1);