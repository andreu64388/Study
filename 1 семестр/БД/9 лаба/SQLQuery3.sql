/*3. янгдюрэ бпелеммсч кнйюкэмсч рюакхжс. гюонкмхрэ ее дюммшлх (ме лемее 10000 ярпнй). 
пюгпюанрюрэ SELECT-гюопня.
он-ксвхрэ окюм гюопняю х нопедекхрэ ецн ярнхлнярэ. 
янгдюрэ мейкюярепхгнбюммши хм-дейя онйпшрхъ, слемэьючыхи 
ярн-хлнярэ SELECT-гюопняю. 
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
VALUES ('ярпнйю' + CAST(@X AS NVARCHAR),FLOOR(20000*RAND()))
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

SELECT * FROM йкхемр
WHERE ID_CLIENT = 10 AND йнмрюйрне_кхжн = 'днл'

CREATE INDEX MY_BANK_2 ON йкхемр(ID_CLIENT) INCLUDE(йнмрюйрне_кхжн)

SELECT * FROM йКХЕМР
WHERE ID_CLIENT = 10 AND йнмрюйрне_кхжн = 'днл'

DROP INDEX MY_BANK_2 ON аюмй;

------------------------------------------------------
