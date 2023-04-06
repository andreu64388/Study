/*4. ������� � ��������� ��������� ��������� �������. 
����������� SELECT-������, ��-������ ���� ������� � ���������� ��� ���������. 
������� ������������������ ����������� ������, ��������-��� ��������� SELECT-�������.
*/


-----------------------------------------------
--------------------UNIVER---------------------
-----------------------------------------------

USE UNIVER;

CREATE TABLE #TASK4
(
INFO NVARCHAR (20),
ITERATOR INT IDENTITY(1,1),
INDEX_ INT 
)

DECLARE @X INT =0;
WHILE @X <= 10000
BEGIN
INSERT INTO #TASK4(INFO,INDEX_)
VALUES ('������' + CAST(@X AS NVARCHAR),FLOOR(20000*RAND()))
SET @X +=1;
END


SELECT ITERATOR FROM #TASK4 
WHERE ITERATOR > 1500 AND ITERATOR < 2000

CREATE INDEX #INDEX ON #TASK4(ITERATOR)
WHERE (ITERATOR > 1500 AND ITERATOR < 2000)

CHECKPOINT;
DBCC DROPCLEANBUFFERS

SELECT ITERATOR FROM #TASK4 
WHERE ITERATOR > 1500 AND ITERATOR < 2000

DROP INDEX #INDEX ON #TASK4

-----------------------------------------------
---------------------BANK----------------------
-----------------------------------------------

USE BANK;

SELECT * FROM ������
WHERE ID_CLIENT = 10 AND ���������_���� = '���'

CREATE INDEX MY_BANK_2 ON ������(ID_CLIENT) WHERE 

SELECT * FROM ������
WHERE ID_CLIENT = 10 AND ���������_���� = '���'

DROP INDEX MY_BANK_2 ON ����;