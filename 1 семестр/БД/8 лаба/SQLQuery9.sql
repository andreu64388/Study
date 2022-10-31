/*
9. Разработать сценарий с ошибками, в котором используются для обработки ошибок блоки TRY и CATCH. 
Приме-нить функции ERROR_NUMBER (код последней ошибки), ERROR_ES-SAGE (сообщение об ошибке), ERROR_LINE 
(код последней ошибки), ER-ROR_PROCEDURE (имя процедуры или NULL), ERROR_SEVERITY
(уровень серьезности ошибки), ERROR_ STATE (метка ошибки). Проанализировать ре-зультат.*/
USE UNIVER;
BEGIN TRY
UPDATE PROGRESS SET NOTE = 'СТРОКА ВМЕСТО INT!!!' WHERE NOTE = 9
END TRY
BEGIN CATCH
PRINT ERROR_NUMBER() -- КОД ПОСЛЕДНЕЙ ОШИБКИ
PRINT ERROR_MESSAGE() -- СООБЩЕНИЕ ОБ ОШИБКЕ
PRINT ERROR_LINE() -- КОД ПОСЛЕДНЕЙ ОШИБКИ
PRINT ERROR_PROCEDURE() -- ИМЯ ПРОЦЕДУРЫ ИЛИ NULL
PRINT ERROR_SEVERITY() -- УРОВЕНЬ СЕРЬЕЗНОСТИ ОШИБКИ
PRINT ERROR_STATE() --
END CATCH