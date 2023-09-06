/*2. ������� ��������� ��������� �������. ��������� �� ������� (10000 ����� ��� ������). 
����������� SELECT-������. ��-������ ���� ������� � ���������� ��� ���������. 
������� ������������������ ��-���������� ��������� ������. 
������� ��������� ������ ��-��������.
*/
-----------------------------------------------
--------------------UNIVER---------------------
-----------------------------------------------


USE UNIVER;
CREATE TABLE #TEST2
(
INFO NVARCHAR (20),
ITERATOR INT IDENTITY(1,1),
INDEX_ INT 
)

DECLARE @X INT =0;
WHILE @X <= 10000
BEGIN
INSERT INTO #TEST2(INFO,INDEX_)
VALUES ('������' + CAST(@X AS NVARCHAR),FLOOR(20000*RAND()))
SET @X +=1;
END

SELECT * FROM #TEST2 WHERE INFO = '������2' AND INDEX_ >= 1000 

CHECKPOINT;

DBCC DROPCLEANBUFFERS

CREATE INDEX #TEST2_NONCL ON #TEST2(INFO,INDEX_)

SELECT * FROM #TEST2 WHERE INFO = '������2' AND INDEX_ >= 1000

DROP INDEX #TEST2_NONCL ON #TEST2



-----------------------------------------------
--------------------BANK-----------------------
-----------------------------------------------
USE BANK;

------------------BEFORE----------------------

SELECT * FROM ������
WHERE �����_������� = 101 AND ID_CLIENT = 10

CREATE INDEX MY_NOMER ON ������(�����_�������,ID_CLIENT);

--------------------AFTER---------------------

SELECT * FROM ������
WHERE �����_������� = 101 AND ID_CLIENT = 10

DROP INDEX MY_NOMER ON ������;

----------------------------------------------
