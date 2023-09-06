

---------1----------
SELECT * FROM DBA_TABLESPACE; 
---------2------------
SELECT * FROM dba_data_files

SELECT * FROM dba_TEMP_FILES

SELECT * FROM dba_UNDO_EXTENTS

---------3------------
SELECT * FROM V$LOG

---------4------------
SELECT * FROM V$LOGFILE
----------5------------
ALTER SYSTEM SWITCH LOGFILE
SELECT * FROM V$LOG
----------6------------
alter database add logfile group 4 'REDO04.log' size 50 m blocksize 512;
alter database add logfile member 'REDO041.LOG' reuse  to group 4;
alter database add logfile member  'REDO042.LOG'  reuse to group 4;

SELECT group#, thread#, sequence#, first_change#, next_change#
FROM v$log;
----------7------------
SELECT * FROM v$log WHERE GROUP# = 4;

ALTER DATABASE DROP LOGFILE GROUP 4;
ALTER SYSTEM SWITCH LOGFILE

ALTER DATABASE DROP LOGFILE MEMBER 'REDO04.LOG';
ALTER DATABASE DROP LOGFILE MEMBER 'REDO041.LOG';
ALTER DATABASE DROP LOGFILE MEMBER 'REDO042.LOG';
alter database drop logfile group 4 ;

----------8------------
SELECT log_mode FROM v$database;
-----------11---------------
ALTER SYSTEM SET LOG_ARCHIVE_DEST_1 ='LOCATION=/archive'

ALTER SYSTEM SWITCH LOGFILE;
SELECT NAME, FIRST_CHANGE#, NEXT_CHANGE# FROM V$ARCHIVED_LOG;
-------------12---------------------
--shutdown immediate;
--startup mount;
--alter database noarchivelog;
--select name, log_mode from v$database;
--alter database open;
---------------13------------------
select * from v$controlfile;
---------------14------------------
show parameter control;