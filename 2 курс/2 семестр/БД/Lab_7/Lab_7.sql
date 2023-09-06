----------------- Task 1 -----------------
/*1 Определите общий размер области SGA.*/
----------------- Task 1 -----------------
select * from V$SGA;
select SUM(value) from v$sga;

----------------- Task 2 -----------------
/*2.Определите текущие размеры основных пулов SGA.*/
----------------- Task 2 -----------------
select * from v$sga_dynamic_components where current_size > 0;

----------------- Task 3 -----------------
/*3.Определите размеры гранулы для каждого пула.*/
----------------- Task 3 -----------------
select component, granule_size from v$sga_dynamic_components where current_size > 0;

----------------- Task 4 -----------------
/*4.Определите объем доступной свободной памяти в SGA.*/
----------------- Task 4 -----------------
select current_size from v$sga_dynamic_free_memory;

----------------- Task 5 -----------------
/*5. Определите максимальный и целевой размер области SGA.*/
----------------- Task 5 -----------------


----------------- Task 6 -----------------
/*6. Определите размеры пулов КЕЕP, DEFAULT и RECYCLE буферного кэша.*/
----------------- Task 6 -----------------
select component, current_size, min_size from v$sga_dynamic_components 
where component='KEEP buffer cache' or component='DEFAULT buffer cache' or component='RECYCLE buffer cache';

----------------- Task 7 -----------------
/*7. Создайте таблицу, которая будет помещаться в пул КЕЕP.
Продемонстрируйте сегмент таблицы.*/
----------------- Task 7 -----------------
CREATE TABLE MyTable (
   id NUMBER,
   name VARCHAR2(50)
) TABLESPACE users STORAGE (BUFFER_POOL KEEP);

SELECT segment_name, segment_type, tablespace_name, buffer_pool 
FROM user_segments 
WHERE segment_name = 'MYTABLE';


drop table MyTable;

----------------- Task 8 -----------------
/*8.Создайте таблицу, которая будет кэшироваться в пуле 
DEFAULT. Продемонстрируйте сегмент таблицы. */
----------------- Task 8 -----------------
CREATE TABLE my_cached_table (
  id NUMBER,
  name VARCHAR2(50),
  age NUMBER
) CACHE;

SELECT segment_name, segment_type, tablespace_name
FROM user_segments
WHERE segment_name = 'MY_CACHED_TABLE';


----------------- Task 9 -----------------
/*9.	Найдите размер буфера журналов повтора. */
----------------- Task 9 -----------------
show parameter log_buffer;

----------------- Task 10 -----------------
/*10.	Найдите размер свободной памяти в большом пуле. */
----------------- Task 10 -----------------
select sum(decode(name,'free memory',bytes)) 
from v$sgastat 
where pool = 'large pool';

----------------- Task 11 -----------------
/*11.Определите режимы текущих соединений с инстансом (dedicated, shared). */
----------------- Task 11 -----------------
select username, service_name, server, osuser, machine, program 
from v$session 
where username is not null;

----------------- Task 12 -----------------
/*12. Получите полный список работающих в настоящее время фоновых процессов. */
----------------- Task 12 -----------------
ALTER SESSION SET "_ORACLE_SCRIPT"=TRUE;

SELECT name, description FROM v$bgprocess;

----------------- Task 13 -----------------
/*13.	Получите список работающих в настоящее время серверных процессов. */
----------------- Task 13 -----------------
select * from v$bgprocess where paddr != '00';

----------------- Task 14 -----------------
/*14. Определите, сколько процессов DBWn работает в настоящий момент. */
----------------- Task 14 -----------------
select count(*) from v$bgprocess where paddr!= '00' and name like 'DBW%';

----------------- Task 15 -----------------
/*15.	Определите сервисы (точки подключения экземпляра). */
----------------- Task 15 -----------------
select * from v$services;


----------------- Task 16 -----------------
/*16 Получите известные вам параметры диспетчеров. */
----------------- Task 16 -----------------
select * from v$dispatcher;
show parameter dispatchers;

----------------- Task 17 -----------------
/*17.Укажите в списке Windows-сервисов сервис, реализующий процесс LISTENER.*/
----------------- Task 17 -----------------
select * from v$services;

----------------- Task 18 -----------------
/*18.	Продемонстрируйте и поясните содержимое файла LISTENER.ORA. */
----------------- Task 18 -----------------
