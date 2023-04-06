------------------- Task 1 -------------------
/*�������� ������ ���� ������������ PDB � ������ 
���������� ORA12W. ���������� �� ������� ���������.*/
------------------- Task 1 -------------------
SELECT CON_UID, NAME, OPEN_MODE FROM V$PDBS;
------------------- Task 2 -------------------
/*��������� ������ � ORA12W, ����������� ��������
�������� �����������*/
------------------- Task 2 -------------------
SELECT INSTANCE_NUMBER, INSTANCE_NAME, HOST_NAME
FROM V$INSTANCE;
------------------- Task 3 -------------------
/*��������� ������ � ORA12W, ����������� �������� ��������
������������� ����������� ���� Oracle 12c � �� ������ � ������*/
------------------- Task 3 -------------------
SELECT COMP_ID, COMP_NAME, VERSION, STATUS
FROM DBA_REGISTRY;
------------------- Task 4 -------------------
/*�������� ����������� ��������� PDB (���������� ������������
� ������� � ���������� ���������� � ����������� Database Configuration 
Assistant) � ������ XXX_PDB, ��� XXX � �������� ��������*/
------------------- Task 4 -------------------
-- DATABASE CONFIGURATION ASSISTANT


ALTER PLUGGABLE DATABASE KAVPDB OPEN;
------------------- Task 5 -------------------
/*�������� ������ ���� ������������ PDB � ������ ����������
ORA12W. ���������, ��� ��������� PDB-���� ������ ����������*/
------------------- Task 5 -------------------
SELECT NAME,OPEN_MODE,CON_ID,CREATION_TIME FROM V$PDBS;
------------------- Task 6 -------------------
/*������������ � XXX_PDB c ������� SQL Developer �������� 
���������������� ������� (��������� ������������, ����, ������� 
������������, ������������ � ������ U1_XXX_PDB)*/
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
/*������������ � ������������ U1_XXX_PDB, � ������� SQL Developer, 
�������� ������� XXX_table, �������� � ��� ������, 
��������� SELECT-������ � �������.*/
------------------- Task 7 -------------------
-- Connections -> U1_KAV_PDB    
CREATE TABLE KAV_TABLES (I NUMBER);
INSERT INTO  KAV_TABLES VALUES (1);
SELECT * FROM  KAV_TABLES;
------------------- Task 8 -------------------
/*� ������� ������������� ������� ���� ������ ����������, ���
��������� ������������, ���  ����� (������������ � ���������),
��� ���� (� �������� �� ����������), ������� ������������, ����
�������������  ���� ������ XXX_PDB �  ����������� �� ����.*/
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
/*������������  � CDB-���� ������, �������� ������ ������������ �
������ C##XXX, ��������� ��� ����������, ����������� ����������� � ����
������ XXX_PDB. �������� 2 ����������� ������������ C##XXX � SQL Developer 
� CDB-���� ������ �  XXX_PDB � ���� ������. ��������� �� �����������������.  */
------------------- Task 9 -------------------
-- Connections -> KAV

CREATE USER C##KAV IDENTIFIED BY 123


GRANT CREATE SESSION TO C##KAV;

------------------- Task 10 -------------------
/*10. ��������� ����������, ������������ ����������� � XXX_PDB ������ ������������
C##YYY, ���������� ������ ���������. ��������� � �����������������  ����� ������������ � ���� ������ XXX_PDB.  */
------------------- Task 10 -------------------


------------------- Task 11 -------------------
/*������������ � ������������ U1_XXX_PDB �� ������ ����������, � � ������������� 
C##XXX � C##YYY � ������� (� XXX_PDB-���� ������). �� ����� ���������� ��������
������ ���� ������� ����������� � XXX_PDB (������� � ������ ��������� ���� �����������).
�� ����� ���������� �������� ������ ���� ������� ����������� � �DB (������� � ������
��������� ���� �����������).  */
------------------- Task 11 -------------------
-- Connections -> KAV PDB

SELECT * FROM V$SESSION WHERE USERNAME IS NOT NULL;
------------------- Task 12 -------------------
/*����������������� �������������, ��������������� PDB-���� ������ � 
��������� �������������� (���������� ���� ��������). �������� �����
PDB-���� ������ (�� ��������� ����������).  */
------------------- Task 12 -------------------
SELECT * FROM DBA_DATA_FILES;
------------------- Task 13 -------------------
/*������� ��������� ���� ������ XXX_DB. ���������
, ��� ��� ����� PDB-���� ������ �������. �������
������������ C##XXX. ������� � SQL Developer ��� ����������� � XXX_PDB */
------------------- Task 13 -------------------
-- Connections -> KVS PDB SYS

ALTER PLUGGABLE DATABASE KAVPDB CLOSE IMMEDIATE;
DROP PLUGGABLE DATABASE KAVPDB;

-- drop all
DROP USER C##KAV CASCADE;
-----------------------------------------------