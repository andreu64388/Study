----------------- Task 1 -----------------
/*1 ���������� ����� ������ ������� SGA.*/
----------------- Task 1 -----------------
select * from V$SGA;
select SUM(value) from v$sga;

----------------- Task 2 -----------------
/*2.���������� ������� ������� �������� ����� SGA.*/
----------------- Task 2 -----------------
select * from v$sga_dynamic_components where current_size > 0;

----------------- Task 3 -----------------
/*3.���������� ������� ������� ��� ������� ����.*/
----------------- Task 3 -----------------
select component, granule_size from v$sga_dynamic_components where current_size > 0;

----------------- Task 4 -----------------
/*4.���������� ����� ��������� ��������� ������ � SGA.*/
----------------- Task 4 -----------------
select current_size from v$sga_dynamic_free_memory;

----------------- Task 5 -----------------
/*5. ���������� ������������ � ������� ������ ������� SGA.*/
----------------- Task 5 -----------------


----------------- Task 6 -----------------
/*6. ���������� ������� ����� ���P, DEFAULT � RECYCLE ��������� ����.*/
----------------- Task 6 -----------------
select component, current_size, min_size from v$sga_dynamic_components 
where component='KEEP buffer cache' or component='DEFAULT buffer cache' or component='RECYCLE buffer cache';

----------------- Task 7 -----------------
/*7. �������� �������, ������� ����� ���������� � ��� ���P.
����������������� ������� �������.*/
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
/*8.�������� �������, ������� ����� ������������ � ���� 
DEFAULT. ����������������� ������� �������. */
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
/*9.	������� ������ ������ �������� �������. */
----------------- Task 9 -----------------
show parameter log_buffer;

----------------- Task 10 -----------------
/*10.	������� ������ ��������� ������ � ������� ����. */
----------------- Task 10 -----------------
select sum(decode(name,'free memory',bytes)) 
from v$sgastat 
where pool = 'large pool';

----------------- Task 11 -----------------
/*11.���������� ������ ������� ���������� � ��������� (dedicated, shared). */
----------------- Task 11 -----------------
select username, service_name, server, osuser, machine, program 
from v$session 
where username is not null;

----------------- Task 12 -----------------
/*12. �������� ������ ������ ���������� � ��������� ����� ������� ���������. */
----------------- Task 12 -----------------
ALTER SESSION SET "_ORACLE_SCRIPT"=TRUE;

SELECT name, description FROM v$bgprocess;

----------------- Task 13 -----------------
/*13.	�������� ������ ���������� � ��������� ����� ��������� ���������. */
----------------- Task 13 -----------------
select * from v$bgprocess where paddr != '00';

----------------- Task 14 -----------------
/*14. ����������, ������� ��������� DBWn �������� � ��������� ������. */
----------------- Task 14 -----------------
select count(*) from v$bgprocess where paddr!= '00' and name like 'DBW%';

----------------- Task 15 -----------------
/*15.	���������� ������� (����� ����������� ����������). */
----------------- Task 15 -----------------
select * from v$services;


----------------- Task 16 -----------------
/*16 �������� ��������� ��� ��������� �����������. */
----------------- Task 16 -----------------
select * from v$dispatcher;
show parameter dispatchers;

----------------- Task 17 -----------------
/*17.������� � ������ Windows-�������� ������, ����������� ������� LISTENER.*/
----------------- Task 17 -----------------
select * from v$services;

----------------- Task 18 -----------------
/*18.	����������������� � �������� ���������� ����� LISTENER.ORA. */
----------------- Task 18 -----------------
