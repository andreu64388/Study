------------------- Task 1 -------------------
/*Получите список всех существующих PDB в рамках 
экземпляра ORA12W. Определите их текущее состояние.*/
------------------- Task 1 -------------------
SELECT CON_UID, NAME, OPEN_MODE FROM V$PDBS;
------------------- Task 2 -------------------
/*Выполните запрос к ORA12W, позволяющий получить
перечень экземпляров*/
------------------- Task 2 -------------------
SELECT INSTANCE_NUMBER, INSTANCE_NAME, HOST_NAME
FROM V$INSTANCE;
------------------- Task 3 -------------------
/*Выполните запрос к ORA12W, позволяющий получить перечень
установленных компонентов СУБД Oracle 12c и их версии и статус*/
------------------- Task 3 -------------------
SELECT COMP_ID, COMP_NAME, VERSION, STATUS
FROM DBA_REGISTRY;
------------------- Task 4 -------------------
/*Создайте собственный экземпляр PDB (необходимо подключиться
к серверу с серверного компьютера и используйте Database Configuration 
Assistant) с именем XXX_PDB, где XXX – инициалы студента*/
------------------- Task 4 -------------------
-- DATABASE CONFIGURATION ASSISTANT


ALTER PLUGGABLE DATABASE KAVPDB OPEN;
------------------- Task 5 -------------------
/*Получите список всех существующих PDB в рамках экземпляра
ORA12W. Убедитесь, что созданная PDB-база данных существует*/
------------------- Task 5 -------------------
SELECT NAME,OPEN_MODE,CON_ID,CREATION_TIME FROM V$PDBS;
------------------- Task 6 -------------------
/*Подключитесь к XXX_PDB c помощью SQL Developer создайте 
инфраструктурные объекты (табличные пространства, роль, профиль 
безопасности, пользователя с именем U1_XXX_PDB)*/
------------------- Task 6 -------------------
ALTER SESSION SET "_ORACLE_SCRIPT"=true
ALTER SESSION SET CONTAINER = kavpdb;


CREATE TABLESPACE KAV_PDB_SYS_TS
  DATAFILE 'KAV_PDB_SYS_TS3.DBF' 
  SIZE 10M
  AUTOEXTEND ON NEXT 5M
  MAXSIZE 50M;
  
DROP TABLESPACE KAV_PDB_SYS_TS_TEMP
CREATE TEMPORARY TABLESPACE KAV_PDB_SYS_TS_TEMP
  TEMPFILE 'PIA_PDB_SYS_TS_TEMP.DBF'
  SIZE 5M
  AUTOEXTEND ON NEXT 2M
  MAXSIZE 40M;

SELECT * FROM DBA_TABLESPACES WHERE TABLESPACE_NAME LIKE '%KAV%';

-- ROLE
CREATE ROLE KAV_PDB_SYS_RL;


GRANT CONNECT, CREATE SESSION, CREATE ANY TABLE, DROP ANY TABLE, CREATE ANY VIEW, 
DROP ANY VIEW, CREATE ANY PROCEDURE, DROP ANY PROCEDURE TO KAV_PDB_SYS_RL;

SELECT * FROM DBA_ROLES WHERE ROLE LIKE '%RL%';


-- PROFILE
CREATE PROFILE KAV_PDB_SYS_PROFILE LIMIT
  PASSWORD_LIFE_TIME 365
  SESSIONS_PER_USER 10
  FAILED_LOGIN_ATTEMPTS 5
  PASSWORD_LOCK_TIME 1
  PASSWORD_REUSE_TIME 10
  PASSWORD_GRACE_TIME DEFAULT;



-- USER
CREATE USER KAV_PDB_SYS_USER IDENTIFIED BY 123
  DEFAULT TABLESPACE KAV_PDB_SYS_TS  QUOTA UNLIMITED ON KAV_PDB_SYS_TS
  TEMPORARY TABLESPACE KAV_PDB_SYS_TS_TEMP
  PROFILE KAV_PDB_SYS_PROFILE;

