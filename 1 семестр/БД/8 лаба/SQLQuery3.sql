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
print 'Число обработанных строк: ' + cast(@@ROWCOUNT as nvarchar);
print 'Версия SQL Server: ' + cast(@@VERSION as varchar);
print 'Системный идентификатор процесса: ' + cast(@@SPID as nvarchar);
print 'Код последней ошибки: ' + cast(@@ERROR as varchar);
print 'Имя сервера: ' + cast(@@SERVERNAME as varchar);
print 'Уровень вложенности транзакции: ' + cast(@@TRANCOUNT as nvarchar);
print 'Проверка результата считывания строк результирующего набора: ' + cast(@@FETCH_STATUS as nvarchar);
print 'Уровень вложенности текущей процедуры: ' + cast(@@NESTLEVEL as nvarchar);