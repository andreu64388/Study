/*
3.	Разработать T-SQL-скрипт, ко-торый выводит на печать глобальные переменные: 
 @@ROWCOUNT (число обрабо-танных строк); 
 @@VERSION (версия SQL Server);
 @@SPID (возвращает системный идентификатор процесса, назначен-ный сервером текущему подключе-нию); 
 @@ERROR (код последней ошибки); 
 @@SERVERNAME (имя сервера); 
 @@TRANCOUNT (возвращает уровень вложенности транзакции); 
 @@FETCH_STATUS (проверка ре-зультата считывания строк результи-рующего набора); 
 @@NESTLEVEL (уровень вложен-ности текущей процедуры).
*/
PRINT 'ЧИСЛО ОБРАБОТАННЫХ СТРОК: ' + CAST(@@ROWCOUNT AS NVARCHAR);
PRINT 'ВЕРСИЯ SQL SERVER: ' + CAST(@@VERSION AS VARCHAR);
PRINT 'СИСТЕМНЫЙ ИДЕНТИФИКАТОР ПРОЦЕССА: ' + CAST(@@SPID AS NVARCHAR);
PRINT 'КОД ПОСЛЕДНЕЙ ОШИБКИ: ' + CAST(@@ERROR AS VARCHAR);
PRINT 'ИМЯ СЕРВЕРА: ' + CAST(@@SERVERNAME AS VARCHAR);
PRINT 'УРОВЕНЬ ВЛОЖЕННОСТИ ТРАНЗАКЦИИ: ' + CAST(@@TRANCOUNT AS NVARCHAR);
PRINT 'ПРОВЕРКА РЕЗУЛЬТАТА СЧИТЫВАНИЯ СТРОК РЕЗУЛЬТИРУЮЩЕГО НАБОРА: ' + CAST(@@FETCH_STATUS AS NVARCHAR);
PRINT 'УРОВЕНЬ ВЛОЖЕННОСТИ ТЕКУЩЕЙ ПРОЦЕДУРЫ: ' + CAST(@@NESTLEVEL AS NVARCHAR);