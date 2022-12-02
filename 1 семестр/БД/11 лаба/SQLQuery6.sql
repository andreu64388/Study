/*6. Разработать два сценария A и B на примере базы данных X_UNIVER. 
Сценарий A представляет собой явную транзакцию с уровнем изолированности REPEATABLE READ. 
Сценарий B – явную транзакцию с уровнем изолированности READ COMMITED. 
Сценарий A должен демонстрировать, что уровень REAPETABLE READ не допускает неподтвержденного
чтения и неповторяющегося чтения, но при этом возможно фантомное чтение. 
*/
USE UNIVER;
--------A---------
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ
BEGIN TRANSACTION
SELECT PULPIT FROM PULPIT WHERE FACULTY = 'ТЛ';
--------T1---------
--------T2---------
SELECT CASE
WHEN PULPIT = 'ТЛ' THEN 'INSERT'  
ELSE ' ' 
END,
PULPIT FROM PULPIT WHERE FACULTY = 'ТЛ'
COMMIT


--- B ---	
BEGIN TRANSACTION 	  
--------T1---------
UPDATE PULPIT SET FACULTY = 'ИТ' WHERE PULPIT = 'ТЛ';
COMMIT
--------T2---------

