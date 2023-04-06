/*7. Создать временную локальную таблицу из трех столбцов и 10 строк, заполнить ее и вывести содержимое. 
Использовать оператор WHILE.*/
CREATE TABLE #TASK(
	ID INT,
	NAME VARCHAR(20),
	MESSAGE VARCHAR(10)
	)
GO

DECLARE @INDEX INT = 0
WHILE @INDEX < 10
BEGIN
INSERT #TASK VALUES (@INDEX, 'NAME ' + CAST(@INDEX AS VARCHAR), 'MESSAGE ' + CAST(@INDEX AS VARCHAR))
SET @INDEX += 1
END

SELECT * FROM #TASK



