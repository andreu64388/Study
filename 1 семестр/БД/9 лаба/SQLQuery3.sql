/*3. ������� ��������� ��������� �������. ��������� �� ������� (�� ����� 10000 �����). 
����������� SELECT-������.
��-������ ���� ������� � ���������� ��� ���������. 
������� ������������������ ��-���� ��������, ����������� 
���-������ SELECT-�������. 
*/

-----------------------------------------------
--------------------UNIVER---------------------
-----------------------------------------------

USE UNIVER;
CREATE TABLE #TASK3
(
INFO NVARCHAR (20),
ITERATOR INT IDENTITY(1,1),
INDEX_ INT 
)

DECLARE @X INT =0;
WHILE @X <= 10000
BEGIN
INSERT INTO #TASK3(INFO,INDEX_)
VALUES ('������' + CAST(@X AS NVARCHAR),FLOOR(20000*RAND()))
SET @X +=1;
END

SELECT INFO FROM #TASK3 WHERE ITERATOR <= 10000 

CHECKPOINT;

DBCC DROPCLEANBUFFERS

CREATE INDEX #NONCLUSTPOK ON #TASK3 (ITERATOR) INCLUDE (INFO)

SELECT INFO FROM #TASK3 WHERE ITERATOR = 200

DROP INDEX #NONCLUSTPOK ON #TASK3

DROP TABLE #TASK3

-------------------------------------------------------
-------------------------BANK--------------------------
-------------------------------------------------------

USE BANK;

SELECT * FROM ������
WHERE ID_CLIENT = 10 AND ���������_���� = '���'

CREATE INDEX MY_BANK_2 ON ������(ID_CLIENT) INCLUDE(���������_����)

SELECT * FROM ������
WHERE ID_CLIENT = 10 AND ���������_���� = '���'

DROP INDEX MY_BANK_2 ON ����;

------------------------------------------------------
