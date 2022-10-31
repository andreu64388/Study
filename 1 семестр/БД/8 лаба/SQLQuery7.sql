/*7. Создать временную локальную таблицу из трех столбцов и 10 строк, заполнить ее и вывести содержимое. 
Использовать оператор WHILE.*/
CREATE TABLE #MYTABLE(
ЧИСЛА INT,
СЛОВА NVARCHAR(50),
[ЕЩЕ СЛОВА] NVARCHAR(50)
);

DECLARE @I INT = 1;
WHILE @I <11
BEGIN
INSERT INTO #MYTABLE VALUES
(CAST(@I AS INT), CAST(@I AS NVARCHAR(10)) + ' - ЛАБА ','БД ' + CAST(@I AS NVARCHAR(10)))
SET @I +=1;
END
SELECT * FROM #MYTABLE
ORDER BY ЧИСЛА DESC

DROP TABLE #MYTABLE;