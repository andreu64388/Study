create user lab_5 identified by Admin1234; --создаем пользователя lab_5 с паролем Admin1
alter session set "_oracle_script"=true
--далее выдаем права       
grant create session to lab_5; --создание сессии (чтобы могли приконнектиться к БД)
grant unlimited tablespace to lab_5; --создание таблиц с безлимитным табличных простанствах
grant create table to lab_5; --создание таблиц
grant create any index to lab_5; --создание индексов
grant create tablespace to lab_5; --создание табличных пространств
grant create any sequence to lab_5; --создание последовательностей
grant create user to lab_5; --создание новых пользователей
GRANT CREATE TRIGGER TO lab_5;
GRANT CREATE VIEW TO lab_5;
grant drop user to lab_5; --удаление существующих пользователей
grant insert any table to lab_5; --добавление данных в таблицы
grant update any table to lab_5; --изменения данных в таблицах
grant delete any table to lab_5; --удаление данных в таблицах
grant select on dba_source to lab_5; --просмотр словаря кода объектов 
grant select on dba_objects to lab_5; --просмотр словаря сущесвующих объектов в БД
grant select on dba_indexes to lab_5; --просмотр словаря существующих индексов БД