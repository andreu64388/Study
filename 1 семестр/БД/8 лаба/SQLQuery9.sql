/*
9. Разработать сценарий с ошибками, в котором используются для обработки ошибок блоки TRY и CATCH. 
Приме-нить функции ERROR_NUMBER (код последней ошибки), ERROR_ES-SAGE (сообщение об ошибке), ERROR_LINE 
(код последней ошибки), ER-ROR_PROCEDURE (имя процедуры или NULL), ERROR_SEVERITY
(уровень серьезности ошибки), ERROR_ STATE (метка ошибки). Проанализировать ре-зультат.*/
begin try
update PROGRESS set NOTE = 'Строка вместо int!!!' where NOTE = 9
end try
begin catch
print ERROR_NUMBER() -- код последней ошибки
print ERROR_MESSAGE() -- сообщение об ошибке
print ERROR_LINE() -- код последней ошибки
print ERROR_PROCEDURE() -- имя процедуры или NULL
print ERROR_SEVERITY() -- уровень серьезности ошибки
print ERROR_STATE() --
end catch