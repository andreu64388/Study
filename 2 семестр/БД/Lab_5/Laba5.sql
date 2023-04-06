----------- Task 1 -----------
/*1. �������� ������ ���� ��������� �����������.*/
----------- Task 1 -----------
SELECT TABLESPACE_NAME FROM DBA_TABLESPACES;
----------- Task 2 -----------
/*2. �������� ��������� ������������ � ������ XXX_QDATA (10 m). 
��� �������� ���������� ��� � ��������� offline. ����� ���������� 
��������� ������������ � ��������� online. �������� ������������ XXX
����� 2 m � ������������ XXX_QDATA. �� ����� XXX � ������������ XXX_ QDATA 
�������� ������� XXX_T1 �� ���� ��������, ���� �� ������� ����� �������� 
��������� ������. � ������� �������� 3 ������.*/
----------- Task 2 -----------


CREATE TABLESPACE KAV1_QDATA
DATAFILE 'kav_qdata.dbf'
SIZE 10M
OFFLINE;

--������� ���������� ������������ XXX_QDATA � ��������� online:


--��������� ������������ XXX ����� 2 ��������� � ������������ XXX_QDATA:
--���� ���� (����� ���� �����, �-�� ���� ����� �����
alter session set "_ORACLE_SCRIPT"=true;
CREATE ROLE myrole;
GRANT CREATE SESSION,
      CREATE TABLE, 
      CREATE VIEW, 
      CREATE PROCEDURE,
      DROP ANY TABLE,
      DROP ANY VIEW,
      DROP ANY PROCEDURE TO myrole;    
COMMIT;
grant create session to myrole;

--���� �������
CREATE PROFILE myprofile LIMIT
    PASSWORD_LIFE_TIME 180      --���-�� ���� ����� ������
    SESSIONS_PER_USER 3         --���-�� ������ ��� �����
    FAILED_LOGIN_ATTEMPTS 7     --���-�� ������� �����
    PASSWORD_LOCK_TIME 1        --���-�� ���� ����� ����� ������
    PASSWORD_REUSE_TIME 10      --����� ���� ���� ����� ��������� ������
    PASSWORD_GRACE_TIME DEFAULT --���-�� ���� ����������.� ����� ������
    CONNECT_TIME 180            --����� ���� (���)
    IDLE_TIME 30 ;              --���-�� ��� ������� 
    
    
--���� �����
CREATE USER KAV IDENTIFIED BY 123
DEFAULT TABLESPACE KAV1_QDATA QUOTA UNLIMITED ON KAV1_QDATA
PROFILE MYPROFILE
ACCOUNT UNLOCK;

GRANT MYROLE TO KAV;

ALTER USER KAV QUOTA 2M ON KAV1_QDATA;

--�� ����� ����� KAV(123) � KAV_QDATA ���� ������� KAV_T1

CREATE TABLE KAV_T1(
ID NUMBER(15) PRIMARY KEY,
NAME VARCHAR2(10))
TABLESPACE KAV1_QDATA;

INSERT INTO KAV_T1 VALUES(1, 'TES');
INSERT INTO KAV_T1 VALUES(2, 'KAV');
INSERT INTO KAV_T1 VALUES(3, 'SRE');
COMMIT
----------- Task 3 -----------
/*3. �������� ������ ��������� ���������� ������������ XXX_QDATA. */
----------- Task 3 -----------
SELECT *
FROM DBA_SEGMENTS
WHERE TABLESPACE_NAME = 'KAV1_QDATA';
----------- Task 4 -----------
/*4. ���������� ������� ������� XXX_T1. */
----------- Task 4 -----------
SELECT segment_name, segment_type
FROM dba_segments
WHERE segment_name = 'KAV_T1';
----------- Task 5 -----------
/*5. ���������� ��������� ��������. */
----------- Task 5 -----------
SELECT segment_name, segment_type
FROM dba_segments
WHERE segment_name LIKE 'KAV_T1%';
----------- Task 6 -----------
/*6. ������� (DROP) ������� XXX_T1.  */
----------- Task 6 -----------
DROP TABLE KAV_T1;
COMMIT
----------- Task 7 -----------
/*7. �������� ������ ��������� ���������� 
������������ XXX_QDATA. ���������� ������� ������� XXX_T1.
��������� SELECT-������ � ������������� USER_RECYCLEBIN, 
�������� ���������.  */
----------- Task 7 -----------
--������ ���������
select SEGMENT_NAME from DBA_SEGMENTS where TABLESPACE_NAME='KAV1_QDATA'

-- ����������� �������� ������� XXX_T1 
SELECT segment_name, segment_type
FROM dba_segments
WHERE segment_name = 'KAV_T1';

SELECT *
FROM user_recyclebin;

----------- Task 8 -----------
/*8. ������������ (FLASHBACK) ��������� �������. */
----------- Task 8 -----------

FLASHBACK TABLE kav_t1 TO BEFORE DROP;

----------- Task 9 -----------
/*9. ��������� PL/SQL-������, ����������� 
������� XXX_T1 ������� (10000 �����).  */
----------- Task 9 -----------

BEGIN
  FOR k IN 4..10004
  LOOP
    insert into KAV_T1 values(k, 'A');
  END LOOP;
  COMMIT;
END;

----------- Task 10 -----------
/*10. ���������� ������� � �������� ������� XXX_T1
���������, �� ������ � ������ � ������.   */
----------- Task 10 -----------
SELECT EXTENT_ID, BLOCKS, BYTES FROM DBA_EXTENTS WHERE SEGMENT_NAME='KAV_T1';
----------- Task 11 -----------
/*11. �������� �������� ���� ��������� � ���� ������.    */
----------- Task 11 -----------
SELECT OWNER, SEGMENT_NAME, SEGMENT_TYPE, EXTENT_ID, FILE_ID, BLOCK_ID, BLOCKS
FROM DBA_EXTENTS;
----------- Task 13 -----------
/*13. ���������� �������� ������������� RowSCN � ������� XXX_T1 � ������ ��������.    */
----------- Task 13 -----------
CREATE OR REPLACE TRIGGER kav_t1_rowscn_trg
BEFORE INSERT OR UPDATE ON kav_t1
FOR EACH ROW
BEGIN
  :new.ROWSCN := DBMS_FLASHBACK.GET_SYSTEM_CHANGE_NUMBER;
END;
----------- Task 15 -----------
/*15. ������� ��������� ������������ XXX_QDATA � ��� ����.    */
----------- Task 15 -----------
DROP TABLE KAV_T1;

DROP TABLESPACE KAV1_QDATA INCLUDING CONTENTS AND DATAFILES;