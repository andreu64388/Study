----------- Task 1 -----------
/*1. Получите список всех табличных пространств.*/
----------- Task 1 -----------
SELECT TABLESPACE_NAME FROM DBA_TABLESPACES;
----------- Task 2 -----------
/*2. Создайте табличное пространство с именем XXX_QDATA (10 m). 
При создании установите его в состояние offline. Затем переведите 
табличное пространство в состояние online. Выделите пользователю XXX
квоту 2 m в пространстве XXX_QDATA. От имени XXX в пространстве XXX_ QDATA 
создайте таблицу XXX_T1 из двух столбцов, один из которых будет являться 
первичным ключом. В таблицу добавьте 3 строки.*/
----------- Task 2 -----------


CREATE TABLESPACE KAV1_QDATA
DATAFILE 'kav_qdata.dbf'
SIZE 10M
OFFLINE;

--Перевод табличного пространства XXX_QDATA в состояние online:


--Выделение пользователю XXX квоты 2 мегабайта в пространстве XXX_QDATA:
--созд роль (чтобы дать юзеру, к-му надо выдел квоту
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

--созд профиль
CREATE PROFILE myprofile LIMIT
    PASSWORD_LIFE_TIME 180      --кол-во дней жизни пароля
    SESSIONS_PER_USER 3         --кол-во сессий для юзера
    FAILED_LOGIN_ATTEMPTS 7     --кол-во попыток ввода
    PASSWORD_LOCK_TIME 1        --кол-во дней блока после ошибок
    PASSWORD_REUSE_TIME 10      --через скок дней можно повторить пароль
    PASSWORD_GRACE_TIME DEFAULT --кол-во дней предупрежд.о смене пароля
    CONNECT_TIME 180            --время соед (мин)
    IDLE_TIME 30 ;              --кол-во мин простоя 
    
    
--созд юзера
CREATE USER KAV IDENTIFIED BY 123
DEFAULT TABLESPACE KAV1_QDATA QUOTA UNLIMITED ON KAV1_QDATA
PROFILE MYPROFILE
ACCOUNT UNLOCK;

GRANT MYROLE TO KAV;

ALTER USER KAV QUOTA 2M ON KAV1_QDATA;

--от имени юзера KAV(123) в KAV_QDATA созд таблицу KAV_T1

CREATE TABLE KAV_T1(
ID NUMBER(15) PRIMARY KEY,
NAME VARCHAR2(10))
TABLESPACE KAV1_QDATA;

INSERT INTO KAV_T1 VALUES(1, 'TES');
INSERT INTO KAV_T1 VALUES(2, 'KAV');
INSERT INTO KAV_T1 VALUES(3, 'SRE');
COMMIT
----------- Task 3 -----------
/*3. Получите список сегментов табличного пространства XXX_QDATA. */
----------- Task 3 -----------
SELECT *
FROM DBA_SEGMENTS
WHERE TABLESPACE_NAME = 'KAV1_QDATA';
----------- Task 4 -----------
/*4. Определите сегмент таблицы XXX_T1. */
----------- Task 4 -----------
SELECT segment_name, segment_type
FROM dba_segments
WHERE segment_name = 'KAV_T1';
----------- Task 5 -----------
/*5. Определите остальные сегменты. */
----------- Task 5 -----------
SELECT segment_name, segment_type
FROM dba_segments
WHERE segment_name LIKE 'KAV_T1%';
----------- Task 6 -----------
/*6. Удалите (DROP) таблицу XXX_T1.  */
----------- Task 6 -----------
DROP TABLE KAV_T1;
COMMIT
----------- Task 7 -----------
/*7. Получите список сегментов табличного 
пространства XXX_QDATA. Определите сегмент таблицы XXX_T1.
Выполните SELECT-запрос к представлению USER_RECYCLEBIN, 
поясните результат.  */
----------- Task 7 -----------
--список сегментов
select SEGMENT_NAME from DBA_SEGMENTS where TABLESPACE_NAME='KAV1_QDATA'

-- определения сегмента таблицы XXX_T1 
SELECT segment_name, segment_type
FROM dba_segments
WHERE segment_name = 'KAV_T1';

SELECT *
FROM user_recyclebin;

----------- Task 8 -----------
/*8. Восстановите (FLASHBACK) удаленную таблицу. */
----------- Task 8 -----------

FLASHBACK TABLE kav_t1 TO BEFORE DROP;

----------- Task 9 -----------
/*9. Выполните PL/SQL-скрипт, заполняющий 
таблицу XXX_T1 данными (10000 строк).  */
----------- Task 9 -----------

BEGIN
  FOR k IN 4..10004
  LOOP
    insert into KAV_T1 values(k, 'A');
  END LOOP;
  COMMIT;
END;

----------- Task 10 -----------
/*10. Определите сколько в сегменте таблицы XXX_T1
экстентов, их размер в блоках и байтах.   */
----------- Task 10 -----------
SELECT EXTENT_ID, BLOCKS, BYTES FROM DBA_EXTENTS WHERE SEGMENT_NAME='KAV_T1';
----------- Task 11 -----------
/*11. Получите перечень всех экстентов в базе данных.    */
----------- Task 11 -----------
SELECT OWNER, SEGMENT_NAME, SEGMENT_TYPE, EXTENT_ID, FILE_ID, BLOCK_ID, BLOCKS
FROM DBA_EXTENTS;
----------- Task 13 -----------
/*13. Исследуйте значения псевдостолбца RowSCN в таблице XXX_T1 и других таблицах.    */
----------- Task 13 -----------
CREATE OR REPLACE TRIGGER kav_t1_rowscn_trg
BEFORE INSERT OR UPDATE ON kav_t1
FOR EACH ROW
BEGIN
  :new.ROWSCN := DBMS_FLASHBACK.GET_SYSTEM_CHANGE_NUMBER;
END;
----------- Task 15 -----------
/*15. Удалите табличное пространство XXX_QDATA и его файл.    */
----------- Task 15 -----------
DROP TABLE KAV_T1;

DROP TABLESPACE KAV1_QDATA INCLUDING CONTENTS AND DATAFILES;