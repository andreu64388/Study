------------------- Task 1 -------------------
/*Создайте табличное пространство для постоянных
данных со следующими параметрами:
- имя: TS_XXX;
- имя файла: TS_XXX; 
- начальный размер: 7М;
- автоматическое приращение: 5М;
- максимальный размер: 20М. 
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
/*Создайте табличное пространство для временных 
данных со следующими параметрами:
?	имя: TS_XXX_TEMP;
?	имя файла: TS_XXX_TEMP; 
?	начальный размер: 5М;
?	автоматическое приращение: 3М;
?	максимальный размер: 30М. 
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
/*Получите список всех табличных пространств, 
списки всех файлов с помощью select-запроса к словарю.*/
------------------- Task 3 -------------------
SELECT TABLESPACE_NAME FROM SYS.DBA_TABLESPACES; 
SELECT FILE_NAME, TABLESPACE_NAME FROM DBA_DATA_FILES;     
------------------- Task 4 -------------------
/*Создайте роль с именем RL_XXXCORE. Назначьте ей следующие системные привилегии:
?	разрешение на соединение с сервером;
?	разрешение создавать и удалять таблицы, представления, процедуры и функции.*/
------------------- Task 4 -------------------
--разрешение на соединение с сервером;
ALTER SESSION SET "_ORACLE_SCRIPT" = TRUE;
-----------------------------------------
CREATE ROLE RL_KAVCORE;

GRANT CONNECT,CREATE SESSION, CREATE ANY TABLE,
DROP ANY TABLE, CREATE ANY VIEW,
DROP ANY VIEW, CREATE ANY PROCEDURE,
DROP ANY PROCEDURE TO RL_KAVCORE
-- drop role  RL_KAVCORE;
------------------- Task 5 -------------------
/*Найдите с помощью select-запроса роль в словаре. Найдите
с помощью select-запроса все системные привилегии, назначенные роли. */
------------------- Task 5 -------------------
SELECT * FROM DBA_ROLES WHERE ROLE LIKE '%RL%';
SELECT * FROM DBA_SYS_PRIVS WHERE GRANTEE = 'RL_KAVCORE';
------------------- Task 6 -------------------
/*Создайте профиль безопасности с именем PF_XXXCORE,
имеющий опции, аналогичные примеру из лекции. */
------------------- Task 6 -------------------
CREATE PROFILE PF_KAVCORE LIMIT
PASSWORD_LIFE_TIME 180 -- количество дней жизни пароля
SESSIONS_PER_USER 3 -- количество сессий пользователя
FAILED_LOGIN_ATTEMPTS 7 -- количество попыток входа
PASSWORD_LOCK_TIME 1 -- количество дней блокирования после ошибок
PASSWORD_REUSE_TIME 10  -- количество дней предупреждений о смене пароля
CONNECT_TIME 180 -- время соединения, минуты
IDLE_TIME 30 -- количество минут простоя
------------------- Task 7 -------------------
/*Получите список всех профилей БД. Получите значения всех параметров
профиля PF_XXXCORE. Получите значения всех параметров профиля DEFAULT. */
------------------- Task 7 -------------------
SELECT * FROM DBA_PROFILES;
SELECT * FROM DBA_PROFILES  WHERE PROFILE='PF_KAVCORE';
SELECT * FROM DBA_PROFILES  WHERE PROFILE='DEFAULT';
------------------- Task 8 -------------------
/*. Создайте пользователя с именем XXXCORE со следующими параметрами:
- табличное пространство по умолчанию: TS_XXX;
- табличное пространство для временных данных: TS_XXX_TEMP;
- профиль безопасности PF_XXXCORE;
- учетная запись разблокирована;
- срок действия пароля истек.  */
------------------- Task 8 ------------------
CREATE USER KAVCORE IDENTIFIED BY 12345
DEFAULT TABLESPACE TS_KAV QUOTA UNLIMITED ON TS_KAV
TEMPORARY TABLESPACE TS_KAV_TEMP
PROFILE PF_KAVCORE
ACCOUNT UNLOCK
PASSWORD EXPIRE
------------------- Task 9 -------------------
--Соединитесь с сервером Oracle с помощью sqlplus 
--и введите новый пароль для пользователя XXXCORE
------------------- Task 9 ------------------
--DONE
------------------- Task 10 -------------------
/*Создайте соединение с помощью SQL Developer для 
пользователя XXXCORE. Создайте любую таблицу и любое представление.*/
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
/*Создайте табличное пространство с именем XXX_QDATA (10m).
При создании установите его в состояние offline. Затем переведите табличное
пространство в состояние online. Выделите пользователю XXX квоту 2m в 
пространстве XXX_QDATA. От имени пользователя XXX создайте таблицу в 
пространстве XXX_T1. В таблицу добавьте 3 строки.*/
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