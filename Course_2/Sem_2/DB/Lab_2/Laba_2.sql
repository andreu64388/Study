  ------------------- Task 1 -------------------
/*�������� ��������� ������������ ��� ����������
������ �� ���������� �����������:
- ���: TS_XXX;
- ��� �����: TS_XXX; 
- ��������� ������: 7�;
- �������������� ����������: 5�;
- ������������ ������: 20�. 
*/
------------------- Task 1 -------------------
CREATE TABLESPACE TS_KAV
DATAFILE 'TS_KAV.DFA'
SIZE 7M
AUTOEXTEND ON NEXT 5M
MAXSIZE 20M
EXTENT MANAGEMENT LOCAL;

-- DROP TABLESPACE TS_KVS;
------------------- Task 2 -------------------
/*�������� ��������� ������������ ��� ��������� 
������ �� ���������� �����������:
?	���: TS_XXX_TEMP;
?	��� �����: TS_XXX_TEMP; 
?	��������� ������: 5�;
?	�������������� ����������: 3�;
?	������������ ������: 30�. 
*/
------------------- Task 2 -------------------
CREATE TEMPORARY TABLESPACE TS_KAV_TEMP
TEMPFILE 'TS_KAV_TEMP.DFA'
SIZE 5M
AUTOEXTEND ON NEXT 3M
MAXSIZE 30M
EXTENT MANAGEMENT LOCAL;

-- DROP TABLESPACE ts_kav_temp;
------------------- Task 3 -------------------
/*�������� ������ ���� ��������� �����������, 
������ ���� ������ � ������� select-������� � �������.*/
------------------- Task 3 -------------------
SELECT TABLESPACE_NAME FROM SYS.DBA_TABLESPACES; 
SELECT FILE_NAME, TABLESPACE_NAME FROM DBA_DATA_FILES;     
------------------- Task 4 -------------------
/*�������� ���� � ������ RL_XXXCORE. ��������� �� ��������� ��������� ����������:
?	���������� �� ���������� � ��������;
?	���������� ��������� � ������� �������, �������������, ��������� � �������.*/
------------------- Task 4 -------------------
--���������� �� ���������� � ��������;
ALTER SESSION SET "_ORACLE_SCRIPT" = TRUE;
-----------------------------------------
CREATE ROLE RL_KAVCORE;

GRANT CONNECT,CREATE SESSION, CREATE ANY TABLE,
DROP ANY TABLE, CREATE ANY VIEW,
DROP ANY VIEW, CREATE ANY PROCEDURE,
DROP ANY PROCEDURE TO RL_KAVCORE
-- drop role  RL_KAVCORE;
------------------- Task 5 -------------------
/*������� � ������� select-������� ���� � �������. �������
� ������� select-������� ��� ��������� ����������, ����������� ����. */
------------------- Task 5 -------------------
SELECT * FROM DBA_ROLES WHERE ROLE LIKE '%RL%';
SELECT * FROM DBA_SYS_PRIVS WHERE GRANTEE = 'RL_KAVCORE';
------------------- Task 6 -------------------
/*�������� ������� ������������ � ������ PF_XXXCORE,
������� �����, ����������� ������� �� ������. */
------------------- Task 6 -------------------
CREATE PROFILE PF_KAVCORE LIMIT
PASSWORD_LIFE_TIME 180 -- ���������� ���� ����� ������
SESSIONS_PER_USER 3 -- ���������� ������ ������������
FAILED_LOGIN_ATTEMPTS 7 -- ���������� ������� �����
PASSWORD_LOCK_TIME 1 -- ���������� ���� ������������ ����� ������
PASSWORD_REUSE_TIME 10  -- ���������� ���� �������������� � ����� ������
CONNECT_TIME 180 -- ����� ����������, ������
IDLE_TIME 30 -- ���������� ����� �������
------------------- Task 7 -------------------
/*�������� ������ ���� �������� ��. �������� �������� ���� ����������
������� PF_XXXCORE. �������� �������� ���� ���������� ������� DEFAULT. */
------------------- Task 7 -------------------
SELECT * FROM DBA_PROFILES;
SELECT * FROM DBA_PROFILES  WHERE PROFILE='PF_KAVCORE';
SELECT * FROM DBA_PROFILES  WHERE PROFILE='DEFAULT';
------------------- Task 8 -------------------
/*. �������� ������������ � ������ XXXCORE �� ���������� �����������:
- ��������� ������������ �� ���������: TS_XXX;
- ��������� ������������ ��� ��������� ������: TS_XXX_TEMP;
- ������� ������������ PF_XXXCORE;
- ������� ������ ��������������;
- ���� �������� ������ �����.  */
------------------- Task 8 ------------------
CREATE USER KAVCORE IDENTIFIED BY 12345
DEFAULT TABLESPACE TS_KAV QUOTA UNLIMITED ON TS_KAV
TEMPORARY TABLESPACE TS_KAV_TEMP
PROFILE PF_KAVCORE
ACCOUNT UNLOCK
PASSWORD EXPIRE
------------------- Task 9 -------------------
--����������� � �������� Oracle � ������� sqlplus 
--� ������� ����� ������ ��� ������������ XXXCORE
------------------- Task 9 ------------------
--DONE
------------------- Task 10 -------------------
/*�������� ���������� � ������� SQL Developer ��� 
������������ XXXCORE. �������� ����� ������� � ����� �������������.*/
------------------- Task 10 ------------------
CREATE TABLE TEST_ (
    FIRSTNAME VARCHAR2(20),
    AGE NUMBER(2)
);

INSERT  INTO TEST_ (FIRSTNAME, AGE) VALUES ('YOURI', 22);
-- DROP TABLE TEST_;
CREATE VIEW VIEW_TEST_ (FIRSTNAME, AGE) AS SELECT * FROM TEST_;
-- DROP VIEW VIEW_TEST_;
------------------- Task 11 -------------------
/*�������� ��������� ������������ � ������ XXX_QDATA (10m).
��� �������� ���������� ��� � ��������� offline. ����� ���������� ���������
������������ � ��������� online. �������� ������������ XXX ����� 2m � 
������������ XXX_QDATA. �� ����� ������������ XXX �������� ������� � 
������������ XXX_T1. � ������� �������� 3 ������.*/
------------------- Task 11 ------------------
CREATE TABLESPACE KAV_QDATA
DATAFILE 'KAV_QDATA.DFA'
SIZE 10M
OFFLINE;

SELECT TABLESPACE_NAME, STATUS, CONTENTS FROM SYS.DBA_TABLESPACES;
ALTER TABLESPACE KAV_QDATA ONLINE;

ALTER USER KAVCORE QUOTA 2M ON KAV_QDATA;

CREATE TABLE KAV_TABLE
(
  TITLE VARCHAR(50),
  DESCRIPTIONS VARCHAR(50), 
  AGE NUMBER
) TABLESPACE KAV_QDATA;

INSERT INTO  KAV_TABLE VALUES ('TEST1', 'TEST1', 1);
INSERT INTO  KAV_TABLE VALUES ('TEST2', 'TEST2', 2);
INSERT INTO  KAV_TABLE VALUES ('TEST3', 'TEST3', 3);

SELECT * FROM KAV_TABLE;
-----------------------------------------------