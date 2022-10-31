/*4. ������� � ��������� ��������� ��������� �������. 
����������� SELECT-������, ��-������ ���� ������� � ���������� ��� ���������. 
������� ������������������ ����������� ������, ��������-��� ��������� SELECT-�������.
*/
USE UNIVER;

CREATE TABLE #TASK4
(
INFO NVARCHAR (20),
ITERATOR INT IDENTITY(1,1),
INDEX_ INT 
)

DECLARE @X INT =1;
WHILE @X <= 11000
BEGIN
INSERT INTO #TASK4(INFO,INDEX_)
VALUES ('������' + CAST(@X AS NVARCHAR),FLOOR(20000*RAND()))
SET @X +=1;
END

CREATE INDEX #INDEX ON #TASK4(ITERATOR)
WHERE (ITERATOR > 1500 AND ITERATOR < 2000)
CHECKPOINT;
DBCC DROPCLEANBUFFERS

SELECT ITERATOR FROM #TASK4 
WHERE ITERATOR > 1500 AND ITERATOR < 2000

DROP INDEX #INDEX ON #TASK4