GRANT CONNECT, CREATE SESSION, ALTER SESSION, CREATE ANY TABLE, DROP ANY TABLE, CREATE ANY VIEW, 
DROP ANY VIEW, CREATE ANY PROCEDURE, DROP ANY PROCEDURE TO KAV_PDB_SYS_USER; 
GRANT SYSDBA TO KAV_PDB_SYS_USER;

SELECT * FROM DBA_USERS WHERE USERNAME LIKE '%KAV%';
------------------- Task 7 -------------------
/*Подключитесь к пользователю U1_XXX_PDB, с помощью SQL Developer, 
создайте таблицу XXX_table, добавьте в нее строки, 
выполните SELECT-запрос к таблице.*/
------------------- Task 7 -------------------
-- Connections -> U1_KAV_PDB    
CREATE TABLE KAV_TABLES (I NUMBER);
INSERT INTO  KAV_TABLES VALUES (1);
SELECT * FROM  KAV_TABLES;
------------------- Task 8 -------------------
/*С помощью представлений словаря базы данных определите, все
табличные пространства, все  файлы (перманентные и временные),
все роли (и выданные им привилегии), профили безопасности, всех
пользователей  базы данных XXX_PDB и  назначенные им роли.*/
------------------- Task 8 -------------------
-- Connections -> PIA PDB SYS
SELECT * FROM DBA_TABLESPACES; 
SELECT * FROM DBA_ROLES;
SELECT * FROM DBA_PROFILES;  
SELECT * FROM ALL_USERS;

SELECT * FROM DBA_DATA_FILES;   
SELECT * FROM DBA_TEMP_FILES;  
SELECT GRANTEE, PRIVILEGE FROM DBA_SYS_PRIVS; 
------------------- Task 9 -------------------
/*Подключитесь  к CDB-базе данных, создайте общего пользователя с
именем C##XXX, назначьте ему привилегию, позволяющую подключится к базе
данных XXX_PDB. Создайте 2 подключения пользователя C##XXX в SQL Developer 
к CDB-базе данных и  XXX_PDB – базе данных. Проверьте их работоспособность.  */
------------------- Task 9 -------------------
-- Connections -> KAV

CREATE USER C##KAV IDENTIFIED BY 123


GRANT CREATE SESSION TO C##KAV;

------------------- Task 10 -------------------
/*10. Назначьте привилегию, разрешающему подключение к XXX_PDB общему пользователю
C##YYY, созданному другим студентом. Убедитесь в работоспособности  этого пользователя в базе данных XXX_PDB.  */
------------------- Task 10 -------------------


------------------- Task 11 -------------------
/*Подключитесь к пользователю U1_XXX_PDB со своего компьютера, а к пользователям 
C##XXX и C##YYY с другого (к XXX_PDB-базе данных). На своем компьютере получите
список всех текущих подключений к XXX_PDB (найдите в списке созданные вами подключения).
На своем компьютере получите список всех текущих подключений к СDB (найдите в списке
созданные вами подключений).  */
------------------- Task 11 -------------------
-- Connections -> KAV PDB

SELECT * FROM V$SESSION WHERE USERNAME IS NOT NULL;
------------------- Task 12 -------------------
/*Продемонстрируйте преподавателю, работоспособную PDB-базу данных и 
созданную инфраструктуру (результаты всех запросов). Покажите файлы
PDB-базы данных (на серверном компьютере).  */
------------------- Task 12 -------------------
SELECT * FROM DBA_DATA_FILES;
------------------- Task 13 -------------------
/*Удалите созданную базу данных XXX_DB. Убедитесь
, что все файлы PDB-базы данных удалены. Удалите
пользователя C##XXX. Удалите в SQL Developer все подключения к XXX_PDB */
------------------- Task 13 -------------------
-- Connections -> KVS PDB SYS

ALTER PLUGGABLE DATABASE KAVPDB CLOSE IMMEDIATE;
DROP PLUGGABLE DATABASE KAVPDB;

-- drop all
DROP USER C##KAV CASCADE;
-----------------------------------------------